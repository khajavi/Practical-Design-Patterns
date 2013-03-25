#include "Factory.h"
#include <iostream>

using namespace std;

void Factory::AnOperation() {
	Product* p = FactoryMethod();
	std::cout << "An operation of product\n";
}

Product* ConcreteFactory::FactoryMethod() {
	return new ConcreteProduct();
}
