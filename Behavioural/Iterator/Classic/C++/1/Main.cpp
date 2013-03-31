#include <iostream>
using namespace std;

typedef int DATA;
class Iterator;

class Aggregate {
public:
	virtual Iterator* createIterator(Aggregate* aggregate) = 0;
	virtual int getSize() = 0;
	virtual DATA getItem(int nIndex) = 0;
};

class Iterator {
public:
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool isDone() = 0;
	virtual DATA currentItem() = 0;
};

class ConcreteIterator : public Iterator {
public:
	ConcreteIterator( Aggregate* aggregate ) 
		:_concreteAggregate( aggregate ),
		_index( 0 )
	{
		
	}

	virtual void first() {
		_index = 0;
	}

	virtual void next() {
		if ( _index < _concreteAggregate->getSize() ) {
			++_index;
		}
	}

	virtual bool isDone() {
		return (_index == _concreteAggregate->getSize());
	}

	virtual DATA currentItem() {
		return _concreteAggregate->getItem(_index);
	}
private:
	Aggregate* _concreteAggregate;
	int _index;
};



class ConcreteAggregate : public Aggregate {
public:
	ConcreteAggregate( int size ) 
		:_size( size ),
		_data( NULL )
	{
		_data = new DATA[_size];

		for ( int i = 0; i < size; ++i ) {
			_data[i] = i;
		}
	}
	
	virtual Iterator* createIterator( Aggregate* aggregate) {
		return new ConcreteIterator( this );
	}

	virtual int getSize() {
		return _size;
	}

	virtual DATA getItem( int index ) {
		if ( index < _size ) {
			return _data[index];
		} else {
			return -1;
		}
	}

private:
	int _size;
	DATA* _data;
};

int main() {
	
	Aggregate* aggregate = new ConcreteAggregate( 4 );
	Iterator* iterator = new ConcreteIterator( aggregate );

	for (; false == iterator->isDone(); iterator->next() ) {
		cout << iterator->currentItem() << endl;
	}

	return 0;
}
