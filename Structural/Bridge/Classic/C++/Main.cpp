#include <iostream>
using namespace std;

class Implementor {
public:
	virtual void operationImpl() = 0;
};


class Abstraction {
public:
	Abstraction( Implementor* implementor )
		:_implementor( implementor ) {
	}

	void operation() {
		_implementor->operationImpl();
	}
protected:
	Implementor* _implementor;
};

class ConcreteImplementorA : public Implementor {
public:
	virtual void operationImpl() {
		cout << "Implementation by ConcreteImplementorA" << endl;
	}
};

class ConcreteImplementorB : public Implementor {
public:
	virtual void operationImpl() {
		cout << "Implementation by ConcreteImplementorB" << endl;
	}
};


int main() {

	ConcreteImplementorA* implementorA = new ConcreteImplementorA();
	Abstraction* abstraction1 = new Abstraction( implementorA );
	abstraction1->operation();

	ConcreteImplementorB* implementorB = new ConcreteImplementorB();
	Abstraction* abstraction2 = new Abstraction( implementorB );
	abstraction2->operation();

	return 0;
}
