#include <iostream>
#include "Duck.h"

int main()
{
	Duck* mallard = new Mallard();
	mallard->performQuack();
	mallard->performFly();
	mallard->setFlyBehaviour(new FlyNoWay());
	mallard->performFly();	
	delete mallard;
	//mallard->~Duck();

	Duck* rocky = new RocketDuck();
	rocky->performQuack();
	rocky->performFly();
	delete rocky;
}