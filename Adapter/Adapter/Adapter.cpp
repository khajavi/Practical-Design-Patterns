#include "Adapter.hpp"
#include <iostream>
using namespace std;

void Adaptee::SpecialRequest() {
	cout << "Special Request of Adaptee\n" << endl;
}

Adapter::Adapter(Adaptee* pAdaptee)
	:m_pAdaptee(pAdaptee)
{
}

Adapter::~Adapter() {
	delete m_pAdaptee;
	m_pAdaptee = NULL;
}

void Adapter::Request() {
	cout << "Request of Adapter\n" << endl;
	m_pAdaptee->SpecialRequest();
}
