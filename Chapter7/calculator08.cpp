
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
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';

//Get the next token from cin, categorize it, and create the appropriate Token.
//Return said token.
Token Token_stream::get()
{
	if (full) { full=false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
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
	default:
		if (isalpha(ch)) { //Declaration, quit, or name
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;
			cin.unget();
			if (s == "let") return Token(let);
			if (s == "quit") return Token(quit);
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
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

//Find the value for a variable if it exists in names, otherwise return an error.
double get_value(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ",s);
}

//Set the value for a variable if it exists in names, otherwise return an error.
void set_value(string s, double d)
{
	for (int i = 0; i<=names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ",s);
}

//Check to see if a variable has been declared.
bool is_declared(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

//Forward declare expression to be used in primary.
double expression();

//Obtain and return a primary. Deals with subexpressions, numbers, negative
//numbers, and variable substitution.
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(': //Evaluate subexpression
	{	double d = expression();
		t = ts.get();
		if (t.kind != ')') error("'(' expected");
	}
	case '-': //Unary -, negates the next primary
		return - primary();
	case number: //Number
		return t.value;
	case name: //Variable
		return get_value(t.name);
	default:
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
		default:
			ts.unget(t); //No more addition or multiplication of terms - return.
			return left;
		}
	}
}

//Declare a variable. Expects an undeclared name followed by '=' followed by some
//expression. Returns final value of variable.
double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error ("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,name);
	double d = expression();
	names.push_back(Variable(name,d));
	return d;
}

//Evaluate a statement - either an expresion or a declaration.
double statement()
{
	Token t = ts.get();
	switch(t.kind) {
	case let: //If t is let, a declaration follows. Otherwise, expression.
		return declaration();
	default:
		ts.unget(t);
		return expression();
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
