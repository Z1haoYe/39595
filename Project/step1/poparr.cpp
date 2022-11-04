#include <iostream>
#include <map>
#include <regex>
#include "Stmt.h"
#include "SymbolTable.h"

poparr::poparr(const std::string& line)
{
	var_ = (matchString(line))[1];
	loc = SymbolTable::findVar(var_);
}

std::string poparr::makeStmt()
{
	return output + " " + std::to_string(loc);
}