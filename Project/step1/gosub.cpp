#include <iostream>
#include <map>
#include <regex>
#include "Stmt.h"
#include "SymbolTable.h"

gosub::gosub(const std::string& line)
{
	label = (Stmt::matchString(line))[1];

	labelLoc = SymbolTable::labelGetLoc(label);
	if (labelLoc == -1) Stmt::undef.push_back(this);
}

void gosub::updateLoc()
{
	labelLoc = SymbolTable::labelGetLoc(label);
}

std::string gosub::makeStmt()
{
	return output + ", " + std::to_string(labelLoc);
}