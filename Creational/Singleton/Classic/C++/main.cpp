#include <iostream>
using namespace std;


class Singleton {
private:
	Singleton() {
		cout << "new Singleton is called" << endl;
	}
	static Singleton* uniqueInstance;
public:
	static Singleton* getInstance() {
		if (!uniqueInstance) {
			uniqueInstance = new Singleton();
		}
		return uniqueInstance;
	}
};

Singleton* Singleton::uniqueInstance = NULL;


int main (int argc, char const* argv[]) {

	Singleton::getInstance();
	Singleton::getInstance();
	Singleton::getInstance();

	return 0;
}
