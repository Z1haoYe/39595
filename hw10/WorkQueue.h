#include <vector>
#include "Command.h"
#include <memory>

static std::vector<Command> que;

std::shared_ptr<Command> get()
{
	return std::make_shared<que[0]>;
}
