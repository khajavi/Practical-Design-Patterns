/*
 * Adopted from http://www.cppblog.com/converse/archive/2006/08/05/10858.html
 */

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

typedef int STATE;

class Observer;

// Subject Interface (Observable)
class Subject {
public:
	Subject()
		:_subjectState( -1 ) {
		}

	void notify(); 

	void attach( Observer* observer ) {
		cout << "attach an Observer" << endl;
		_listObserver.push_back( observer );
	}

	void detach( Observer* observer ) {
		list<Observer*>::iterator iter;
		iter = find( _listObserver.begin(), _listObserver.end(), observer );

		if ( _listObserver.end() != iter ) {
			_listObserver.erase( iter );
		}
		cout << "detach and Observer" << endl;
	}

	virtual void setState( STATE state ) {
		cout << "setState by subject" << endl;
		_subjectState = state;
	}

	virtual STATE getState() {
		cout << "getState by subject" << endl;
		return _subjectState;
	}

protected:
	STATE _subjectState;
	list<Observer*> _listObserver;
};



class Observer {
public:
	virtual void update( Subject* subject ) = 0;
protected:
	STATE _observerState;
};

class ConcreteSubject : public Subject {
public:
	virtual void setState( STATE state ) {
		cout << "setState by ConcreteSubject" << endl;
		_subjectState = state;
	}

	virtual STATE getState() {
		cout << "getState by ConcreteSubject" << endl;
		return _subjectState;
	}
};

class ConcreteObserver : public Observer {
public:
	virtual void update( Subject* subject ) {
		if ( NULL == subject )
			return;
		_observerState = subject->getState();
		cout << "the ObserverState is " << _observerState << endl;
	}
};

void Subject::notify() {
	cout << "notify observer's state" << endl;

	list<Observer*>::iterator iter1, iter2;
	for ( iter1 = _listObserver.begin(), iter2 = _listObserver.end();
			iter1 != iter2;
			++iter1 ) {
		(*iter1)->update( this );
	}
}

int main() {

	Observer* observer1 = new ConcreteObserver();
	Observer* observer2 = new ConcreteObserver();

	Subject* subject = new ConcreteSubject();

	subject->attach( observer1 );
	subject->attach( observer2 );

	subject->setState( 4 );
	subject->notify();

	subject->detach( observer1 );
	subject->setState( 10 );
	subject->notify();

	return 0;
}
