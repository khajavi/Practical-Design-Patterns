#ifndef FACTORY_H
#define FACTORY_H

class Product {

};

class ConcreteProduct : public Product {

};

class Factory {
public:
	void AnOperation();
protected:
	virtual Product* FactoryMethod() = 0;
};

class ConcreteFactory : public Factory {
protected:
	virtual Product* FactoryMethod();
};

#endif
