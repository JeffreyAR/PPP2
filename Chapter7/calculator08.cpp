
/*
  I do not claim to be the author of this program.

	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

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
const string squareRoot = "sqrt";
const string intPower = "pow";
const string quitString = "exit";
const string constString = "const";

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
		return Token(';');
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
		if (isalpha(ch)) { //Declaration, quit, square root, or name
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s+=ch;
			cin.unget();
			if (s == quitString) return Token(quit);
      if (s == squareRoot) return Token(root);
      if (s == intPower) return Token(power);
			if (s == constString) return Token(constant);
			return Token(name,s);
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

//Obtain and return a primary. Deals with subexpressions, numbers, negative
//numbers, variable assignment, and variable substitution.
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(': //Evaluate subexpression
	{	double d = expression();
		t = ts.get();
		if (t.kind != ')'){
      ts.unget(t);
      error("')' expected");
    }
    return d;
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
    { t = ts.get();
      if(t.kind != '('){
        ts.unget(t);
        error("'(' expected after ", squareRoot);
      }
      double d = expression();
      if(d < 0) error("expression inside sqrt is negative");
      t = ts.get();
      if (t.kind != ')'){
        ts.unget(t);
        error("')' expected");
      }
      return sqrt(d);
    }
  case power: //Power function
    { t = ts.get();
      if(t.kind != '('){
        ts.unget(t);
        error("'(' expected after ", intPower);
      }
      double d = expression();
      t = ts.get();
      if(t.kind != ','){
        ts.unget(t);
        error("',' missing in ", intPower);
      }
      int i = narrow_cast<int>(expression());
      t = ts.get();
      if (t.kind != ')'){
        ts.unget(t);
        error("')' expected");
      }
    return raisePower(d,i);
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
      error("name adjacent to double");
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

//Accept statements from the user until they type "quit".
void calculate()
{
  st.declare("k", 1000, true);
	while(true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get(); //Deal with multiple prints
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
