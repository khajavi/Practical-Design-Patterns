#include "Factory.h"
#include <cstdlib>

int main (int argc, char const* argv[]) {
	Factory* factory = new ConcreteFactory();
	factory->AnOperation();

	return 0;
}
