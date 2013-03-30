#include <iostream>
using namespace std;

class Command {
public:
	virtual void execute() = 0;
};

//Receiver
class Light {
public:
	void switchOn() {
		on = true;
		cout << "Light is switched on" << endl;
	}

	void switchOff() {
		on = false;
		cout << "Light is switched off" << endl;
	}
private:
	bool on;
};

//ConcreteCommand1
class LightOnCommand : public Command {
public:
	LightOnCommand(Light* light)
		:_light(light) {
	}

	void execute() {
		_light->switchOn();
	}

private:
	Light* _light;
};


//ConcreteCommand2
class LightOffCommand : public Command {
public:
	LightOffCommand(Light* light)
		:_light(light) {
	}

	void execute() {
		_light->switchOff();
	}
private:
	Light* _light;
};

//Invoker
class RemoteControl {
public:
	void setCommand(Command* command) {
		_command = command;
	}
	void pressButton() {
		_command->execute();
	}

private:
	Command* _command;
};




int main() {
	RemoteControl* control = new RemoteControl();
	
	Light* light = new Light();

	Command* lightsOn = new LightOnCommand( light );
	Command* lightsOff = new LightOffCommand( light );

	//switch on
	control->setCommand( lightsOn );
	control->pressButton();

	//switch off
	control->setCommand( lightsOff );
	control->pressButton();
	
	return 0;
}
