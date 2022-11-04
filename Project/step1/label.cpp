#include <iostream>
#include <map>
#include <regex>
#include "Stmt.h"
#include "SymbolTable.h"

label_::label_() {}

void label_::declLabel(const std::string& line)
{
	//std::string* list = ;
	std::string labelName = (Stmt::matchString(line))[1];
	int lineLoc = SymbolTable::getlineNum();
	if (SymbolTable::findVar(labelName) != -1)
	{
		if (SymbolTable::getCurrLv() == SymbolTable::findVarLv(labelName))
		{
			std::cout << "error: attempting to add label with name " + labelName + " twice" << std::endl;
			exit(EXIT_FAILURE);

		}

	}

	SymbolTable ret(labl, labelName, lineLoc, 0, SymbolTable::getCurrLv());
	SymbolTable::symbols.push_back(ret);
}