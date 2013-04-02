/*
 * Adopted from http://javapapers.com/design-patterns/bridge-design-pattern/
 */

#include <iostream>
using namespace std;


// Implementor
class Workshop {
public:
	virtual void work() = 0;
};

// Abstraction
class Vehicle {
public:
	Vehicle( Workshop* workshop1, Workshop* workshop2 )
		:_workshop1( workshop1 ),
		_workshop2( workshop2 ) {
	}

	virtual void manufacture() = 0;

protected:
	Workshop* _workshop1;
	Workshop* _workshop2;
};

// Concrete implementation 1
class Produce : public Workshop {
public:
	virtual void work() {
		cout << "Produced";
	}
};

// Concrete implementation 2
class Assemple : public Workshop {
public:
	virtual void work() {
		cout << " Assembled" << endl;
	}
};

// Refine Abstraction 1
class Car : public Vehicle {
public:
	Car( Workshop* workshop1, Workshop* workshop2 )
		:Vehicle(workshop1, workshop2) {
	}

	virtual void manufacture() {
		cout << "Car ";
		_workshop1->work();
		_workshop2->work();
	}
	
};

// Refine Abstraction 2
class Bike : public Vehicle {
public:
	Bike( Workshop* workshop1, Workshop* workshop2 )
		:Vehicle( workshop1, workshop2 ) {
	}

	virtual void manufacture() {
		cout << "Bike ";
		_workshop1->work();
		_workshop2->work();
	}
};

int main() {

	Vehicle* vehicle1 = new Car( new Produce(), new Assemple() );
	vehicle1->manufacture();

	Vehicle* vehicle2 = new Bike( new Produce(), new Assemple() );
	vehicle2->manufacture();

	return 0;
}
