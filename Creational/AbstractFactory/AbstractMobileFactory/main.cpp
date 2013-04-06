#include <iostream>
using namespace std;

class SmartPhone {};
class NoneSmartPhone {};

class Nokia1100 : public NoneSmartPhone {
public:
	Nokia1100() {
		cout << "Nokia1100 is created" << endl;
	}
};

class NokiaN950 : public SmartPhone {
public:
	NokiaN950() {
		cout << "NokiaN950 is created" << endl;
	}
};

class MotorolaAtrix4G : public SmartPhone {
public:
	MotorolaAtrix4G() {
		cout << "Atrix4G is created" << endl;
	}
};

class MotorolaA1200 : public NoneSmartPhone {
public:
	MotorolaA1200() {
		cout << "A1200 is created" << endl;
	}
};

class AbstractMobileFactory {
public:
	virtual SmartPhone* createSmartPhone() = 0;
	virtual NoneSmartPhone* createNoneSmartPhone() = 0;
};

class NokiaFactory : public AbstractMobileFactory {
public:
	SmartPhone* createSmartPhone() {
		return new NokiaN950();
	}

	NoneSmartPhone* createNoneSmartPhone() {
		return new Nokia1100();
	}
};

class MotorolaFactory : public AbstractMobileFactory {
public:
	SmartPhone* createSmartPhone() {
		return new MotorolaAtrix4G();
	}

	NoneSmartPhone* createNoneSmartPhone() {
		return new MotorolaA1200();
	}
};


int main (int argc, char const* argv[]) {
	
	AbstractMobileFactory* factory = new NokiaFactory();
	SmartPhone* smartPhone = factory->createSmartPhone();


	return 0;
}
