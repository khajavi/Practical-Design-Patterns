//source: https://github.com/wxjeacen/DesignPattern.git

#include <iostream>
#include "AbstractFactory.hpp"
using namespace std;

ConcreateProductA1::ConcreateProductA1() {
  cout << "Construction of ConreateProductA1" << endl;
}

ConcreateProductA1::~ConcreateProductA1() {
  cout << "Destruction of ConcreateProductA1" << endl;
}

ConcreateProductA2::ConcreateProductA2() {
  cout << "Construction of ConcreateProductA2" <<endl;
}

ConcreateProductA2::~ConcreateProductA2() {
  cout << "Destruction of ConcreateProductA2" << endl;
}


ConcreateProductB1::ConcreateProductB1() {
  cout << "Construction of ConcreateProductB1" <<endl;
}

ConcreateProductB1::~ConcreateProductB1() {
  cout << "Destruction of ConcreateProductB1" << endl;
}

ConcreateProductB2::ConcreateProductB2() {
  cout << "Construction of ConcreateProductB2" <<endl;
}

ConcreateProductB2::~ConcreateProductB2() {
  cout << "Destruction of ConcreateProductB2" << endl;
}

ConcreateFactory1::ConcreateFactory1() {
  cout << "Construction of ConcreateFactory1" << endl;
}

ConcreateFactory1::~ConcreateFactory1() {
  cout << "Destruction of ConcreateFactory1" << endl;
}

AbstractProductA* ConcreateFactory1::CreateProductA() {
  return new ConcreateProductA1();
}

AbstractProductB* ConcreateFactory1::CreateProductB() {
  return new ConcreateProductB1();
}

ConcreateFactory2::ConcreateFactory2() {
  cout << "Construction of ConcreateFactory2" << endl;
}

ConcreateFactory2::~ConcreateFactory2() {
  cout << "Destruction of ConcreateFactory2" << endl;
}

AbstractProductA* ConcreateFactory2::CreateProductA() {
  return new ConcreateProductA2();
}

AbstractProductB* ConcreateFactory2::CreateProductB() {
  return new ConcreateProductB2();
}
