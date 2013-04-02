/*
 * Adopted from http://java.dzone.com/articles/design-patterns-bridge
 */

#include <iostream>
using namespace std;

// Implementor
class TV {
public:
	virtual void on() = 0;
	virtual void off() = 0;
};

// Concrete Implementor
class Sony : public TV {
public:
	virtual void on() {
		cout << "Sony specifc on" << endl;
	}

	virtual void off() {
		cout << "Sony specifc off" << endl;
	}
};

// Concrete Implementor
class Philips : public TV {
public:
	virtual void on() {
		cout << "Philips specifc on" << endl;
	}

	virtual void off() {
		cout << "Philips specifc off" << endl;
	}
};

// Abstraction
class RemoteControl {
public:
	RemoteControl( TV* tv )
		:_tv( tv ) {
	}

	void on() {
		_tv->on();
	}

	void off() {
		_tv->off();
	}
private:
	TV* _tv;
};

int main() {

	RemoteControl* remoteControl = new RemoteControl( new Sony() );
	remoteControl->on();

	return 0;
}
