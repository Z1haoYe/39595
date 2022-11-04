#include <iostream>
#include <map>
#include <regex>
#include "Stmt.h"
#include "SymbolTable.h"
#include "StringBuffer.h"

prints_::prints_(const std::string& line)
{
	str = (Stmt::matchString(line))[1];
	location = StringBuffer::getcurrLoc();
	StringBuffer::addtoBuffer(str);
	
}

std::string prints_::makeStmt()
{
	return output + " " + std::to_string(location);
}