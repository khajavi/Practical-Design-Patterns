#include <iostream>
using namespace std;

class AbstractClass {
public:
	void TemplateMethod() {
		PrimitiveOperation1();
		PrimitiveOperation2();
	}
protected:
	virtual void PrimitiveOperation1() = 0;
	virtual void PrimitiveOperation2() = 0;
};

class ConcreteClass1 : public AbstractClass {
protected:
	virtual void PrimitiveOperation1() {
		cout << "PrimitiveOperation1 by ConcreteClass1" << endl;
	}
	virtual void PrimitiveOperation2() {
		cout << "PrimitiveOperation2 by ConcreteClass1" << endl;
	}
};

class ConcreteClass2 : public AbstractClass {
protected:
	virtual void PrimitiveOperation1() {
		cout << "PrimitiveOperation1 by ConcreteClass2" << endl;
	}
	virtual void PrimitiveOperation2() {
		cout << "PrimitiveOperation2 by ConcreteClass2" << endl;
	}
};



int main (int argc, char const* argv[]) {

	AbstractClass* concreteClass = new ConcreteClass1();
	concreteClass->TemplateMethod();

	concreteClass = new ConcreteClass2();
	concreteClass->TemplateMethod();

	return 0;
}
