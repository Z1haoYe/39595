#include <iostream>
#include <map>
#include <regex>
#include "Stmt.h"
#include "SymbolTable.h"

jumpzero::jumpzero(const std::string& line)
{
	label = (Stmt::matchString(line))[1];

	labelLoc = SymbolTable::labelGetLoc(label);
	if (labelLoc == -1) Stmt::undef.push_back(this);
}

void jumpzero::updateLoc()
{
	labelLoc = SymbolTable::labelGetLoc(label);
}

std::string jumpzero::makeStmt()
{
	return output + ", " + std::to_string(labelLoc);
}