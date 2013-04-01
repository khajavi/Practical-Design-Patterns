#include <iostream>
using namespace std;

class State;
class Context;

class State {
public:
	virtual void handle( Context* context ) = 0;
};

class Context {
public:
	Context( State* state )
		:_state( state ) {
	}

	void request() {
		_state->handle( this );
	}

	void changeState( State* state ) {
		_state = state;
	}

private:
	State* _state;
};


class ConcreteStateA : public State {
public:
	void handle( Context* context );
};


class ConcreteStateB : public State {
public:
	void handle( Context* context );
};

void ConcreteStateA::handle( Context* context ) {
	cout << "Handle by ConcreteStateA" << endl;
	context->changeState( new ConcreteStateB() );
}


void ConcreteStateB::handle( Context* context ) {
	cout << "Handle by ConcreteStateB" << endl;
	context->changeState( new ConcreteStateA() );
}


int main() {
	
	State* state = new ConcreteStateA();
	Context* context = new Context( state );
	context->request();
	context->request();
	context->request();
	context->request();
	context->request();
}
