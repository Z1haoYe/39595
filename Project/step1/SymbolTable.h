#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_
#include <map>
#include <string>
#include <list>

enum type_ { labl, va, inte, str };

class SymbolTable
{
public:
	static int getCurrLv() { return currLv; }
	static int getCurrLoc() { return currLoc; }
	SymbolTable(type_ type, std::string& value, int location, int size, int level) : dataType(type), value(value), location(location), size(size), level(level) {}
	static void updateLoc(int size) { currLoc += size; }

	static std::list<SymbolTable> symbols;
	static int getlineNum() { return lineNum; }
	static void updatelineNum() { lineNum++; }
	static int findVar(const std::string& var_)
	{
		std::list<SymbolTable>::reverse_iterator node = symbols.rbegin();
		while (node != symbols.rend())
		{
			if (node->value == var_) return node->location;
			node++;
		}
		return -1;
	}

	static int findVarLv(const std::string& var_)
	{
		std::list<SymbolTable>::reverse_iterator node = symbols.rbegin();
		while (node != symbols.rend())
		{
			if (node->value == var_) return node->level;
			node++;
		}
		return -1;
	}

	static void updateLv() { currLv++; }
	static void decLv() { currLv--; }
	int getLv() { return level; }
	int getSize() { return size; }
	static int labelGetLoc(std::string lab)
	{
		std::list<SymbolTable>::reverse_iterator node = symbols.rbegin();
		while (node != symbols.rend())
		{
			if ((node->value == lab) && (node->dataType == labl)) return node->location;
			node++;
		}
		return -1;
	}
	static int lineNum;

private:
	type_ dataType;
	std::string value;
	int location;
	int size;
	int level;
	
	//SymbolTable* nest;
	

	static int currLv;
	static int currLoc;

	//static bool labelDefined(SymbolTable* head, const std::string line);
};
#endif /* SYMBOLTABLE_H_ */