#include"TurkeyAdapter.h"

int main()
{
	Turkey* wTurkey = new WildTurkey();

	// With the adapter we can call Quack() on Turkey even tho a turkey doesn't quack
	TurkeyAdapter ta = TurkeyAdapter(wTurkey);
	ta.fly();
	ta.quack();

	// ------------------------------
	Duck* mallard = new MallardDuck();
	mallard->quack();
	mallard->fly();

	//wTurkey->fly();
	//wTurkey->gobble();
	delete wTurkey;
	delete mallard;

}