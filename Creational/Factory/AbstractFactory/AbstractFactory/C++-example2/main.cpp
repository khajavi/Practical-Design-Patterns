#include <iostream>
using namespace std;

class AbstractProductA {};

class ProductA1 : public AbstractProductA {
public:
	ProductA1() {
		cout << "Product A of Factory 1 is created" << endl;
	}
};

class ProductA2 : public AbstractProductA {
public:
	ProductA2() {
		cout << "Product A of Factory 2 is created" << endl;
	}
};

class AbstractProductB {};

class ProductB1 : public AbstractProductB {
public:
	ProductB1() {
		cout << "Product B of Factory 1 is created" << endl;
	}
};

class ProductB2 : public AbstractProductB {
public:
	ProductB2() {
		cout << "Product B of Factory 2 is created" << endl;
	}
};

class AbstractFactory {
public:
	virtual AbstractProductA* createProductA() = 0;
	virtual AbstractProductB* createProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory {
public:
	AbstractProductA* createProductA() {
		return new ProductA1();
	}

	AbstractProductB* createProductB() {
		return new ProductB1();
	}
};

class ConcreteFactory2 : public AbstractFactory {
public:
	AbstractProductA* createProductA() {
		return new ProductA2();
	}

	AbstractProductB* createProductB() {
		return new ProductB2();
	}
};

int main (int argc, char const* argv[]) {
	
	AbstractFactory* factory = new ConcreteFactory1();
	AbstractProductA* pa1 = factory->createProductA();
	AbstractProductB* pb1 = factory->createProductB(); 

	return 0;
}
