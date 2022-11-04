#ifndef STRINGBUFFER_H_
#define STRINGBUFFER_H_
#include <map>
#include <string>
#include <list>
#include "Stmt.h"

class StringBuffer
{
public:
	StringBuffer(const std::string& str_) : str(str_), loc(currLoc)
	{
	}

	
	static void addtoBuffer(const std::string& str_)
	{
		strs.push_back(StringBuffer(str_));
		updateLoc();
	}

	static void updateLoc() { currLoc++; }
	static int getcurrLoc() { return currLoc; }

	static std::list<StringBuffer> strs;

	std::string getStr() { return str; }


private:
	//prints_ obj;
	std::string str;
	int loc;
	static int currLoc;
	
};
#endif /* STRINGBUFFER_H_ */