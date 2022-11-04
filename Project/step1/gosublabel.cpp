#include <iostream>
#include <map>
#include <regex>
#include "Stmt.h"
#include "SymbolTable.h"

gosublabel::gosublabel(const std::string& line)
{
	std::regex format("^(gosublabel)(\\s+)[a-zA-Z][a-zA-Z0-9]{0,31}$");
	if (!regex_match(line, format))
	{
		std::cout << "error:gosublabel format dnm" << std::endl;
		exit(-1);
	}

	labelName = (Stmt::matchString(line))[1];
	size = -1;
		
}

void gosublabel::declLabel()
{
	//std::string* list = ;
	//std::string labelName = (Stmt::matchString(line))[1];
	int lineLoc = SymbolTable::getlineNum();

	SymbolTable ret(labl, labelName, lineLoc, 0, SymbolTable::getCurrLv());
	SymbolTable::symbols.push_back(ret);
	SymbolTable::updateLv();
}

std::string gosublabel::makeStmt()
{
	return output + " " + labelName;
}

void gosublabel::changeSize(int new_size)
{
	size = new_size;
}

