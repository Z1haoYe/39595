#include <iostream>
#include <map>
#include <regex>
#include "Stmt.h"
#include "SymbolTable.h"

jump::jump(const std::string& line)
{
	label = (Stmt::matchString(line))[1];

	//if (!SymbolTable::labelDefined(line))labelLoc = -1;
	labelLoc = SymbolTable::labelGetLoc(label);
	if (labelLoc == -1) Stmt::undef.push_back(this);
}

void jump::updateLoc()
{
	labelLoc = SymbolTable::labelGetLoc(label);
}

std::string jump::makeStmt()
{
	return output + " " + std::to_string(labelLoc);
}