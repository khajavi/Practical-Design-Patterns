/*
 * Adopted from Head first Design book, page 238-240
 */

#ifndef DUCK_HPP
#define DUCK_HPP

class Duck {
public:
	virtual void quack() = 0;
	virtual void fly() = 0;
};

#endif
