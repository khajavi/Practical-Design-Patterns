#include <iostream>
#include <cstring>
using namespace std;

class Pizza {};
class CheesePizza : public Pizza {
public:
	CheesePizza() {
		cout << "CheesePizza is created" << endl;
	}
};
class PepperoniPizza : public Pizza {
public:
	PepperoniPizza() {
		cout << "PepperoniPizza is created" << endl;
	}
};
class ClamPizza : public Pizza {
public:
	ClamPizza() {
		cout << "ClamPizza is created" << endl;
	}
};
class VeggiePizza : public Pizza {
public:
	VeggiePizza() {
		cout << "VeggiePizza is created" << endl;
	}
};

class SimplePizzaFactory {
public:
	Pizza* createPizza( const char* type ) {
		if ( strcmp( type, "cheese" ) == 0 ) {
			return new CheesePizza();
		} else if ( strcmp( type, "pepperoni" ) == 0 ) {
			return new PepperoniPizza();
		} else if ( strcmp( type, "clam" ) == 0 ) {
			return new ClamPizza();
		} else if ( strcmp( type, "veggie" ) == 0 ) {
			return new VeggiePizza();
		}
	}
};


int main (int argc, char const* argv[]) {

	SimplePizzaFactory* factory = new SimplePizzaFactory();
	Pizza* pizza = factory->createPizza("clam");


	return 0;
}
