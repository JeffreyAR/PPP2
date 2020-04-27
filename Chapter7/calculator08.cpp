
/*
  I do not claim to be the author of this program.

	This program implements a basic expression calculator.
	Input from cin; output to cout.

	The grammar for input is:
	Statement:
		Expression
		Print
		Statement Print
		Statement Print Expression
		Declaration
		Quit

	Print:
		;

	Quit:
		quit

	Let:
		#

	Constant:
		const

	Expression:
		Term
		Expression + Term
		Expression – Term

	Term:
		Primary
		Term * Primary
		Term / Primary
		Term % Primary

	Primary:
		Number
		Assignment
		( Expression )
		– Primary
		+ Primary

	Number:
		floating-point-literal

	Assignment:
		Variable = Number

	Declaration:
		Let Variable = Number
		Constant Variable = Number

	Variable:
		variable

	Input comes from cin through the Token_stream called ts.
	Variables are stored in a Symbol_table called st.
	Once declared, variables cannot be declared again.

	Possible improvements:
		Add trig functions - implemented
		Add ability to enter functions
		Add calc functions (derivative or integral, former much easier but still non-trivial)
		Fix "> =" when multiple statements are executed.
*/

#include <cmath>
#include "../std_lib_facilities.h"

//Create Token type. Initializer for just a kind, a kind with a value, and a
//kind with a name.
struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
  Token(char ch, string s) :kind(ch), name(s) { }
};

//Create Token stream.
class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { } //Initalize empty stream

	Token get(); //Get next token
	void unget(Token t) { buffer=t; full=true; } //Store token t

	void ignore(char); //Skip to the next statement
};

//Declare constants
const char let = 'L';
const char constant = 'C';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char root = 'r';
const char power = 'p';
const char help = 'h';
const char sinChar = 's';
const char cosChar = 'c';
const char tanChar = 't';
const string squareRoot = "sqrt";
const string intPower = "pow";
const string quitString = "quit";
const string constString = "const";
const string helpString = "help";
const string sinString = "sin";
const string cosString = "cos";
const string tanString = "tan";

//Get the next token from cin, categorize it, and create the appropriate Token.
//Return said token.
Token Token_stream::get()
{
	if (full) { full=false; return buffer; }
	char ch;
	ch = cin.get();
	while(isspace(ch) && ch != '\n') ch = cin.get();
	switch (ch) {
	case '\n':
		return Token(print);
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
  case ',':
		return Token(ch); //Operator
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget(); //Number
		double val;
		cin >> val;
		return Token(number,val);
	}
  case '#':
    return Token(let);
	default:
		if (isalpha(ch)) { //Declaration, quit, functions, names
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s+=ch;
			cin.unget();
			if (s == quitString) return Token(quit);
      else if (s == squareRoot) return Token(root);
      else if (s == intPower) return Token(power);
			else if (s == constString) return Token(constant);
			else if (s == helpString) return Token(help);
			else if (s == sinString) return Token(sinChar);
			else if (s == cosString) return Token(cosChar);
			else if (s == tanString) return Token(tanChar);
			else return Token(name,s);
		}
		error("Bad token");
	}
}

//Skip until the next occurence of c, empty buffer if full.
void Token_stream::ignore(char c)
{
	if (full && c==buffer.kind) { //c was just read, so empty buffer and return
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin>>ch)
		if (ch==c) return;
}

//Create variable type with basic constructor.
struct Variable {
	string name;
	double value;
	bool constant;
	Variable(string n, double v) :name(n), value(v), constant(false) { }
	Variable(string n, double v, bool b) :name(n), value(v), constant(b) { }
};

//Create Symbol table class.
class Symbol_table {
public:
	double get(string s);
	void set(string s, double d);
	bool is_declared(string s);
	void declare(string s, double d, bool isConstant);
private:
	vector<Variable> names;
};

//Find the value for a variable if it exists in names, otherwise return an error.
double Symbol_table::get(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ",s);
}

//Set the value for a variable if it exists in names, otherwise return an error.
void Symbol_table::set(string s, double d)
{
	for (int i = 0; i<=names.size(); ++i)
		if (names[i].name == s) {
			if(names[i].constant == true) error("cannot change value of a constant");
			names[i].value = d;
			return;
		}
	error("set: undefined name ",s);
}

