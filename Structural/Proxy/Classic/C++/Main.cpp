#include <iostream>
using namespace std;

class Subject {
public:
	virtual void request() = 0;
};

class RealSubject : public Subject {
public:
	virtual void request() {
		cout << "Request by RealSubject" << endl;
	}
};

class Proxy : public Subject {
public:
	virtual void request() {
		cout << "Request by Proxy" << endl;
		if ( _realSubject == NULL ) {
			_realSubject = new RealSubject();
		}
		_realSubject->request();
	}
private:
	RealSubject* _realSubject;
};

int main() {
	
	Subject* proxy = new Proxy();
	proxy->request();

	return 0;
}
