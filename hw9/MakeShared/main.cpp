#include "Duck.h"
#include "RedHeadDuck.h"
#include "MallardDuck.h"
#include "DecoyDuck.h"
#include "FlyNoWay.h"
#include <memory>

int main(int argc, char *argv[]) {
	std::shared_ptr<Duck> red = std::make_shared<RedHeadDuck>();
	std::shared_ptr<Duck> mallard = std::make_shared<MallardDuck>();
	std::shared_ptr<Duck> decoy = std::make_shared<DecoyDuck>();
	
	red->performQuack( );
	red->performFly( );
	red->swim( );
	red->setFlyBehavior(std::shared_ptr<FlyBehavior>(new FlyNoWay( )));
	red->performFly( );

	decoy->performFly( );
}