//Check to see if a variable has been declared.
bool Symbol_table::is_declared(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

void Symbol_table::declare(string s, double d, bool isConstant){
	names.push_back(Variable(s, d, isConstant));
}

double raisePower(double d, int i){
  double result = 1;
  for(int j = 1; j <= i; j++){
    result *= d;
  }
  return result;
}

Token_stream ts;

Symbol_table st;

//Forward declare expression to be used in primary.
double expression();

//Handles subexpressions. Given a beginning character, a character which separates
//arguments (separator), and a terminating charactor, it will evaluate each
//given argument as an expression and return a vector containing each argument.
vector<double> subexpression(char begin, char separator, char terminate){
	Token t = ts.get();
	if(t.kind != begin){ //If actual beginning char doesn't match expected, return an error
		ts.unget(t);
		string t(1, begin);
		string s = "'" + t + " expected";
		error(s);
	}
	vector<double> arguments;
	arguments.push_back(expression());
	t = ts.get();
	while(t.kind != terminate){
		//Until the subexpression terminates, evaluate arguments as long as they are
		//separated properly. Otherwise, give an error.
		if(t.kind != separator){
			ts.unget(t);
			string t(1, separator);
			string s = "'" + t + " expected";
			error(s);
		}
		arguments.push_back(expression());
		t = ts.get();
	}
	return arguments;
}

//Obtain and return a primary. Deals with subexpressions, numbers, negative
//numbers, variable assignment, and variable substitution.
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(': //Evaluate subexpression
	{	ts.unget(t);
		vector<double> d = subexpression('(', ',', ')');
    return d[0];
	}
	case '-': //Unary -, negates the next primary
		return - primary();
	case number: //Number
		return t.value;
	case name: //Variable
		{ Token s = ts.get();
			if(s.kind == '='){
				double u = primary();
				st.set(t.name, u);
				return u;
			}
			ts.unget(s);
			return st.get(t.name);
		}
  case root: //Square root function
    { vector<double> d = subexpression('(', ',', ')');
			if(d[0] < 0) error("sqrt arguement less than 0");
			return sqrt(d[0]);
    }
  case power: //Power function
    { vector<double> d = subexpression('(' , ',', ')');
      int i = narrow_cast<int>(d[1]);
			if(i < 0) error("negative power");
    	return raisePower(d[0],i);
    }
	case sinChar: //Sine function
		{ vector<double> d = subexpression('(', ',', ')');
			return sin(d[0]);
		}
	case cosChar: //Cosine function
		{ vector<double> d = subexpression('(', ',', ')');
			return cos(d[0]);
		}
	case tanChar: //Tangent functions
		{ vector<double> d = subexpression('(', ',', ')');
			if(cos(d[0]) == 0) error("divide by 0 in tan");
			return tan(d[0]);
			}
	default:
    ts.unget(t);
		error("primary expected");
	}
}

//Obtain and return a term. Deals with * and / of primaries.
double term()
{
	double left = primary();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

//Gets and returns an evaluated expression. Deals with + and - of terms.
double expression()
{
	double left = term();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
    case name:
      error("name adjacent to double"); //numbers should not be adjacent to letters
      break;
		default:
			ts.unget(t); //No more addition or multiplication of terms - return.
			return left;
		}
	}
}

//Declare a variable. Expects an undeclared name followed by '=' followed by some
//expression. Returns final value of variable.
double declaration(bool makeConst)
{
	Token t = ts.get();
	if (t.kind != 'a') error ("name expected in declaration");
	string name = t.name;
	if (st.is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,name);
	double d = expression();
	st.declare(name, d, makeConst);
	return d;
}

//Evaluate a statement - either an expresion or a declaration.
double statement()
{
	Token t = ts.get();
	switch(t.kind) {
	case let: //If t is let, a declaration follows. Otherwise, expression.
		return declaration(false);
	case constant:
		return declaration(true);
	default:
		ts.unget(t);
    double d = expression();
    Token t = ts.get();
		//We should not have returned with parentheses being the next character
		if(t.kind == '(') error("beginning parenthesis adjacent to number");
    if(t.kind == ')') error("extra ending parenthesis");
		return d;
	}
}

//Reset the token stream after an error so we can continue.
void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void printHelp(){
	cout << "Welcome to our calculator!\n"
			 << "The functions currently supported are:\n"
			 << "\t+, -, *, /, %, ();\n"
			 << "\tsin(t), cos(t), and tan(t);"
			 << "\t" << intPower << "(x,n) which raises x to the integer nth power; and\n"
			 << "\t" << squareRoot << "(x) which takes the square root of x.\n"
			 << "Additionally, you can declare variables using the following notation:\n"
			 << "\t# x = 4\n"
			 << "This declares a variable x and sets it equal to 4.\n"
			 << "You may only declare a variable once. You can reassign it using\n"
			 << "\tx = 6\n"
			 << "which reassigns x to 6. If you wish, you can declare a variable constant using:\n"
			 << "\t" << constString << " x = 6\n"
			 << "This prevents x from being reassigned to another value. The constant k = 1000 is provided.\n"
			 << "More importantly, the constant pi can be accessed using 'pi'.\n"
			 << "Once a variable is declared, it can no longer be made constant.\n"
			 << "The value of an expression is printed once a new line is scanned. "
			 << "Alternatively, you can terminate an expression with ';' to print it.\n"
			 << "To exit, type " << quitString << ".\n"
			 << "To see this guide again, simply input " << helpString << ".\n"
			 << "Thank you for using our calculator!\n"
			 << prompt;
}

//Accept statements from the user until they type "quit".
void calculate()
{
  st.declare("k", 1000, true);
	st.declare("pi", M_PI, true);
	while(true) try {
		cout << prompt;
		Token t = ts.get();
		if(t.kind == help) printHelp();
		while (t.kind == help) t = ts.get(); //Only display help once per cycle
		while (t.kind == print) t = ts.get(); //Deal with multiple prints
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch(runtime_error& e) { //Handle any errors that are thrown in calculation
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

//Begin the program, handle fatal exceptions.
int main()
	try {
		cout << "For info on how to use this calculator, enter " << helpString << ".\n";
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >>c&& c!=';') ;
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin>>c && c!=';');
		return 2;
	}
