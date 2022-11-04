#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <list>
#include <stdio.h>
#include "Stmt.h"
#include "SymbolTable.h"
#include "StringBuffer.h"

int main(int argc, char** args)
{
	//std::vector<Stmt> commandlist;

	std::ifstream readFile(args[1]);
	if (!readFile.good())
	{
		std::cout << "error: test file do not exist" << std::endl;
		exit(EXIT_FAILURE);

	}
	start* startObj = nullptr;
	std::string line;
	int endFlag = 0;
	while (getline(readFile, line))
	{
		std::string command = (Stmt::matchString(line)[0]);
		
		int lineOffset = 1;

		if (command == "declscal") { declscal::declScal(line); lineOffset = 0; }
		else if (command == "declarr") { declarr::declArr(line); lineOffset = 0; }
		else if (command == "label") { label_::declLabel(line); lineOffset = 0; }
		else if (command == "gosublabel")
		{
			gosublabel* temp = new gosublabel(line);
			Stmt::stmts.push_back(temp);
			temp->declLabel();
		}
		else if (command == "start")
		{
			startObj = new start();
			Stmt::stmts.push_back(startObj);
		}
		else if (command == "end") 
		{ 
			lineOffset = 0;
			endFlag = 1;
			std::regex format("^(end)(\\s*)$");
			if (!regex_match(line, format))
			{
				std::cout << "error: end followed by non-blank characters" << std::endl;
				exit(-1);
			}
			if (!Stmt::undef.empty())
			{
				std::list<Stmt*>::iterator node = Stmt::undef.begin();
				while (node != Stmt::undef.end())
				{
					(*(*node)).updateLoc();
					node = (Stmt::undef).erase(node);
				}

			}
			if (getline(readFile, line))
			{
				std::cout << "error: code encountered after an end statement" << std::endl;
				exit(EXIT_FAILURE);

			}


		}
		else if (command == "exit") Stmt::stmts.push_back(new exit_());
		else if (command == "jump") Stmt::stmts.push_back(new jump(line));
		else if (command == "jumpzero") Stmt::stmts.push_back(new jumpzero(line));
		else if (command == "jumpnzero") Stmt::stmts.push_back(new jumpnzero(line));
		else if (command == "gosub") Stmt::stmts.push_back(new gosub(line));
		else if (command == "return")
		{
			return_::findSize_clean();
			Stmt::stmts.push_back(new return_());
		}
		else if (command == "pushscal") Stmt::stmts.push_back(new pushscal(line));
		else if (command == "pusharr") Stmt::stmts.push_back(new pusharr(line));
		else if (command == "pushi") Stmt::stmts.push_back(new pushi(line));
		else if (command == "pop") Stmt::stmts.push_back(new pop());
		else if (command == "popscal") Stmt::stmts.push_back(new popscal(line));
		else if (command == "poparr") Stmt::stmts.push_back(new poparr(line));
		else if (command == "dup") Stmt::stmts.push_back(new dup());
		else if (command == "swap") Stmt::stmts.push_back(new swap());
		else if (command == "add") Stmt::stmts.push_back(new add());
		else if (command == "negate") Stmt::stmts.push_back(new negate());
		else if (command == "mul") Stmt::stmts.push_back(new mul());
		else if (command == "div") Stmt::stmts.push_back(new div_());
		else if (command == "printtos") Stmt::stmts.push_back(new printtos());
		else if (command == "prints") Stmt::stmts.push_back(new prints_(line));
		else
		{
			std::cout << "error: wrong command" << std::endl;
			exit(EXIT_FAILURE);		
		}

		SymbolTable::lineNum += lineOffset;

		


	
	}
	
	if (!endFlag)
	{
		std::cout << "error: no end statement in program" << std::endl;
		exit(EXIT_FAILURE);

	}

	std::string outputName = std::string(args[1]) + ".pout";
	std::ofstream out(outputName);

	if (!StringBuffer::strs.empty())
	{
		std::list<StringBuffer>::iterator node = StringBuffer::strs.begin();
		while (node != StringBuffer::strs.end())
		{
			//(*(*node)).updateLoc();
			std::string output = node->getStr();
			std::cout << output << std::endl;
			out << output << std::endl;
			node++;
		}

	}
	
	startObj->changeSize(startObj->getStartSize());

	
	if (!Stmt::stmts.empty())
	{
		std::list<Stmt*>::iterator node = Stmt::stmts.begin();
		while (node != Stmt::stmts.end())
		{
			std::string output = (**node).makeStmt();
			std::cout << output << std::endl;
			out << output << std::endl;
			delete(*node);
			node++;
			
		}

	}

}