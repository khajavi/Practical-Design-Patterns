#include <iostream>
using namespace std;

class Sun;

class State {
public:
	virtual void nextState( Sun* sun ) = 0;
	virtual const char* toString() = 0;
};

class Bamdad : public State {
public:
	virtual void nextState( Sun* sun );
	virtual const char* toString() {
		return "Bamdad";
	}
};

class Chasht : public State {
public:
	virtual void nextState( Sun* sun );
	virtual const char* toString() {
		return "Chasht";
	}
};

class Shamgah : public State {
public:
	virtual void nextState( Sun* sun );
	virtual const char* toString() {
		return "Shamgah";
	}
};

class Shabangah : public State {
public:
	virtual void nextState( Sun* sun );
	virtual const char* toString() {
		return "Shabangah";
	}
};

class Sun {
public:
	Sun( State* state )
		:_state( state ) {
	}

	void afterSixHours() {
		_state->nextState( this );
	}
	
	void changeState( State* state ) {
		_state = state;
	}

	const char* getState() {
		return _state->toString();
	}

private:
	State* _state;
};

void Bamdad::nextState( Sun* sun ) {
	sun->changeState( new Chasht() );
}

void Chasht::nextState( Sun* sun ) {
	sun->changeState( new Shamgah() );
}

void Shamgah::nextState( Sun* sun ) {
	sun->changeState( new Shabangah() );
}

void Shabangah::nextState( Sun* sun ) {
	sun->changeState( new Bamdad() );
}

int main() {

	Sun* sun = new Sun( new Bamdad() );
	sun->afterSixHours();
	cout << sun->getState() << endl;

	sun->afterSixHours();
	cout << sun->getState() << endl;

	sun->afterSixHours();
	cout << sun->getState() << endl;

	sun->afterSixHours();
	cout << sun->getState() << endl;

	sun->afterSixHours();
	cout << sun->getState() << endl;

	return 0;
}
