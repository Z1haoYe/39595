#include <iostream>
#include "PekinDuck.h"
#include "Quack.h"
#include "FlysPoorly.h"
#include "LaysEggsNotBroody.h"

PekinDuck::PekinDuck() {
	quackBehavior = new Quack();
	flyBehavior = new FlysPoorly();
	laysEggs = new LaysEggsNotBroody();
}

void PekinDuck::display() {
	std::cout << "I'm a pekin duck" << std::endl;
}
