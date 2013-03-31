/*
 * Adopted from http://www.codeproject.com/Articles/362986/Understanding-and-Implementing-the-Iterator-Patter
 */
#include <iostream>
#include <vector>
using namespace std;

class Iterator {
public:
	virtual const char* next() = 0;
	virtual bool hasNext() = 0;
};

class Aggregate {
public:
	virtual Iterator* getIterator() = 0;
	virtual const char* getItem( int ) = 0;
	virtual int size() = 0;
};

class AnimalIterator : public Iterator {
public:
	AnimalIterator( Aggregate* aggregate ) 
		: _current( -1 ),
		_aggregate( aggregate )
	{
	}

	const char* next() {
		_current++;
		return _aggregate->getItem( _current );
	}

	bool hasNext() {
		return (_aggregate->size() != _current); 
	}

private:
	Aggregate* _aggregate;
	int _current;
};

class AnimalAggregate : public Aggregate {
public:
	AnimalAggregate() {
	}

	void addAnimal( const char* value ) {
		_animals.push_back( value );
	}

	Iterator* getIterator() {
		Iterator* iter = new AnimalIterator( this );
		return iter;
	}

	const char* getItem( int index ) {
		return _animals[index];
	}

	int size() {
		return _animals.size();
	}

private:
	vector<const char*> _animals;
};


int main() {

	AnimalAggregate* aggregate = new AnimalAggregate();
	aggregate->addAnimal("Cat");
	aggregate->addAnimal("Fish");
	aggregate->addAnimal("Duck");
	aggregate->addAnimal("Snake");
	aggregate->addAnimal("Ant");

	Iterator* iter = aggregate->getIterator();

	const char* string;
	for (string = iter->next() ; iter->hasNext(); string = iter->next() ) {
		cout << string << endl;
	}

	return 0;
}
