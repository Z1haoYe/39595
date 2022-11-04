#include <iostream>
#include <map>
#include <regex>
#include "Stmt.h"
#include "SymbolTable.h"

declscal::declscal() {}

void declscal::declScal(const std::string& line)
{
	std::string str = (Stmt::matchString(line))[1];
	std::list<SymbolTable>::reverse_iterator node = SymbolTable::symbols.rbegin();
	if (SymbolTable::findVar(str) != -1)
	{
		if (SymbolTable::getCurrLv() == SymbolTable::findVarLv(str))
		{
			std::cout << "error: attempting to add variable with name " + str + " twice" << std::endl;
			exit(EXIT_FAILURE);

		}
	
	}

	SymbolTable ret(va, str, SymbolTable::getCurrLoc(), 1, SymbolTable::getCurrLv());
	SymbolTable::updateLoc(1);
	SymbolTable::symbols.push_back(ret);
}