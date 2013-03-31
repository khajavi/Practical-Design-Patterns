#include <iostream>
#include <vector>
using namespace std;

class Iterator {
public:
	virtual bool hasNext() = 0;
	virtual const char* next() = 0;
}

class Aggregate {
public:
	virtual Iterator* getIterator() = 0;
};

class AnimalIterator : public Iterator {
public:
	
private:
	Aggregate* _aggregate;
	int _current;
}

class Animals : public Aggregate {
public:
	void addValue(const char* value) {
		_animals.push_back(value);
	}

	Iterator* getIterator() {
		Iterator* iter = new MyIterator(this);
		return iter;
	}
private:
	vector<const char*> _animals;
}

int main() {

}
