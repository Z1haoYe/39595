#include "Stmt.h"
#include "SymbolTable.h"

start::start() {}

int start::getStartSize()
{
	int size = 0;
	int currlv = 0;
	std::list<SymbolTable>::reverse_iterator node = SymbolTable::symbols.rbegin();
	while (node != SymbolTable::symbols.rend())
	{
		if ((*node).getLv() == currlv)
		{
			size += (*node).getSize();
			//node = decltype(node)((SymbolTable::symbols).erase(std::next(node).base()));
			//node++;
		}
		node++;
	}
	return size;
}

std::string start::makeStmt()
{
	return output + " " + std::to_string(size);
}

void start::changeSize(int size_)
{
	size = size_;

}