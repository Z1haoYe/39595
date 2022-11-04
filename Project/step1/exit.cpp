#include <iostream>
#include <map>
#include <regex>
#include "Stmt.h"
#include "SymbolTable.h"

exit_::exit_() {}

std::string exit_::makeStmt()
{
	return output;
}