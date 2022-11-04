#include <iostream>
#include "DecoyDuck.h"
#include "FlyNoWay.h"
#include "MuteQuack.h"

DecoyDuck::DecoyDuck( ) {
   flyBehavior = std::unique_ptr<FlyBehavior>(new FlyNoWay( ));
   quackBehavior = std::unique_ptr<QuackBehavior>(new MuteQuack());
}

void DecoyDuck::display( ) {
   std::cout << "I’m a decoy duck" << std::endl;
}
