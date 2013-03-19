/*
 * Adopted from Head first Design book, page 238-240
 */

#ifndef TURKEY_ADAPTER_HPP
#define TURKEY_ADAPTER_HPP
#include "Turkey.hpp"
#include "Duck.hpp"

class TurkeyAdapter : public Duck {
public:
	TurkeyAdapter(Turkey*);
	void quack();
	void fly();
private:
	Turkey* m_turkey;
};

#endif
