/*
 * Adopted from http://www.cppblog.com/converse/archive/2006/08/09/11063.html
 */

#include <iostream>
using namespace std;

class Memento {
private:
	friend class Orginator;
	Memento( const char* & state )
		:_state( state ) {
	}

	void setState( const char* & state ) {
		_state = state;
	}

	const char* getState() {
		return _state;
	}

	const char* _state;
};



class Orginator {
public:
	Orginator( const char* & state )
		:_state( state ) {
	}

	Memento* createMemento() {
		return new Memento( _state );
	}

	const char* getState() {
		return _state;
	}

	void setState( const char* & state ) {
		_state = state;
	}

	void restorState( Memento* memento ) {
		if ( NULL != memento ) {
			_state = memento->getState();
		}
	}

	void printState() {
		cout << "State = " << _state << endl;
	}

private:
	const char* _state;
};

int main() {
	
	const char* oldState = "Old state";
	Orginator* orginator = new Orginator( oldState );
	orginator->printState();

	Memento* memento = orginator->createMemento();

	const char* newState = "New State";
	orginator->setState( newState );
	orginator->printState();

	orginator->restorState( memento );
	orginator->printState();
	
	return 0;
}
