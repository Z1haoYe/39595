#include "SymbolTable.h"

int SymbolTable::lineNum = 0;
int SymbolTable::currLv = 0;
int SymbolTable::currLoc = 0;
std::list<SymbolTable> SymbolTable::symbols;

