#include <iostream>
using namespace std;

class Strategy {
public:
	virtual void AlgorithmInterface() = 0;
};


class ConcreteStrategyA : public Strategy {
public:
	virtual void AlgorithmInterface() {
		cout << "AlgorithmInterface implemented by ConcreteStrategyA\n" << endl;
	}
};


class ConcreteStrategyB : public Strategy {
public:
	virtual void AlgorithmInterface() {
		cout << "AlgorithmInterface implemented by ConcreteStrategyB\n" << endl;
	}
};

class Context {
public:
	Context(Strategy* strategy)
		: _strategy(strategy) {
	}
	
	void changeStrategy(Strategy* strategy) {
		_strategy = strategy;
	}

	void ContextInterface() {
		if ( NULL != _strategy) {
			_strategy->AlgorithmInterface();
		}
	}
private:
	Strategy* _strategy;
};



int main (int argc, char const* argv[]) {
	
	Context* context = new Context(new ConcreteStrategyA());
	context->ContextInterface();
	context->changeStrategy(new ConcreteStrategyB());
	context->ContextInterface();

	return 0;
}
