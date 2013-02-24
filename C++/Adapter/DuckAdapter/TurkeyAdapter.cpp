/*
 * Adopted from Head first Design book, page 238-240
 */

#include "TurkeyAdapter.hpp"

TurkeyAdapter::TurkeyAdapter(Turkey* turkey) {
	m_turkey = turkey;
}

void TurkeyAdapter::quack() {
	m_turkey->gobble();
}

void TurkeyAdapter::fly() {
	for(int i = 0; i < 5; i++) {
		m_turkey->fly();
	}
}

