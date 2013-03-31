#include <iostream>
#include <vector>
using namespace std;

// Iterator interface
class ChannelIterator {
public:
	virtual bool hasNext() = 0;
	virtual void next() = 0;
	virtual const char* currentItem() = 0;
};


// Aggregate Interface
class TV {
public:
	virtual ChannelIterator* getIterator() = 0;
	virtual void add(const char*) = 0;
};

// Concrete Iterator
class ConcreteChannelIterator : public ChannelIterator {
public:
	ConcreteChannelIterator( vector<const char*> channels ) {
		_channels = channels;
		_currentPos = 0;
	}

	bool hasNext() {
		if (_currentPos + 1 < _channels.size() ) {
			return true;
		}
		return false;
	}

	void next() {
		_currentPos++;
	}

	const char* currentItem() {
		return _channels[_currentPos];
	}

private:
	vector<const char*> _channels;
	int _currentPos;
};


// Concrete Aggregator
class ConcreteTV : public TV {
public:
	ConcreteTV() {
		_iterator = new ConcreteChannelIterator( _channels );
	}

	void add( const char* item ) {
		_channels.push_back(item);
	}

	ChannelIterator* getIterator() {
		_iterator = new ConcreteChannelIterator( _channels );
		return _iterator;
	}
private:
	ChannelIterator* _iterator;
	vector<const char*> _channels;
};


int main() {
	
	TV* tv = new ConcreteTV();
	tv->add("Channel 1");
	tv->add("Channel 2");
	ChannelIterator* it = tv->getIterator();
	
	cout << it->hasNext() << endl;
	cout << it->currentItem() << endl;

	return 0;
}
