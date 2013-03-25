#include <iostream>
#include <cstring>
using namespace std;

class Mobile {};
class N900 : public Mobile {
public:
	N900() {
		cout << "N900 is created" << endl;
	}
};
class N95 : public Mobile {
public:
	N95() {
		cout << "N95 is created" << endl;
	}
};

class Atrix : public Mobile {
public:
	Atrix() {
		cout << "Atrix is created" << endl;
	}
};

class A1200 : public Mobile {
public:
	A1200() {
		cout << "A1200 is created" << endl;
	}
};

class Factory {
public:
 virtual Mobile* createMobile(const char* name) = 0;
};

class NokiaFactory : public Factory {
	Mobile* createMobile(const char* name) {
		if (strcmp( name, "N900" ) == 0 ) {
			return new N900();
		} else if ( strcmp( name, "N95" ) == 0 ) {
			return new N95();
		}
	}	
};

class MotorolaFactory : public Factory {
	Mobile* createMobile(const char* name) {
		if (strcmp( name, "Atrix" ) == 0 ) {
			return new Atrix();
		} else if ( strcmp( name, "A1200" ) == 0 ) {
			return new A1200();
		}
	}	
};


int main (int argc, char const* argv[]) {	
	
	Factory* factory = new NokiaFactory();
	Mobile* mobile = factory->createMobile("N900");
	
	factory = new MotorolaFactory();
	mobile = factory->createMobile("A1200");

	return 0;
}
