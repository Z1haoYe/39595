#include <iostream>
#include "MallardDuck.h"
#include "Quack.h"
#include "FlyWithWings.h"

MallardDuck::MallardDuck( ) {
   quackBehavior = std::shared_ptr<QuackBehavior>(new Quack( ));
   flyBehavior = std::shared_ptr<FlyBehavior>(new FlyWithWings( ));
}

void MallardDuck::display( ) {
   std::cout << "I’m a real mallard duck" << std::endl;
}
