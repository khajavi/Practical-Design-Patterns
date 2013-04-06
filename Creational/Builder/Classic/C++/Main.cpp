/*
 * Adopted from http://www.cppblog.com/converse/archive/2006/07/21/10305.html
 */

#include <iostream>
using namespace std;

class Builder {
public:
	virtual void buildPartA() = 0;
	virtual void buildPartB() = 0;
};

class ConcreteBuilder1 : public Builder {
public:
	virtual void buildPartA() {
		cout << "buildPartA by ConcreteBuilder1" << endl;
	}

	virtual void buildPartB() {
		cout << "buildPartB by ConcreteBuilder1" << endl;
	}
};

class ConcreteBuilder2 : public Builder {
	virtual void buildPartA() {
		cout << "buildPartA by ConcreteBuilder2" << endl;
	}
	virtual void buildPartB() {
		cout << "buildPartB by ConcreteBuilder2" << endl;
	}
};

class Director {
public:
	Director( Builder* builder )
		:_builder( builder ) {
	}

	void construct() {
		_builder->buildPartA();
		_builder->buildPartB();
	}

private:
	Builder* _builder;
};

int main() {

	Builder* builder1 = new ConcreteBuilder1();
	Director* director1 = new Director( builder1 );
	director1->construct();

	Builder* builder2 = new ConcreteBuilder2();
	Director* director2 = new Director( builder2 );
	director2->construct();

	return 0;
}
