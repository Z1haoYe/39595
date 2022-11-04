#include <iostream>
#include <map>
#include <regex>
#include "Stmt.h"
#include "SymbolTable.h"

gosublabel* return_::find_gosub()
{
	std::list<Stmt*>::reverse_iterator node = (Stmt::stmts).rbegin();
	while (node != Stmt::stmts.rend())
	{
		gosublabel* ret = dynamic_cast<gosublabel*>(*node);
		if (ret != NULL) return ret;
		node++;
	}
	return nullptr;
}

void return_::findSize_clean()
{
	int size = 0;
	int currlv = SymbolTable::getCurrLv();
	std::list<SymbolTable>::reverse_iterator node = SymbolTable::symbols.rbegin();
	while (node != SymbolTable::symbols.rend())
	{
		if ((*node).getLv() == currlv)
		{
			size += (*node).getSize();
			node = decltype(node)((SymbolTable::symbols).erase(std::next(node).base()));
		}
		node++;
	}
	SymbolTable::decLv();
	gosublabel* gosubptr = return_::find_gosub();
	(*gosubptr).gosublabel::changeSize(size);
}

std::string return_::makeStmt()
{
	return output;
}