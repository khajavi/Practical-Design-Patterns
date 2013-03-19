#ifndef ADAPTER_H
#define ADAPTER_H

class Target {
public:
	Target() {}
	virtual ~Target() {}
	virtual void Request() = 0;
};

class Adaptee {
public:
	Adaptee() {}
	~Adaptee() {}
	void SpecialRequest();
};

class Adapter
	:public Target {
public:
	Adapter(Adaptee* pAdaptee);
	virtual ~Adapter();
	virtual void Request();

private:
	Adaptee* m_pAdaptee;
};

#endif
