#include "Adapter.hpp"
#include <stdlib.h>

int main() {
	Adaptee* pAdaptee = new Adaptee();
	Target* pTarget = new Adapter(pAdaptee);
	pTarget->Request();

	delete pTarget;

	return 0;
}
