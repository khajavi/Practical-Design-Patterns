#include <iostream>
using namespace std;

class Command {
public:
	virtual void execute() = 0;
};

class Receiver {
public:
	void action() {
		cout << "Receiver Action" << endl;
	}
};

class Invoker {
public:
	Invoker(Command* command)
		:_command(command) {
	}
	void invoke() {
		_command->execute();
	}
private:
	Command* _command;
};

class ConcreteCommand : public Command {
public:
	ConcreteCommand(Receiver* receiver);

	virtual void execute();
private:
	Receiver* _receiver;
};

int main (int argc, char const* argv[]) {
	

	return 0;
}
