/*
 * Ported to C++ from http://www.dofactory.com/Patterns/PatternInterpreter.aspx
 */

#include <iostream>
#include <vector>
using namespace std;

class Context {

};


class AbstractExpression {
public:
	virtual void interpret( Context* context ) = 0;
};

class TerminalExpression : public AbstractExpression {
public:
	virtual void interpret( Context* context ) {
		cout << "Called Terminal.interpret()" << endl;
	}
};

class NoneterminalExpression : public AbstractExpression {
public:
	virtual void interpret( Context* context ) {
		cout << "Called NonTerminal.interpret()" << endl;
	}
};


int main() {

	Context* context = new Context();

	vector<AbstractExpression*> list;

	list.push_back( new TerminalExpression() );
	list.push_back( new NoneterminalExpression() );
	list.push_back( new TerminalExpression() );
	list.push_back( new TerminalExpression() );

	for ( vector<AbstractExpression*>::iterator it = list.begin();
			it != list.end();
			++it ) {
		(*it)->interpret(context);
	}

	return 0;
}
