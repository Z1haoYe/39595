#include <iostream>
#include <map>
#include <regex>
#include "Stmt.h"
#include "SymbolTable.h"

popscal::popscal(const std::string& line)
{
	var_ = (matchString(line))[1];
	loc = SymbolTable::findVar(var_);
}

std::string popscal::makeStmt()
{
	return output + " " + std::to_string(loc);
}