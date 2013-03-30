#include <iostream>
using namespace std;

class SubSystemA {
public:
	void MethodA() {
		cout << "SubSystemA.MethodA" << endl;
	}
};

class SubSystemB {
public:
	void MethodB() {
		cout << "SubSystemB MethodB" << endl;
	}
};

class SubSystemC {
public:
	void MethodC() {
		cout << "SubSystemC MethodC" << endl;
	}
};


class Facade {
private:
	SubSystemA* subSystemA;
	SubSystemB* subSystemB;
	SubSystemC* subSystemC;
public:
	Facade() {
		subSystemA = new SubSystemA();
		subSystemB = new SubSystemB();
		subSystemC = new SubSystemC();
	}

	void MethodOne() {
		cout << "*** Facade.MethodOne ***" << endl;
		subSystemA->MethodA();
		subSystemB->MethodB();
		subSystemC->MethodC();
	}

	void MethodTwo() {
		cout << "*** Facade.MethodTwo ***" << endl;
		subSystemC->MethodC();
		subSystemA->MethodA();
	}

};
int main() {
		
	Facade* facade = new Facade();

	facade->MethodOne();
	facade->MethodTwo();

	return 0;
}
