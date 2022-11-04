#include <iostream>
#include <map>
#include <regex>
#include "Stmt.h"
#include "SymbolTable.h"

pushi::pushi(const std::string& line)
{
	std::regex format("^(pushi)(\\s+)[0-9]{1,16}$");
	if (!regex_match(line, format))
	{
		std::cout << "error:pushi format dnm" << std::endl;
		exit(-1);
	}

	intVal = stoi(Stmt::matchString(line)[1]);
}

std::string pushi::makeStmt()
{
	return output + " " + std::to_string(intVal);
}