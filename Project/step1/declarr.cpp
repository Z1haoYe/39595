#include <iostream>
#include <map>
#include <regex>
#include "Stmt.h"
#include "SymbolTable.h"

declarr::declarr() {}

void declarr::declArr(const std::string& line)
{
	std::vector<std::string> list = Stmt::matchString(line);
	int size = std::stoi(list[2]);
	if (SymbolTable::findVar(list[1]) != -1)
	{
		if (SymbolTable::getCurrLv() == SymbolTable::findVarLv(list[1]))
		{
			std::cout << "error: attempting to add variable with name " + list[1] + " twice" << std::endl;
			exit(EXIT_FAILURE);

		}

	}
	SymbolTable ret(va, list[1], SymbolTable::getCurrLoc(), size, SymbolTable::getCurrLv());
	SymbolTable::updateLoc(size);
	SymbolTable::symbols.push_back(ret);
}