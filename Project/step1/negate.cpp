#include <iostream>
#include <map>
#include <regex>
#include "Stmt.h"
#include "SymbolTable.h"

negate::negate() {}

std::string negate::makeStmt()
{
	return output;
}