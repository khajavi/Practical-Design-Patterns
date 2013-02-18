#include "AbstractFactory.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  
  ConcreateFactory1 *pFactory1 = new ConcreateFactory1;
  AbstractProductA *pProductA = pFactory1->CreateProductA();



  return 0;
}
