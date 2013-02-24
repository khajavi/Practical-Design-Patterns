/*
 * Adopted from Head first Design book, page 238-240
 */

#include "MallardDuck.hpp"
#include "WildTurkey.hpp"
#include "TurkeyAdapter.hpp"
#include "Duck.hpp"


int main() {
	MallardDuck* duck = new MallardDuck();

	WildTurkey* turkey = new WildTurkey();
	Duck* turkeyAdapter = new TurkeyAdapter(turkey);

	turkeyAdapter->quack();
	turkeyAdapter->fly();

	return 0;
}
