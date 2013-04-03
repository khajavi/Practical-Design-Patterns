/*
 * Adopted from http://www.cppblog.com/converse/archive/2006/07/28/10663.html
 */

#include <iostream>
using namespace std;

class Handler {
public:
	Handler( Handler* successor = NULL )
		:_successor( successor ) {
	}

	virtual void handleRequest() = 0;
protected:
	Handler* _successor;
};

class ConcreteHandler1 : public Handler {
public:
	ConcreteHandler1( Handler* successor = NULL )	
		:Handler( successor ) {
	}

	virtual void handleRequest() {
		if ( NULL != _successor ) {
			_successor->handleRequest();
		} else {
			cout << "handleRequest by ConcreteHandler1" << endl;
		}
	}
};

class ConcreteHandler2 : public Handler {
public:
	ConcreteHandler2( Handler* successor = NULL )
		:Handler( successor ) {
		}
	virtual void handleRequest() {
		if ( NULL != _successor ) {
			_successor->handleRequest();
		} else {
			cout << "handleRequest by ConcreteHandler2" << endl;
		}
	}
};

int main() {

	Handler* handler1 = new ConcreteHandler1();
	Handler* handler2 = new ConcreteHandler2( handler1 );

	handler2->handleRequest();


	return 0;
}
