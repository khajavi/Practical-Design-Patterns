/*
 * Adopted from http://www.cppblog.com/converse/archive/2006/07/25/10465.html
 */

#include <iostream>
using namespace std;

class Component {
public:
	virtual void operation() = 0;
};

class Decorator : public Component {
public:
	Decorator( Component* component )
		:_component( component ) {
	}
protected:
	Component* _component;
};

class ConcreteComponent : public Component {
public:
	virtual void operation() {
		cout << "operation of ConcreteComponent" << endl;
	}
};

class ConcreteDecorator : public Decorator {
public:
	ConcreteDecorator( Component* component )
		:Decorator( component ) {
	}

	virtual void operation() {
		_component->operation();
		addedBehavior();
	}
private:
	void addedBehavior() {
		cout << "addedBehavior of ConcreteDecorator" << endl;
	}
};


int main() {

	Component* component = new ConcreteComponent();

	Decorator* decorator = new ConcreteDecorator( component );
	decorator->operation();

	return 0;
}
