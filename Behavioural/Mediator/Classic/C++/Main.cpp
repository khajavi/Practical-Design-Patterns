#include <iostream>
#include <vector>
using namespace std;

class Colleague;

class Mediator {
public:
	virtual void send( const char* message, Colleague* colleague ) = 0;
};


class Colleague {
public:
	Colleague( Mediator* mediator )
		:_mediator( mediator ) {
	}

	virtual void notify( const char* message ) = 0;

protected:
	Mediator* _mediator;
};

class ConcreteColleague1 : public Colleague {
public:
	ConcreteColleague1( Mediator* mediator )
		:Colleague( mediator ) {
	}

	void send( const char* message ) {
		_mediator->send( message, this );
	}

	void notify( const char* message ) {
		cout << "ConcreteColleague1 gets message: " << message << endl;
	}
};


class ConcreteColleague2 : public Colleague {
public:
	ConcreteColleague2( Mediator* mediator )
		:Colleague( mediator ) {
	}

	void send( const char* message ) {
		_mediator->send( message, this );
	}

	void notify( const char* message ) {
		cout << "ConcreteColleague2 gets message: " << message << endl;
	}
};

class ConcreteMediator : public Mediator {
public:
	void registerColleague( Colleague* colleague ) {
		_coleagues.push_back( colleague );
	}

	virtual void send( const char* message, Colleague* colleague ) {
		for( vector<Colleague*>::iterator it = _coleagues.begin();
				it != _coleagues.end(); ++it ) {
			if ( *it != colleague ) {
				(*it)->notify( message );
			}
		}
	}

private:
	vector<Colleague*> _coleagues;
};


int main() {
	
	ConcreteMediator* mediator = new ConcreteMediator();

	ConcreteColleague1* colleague1 = new ConcreteColleague1( mediator );

	ConcreteColleague2* colleague2 = new ConcreteColleague2( mediator );
	ConcreteColleague2* colleague3 = new ConcreteColleague2( mediator );

	mediator->registerColleague( colleague1 );
	mediator->registerColleague( colleague2 );
	mediator->registerColleague( colleague3 );
	mediator->registerColleague( colleague3 );


	colleague1->send( "How are you?" );
	colleague2->send( "Fine, thanks." );	

	return 0;
}
