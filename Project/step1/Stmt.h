#ifndef STMT_H_
#define STMT_H_
#include <iostream>
#include <map>
#include <regex>
#include <vector>
#include <list>
class Stmt
{
	//typedef Stmt* (*func)(const std::string& line);

	/*
	static Stmt* createObj(const std::string& line)
	{
		std::vector<std::string> substr = matchString(line);

		stmtFac[substr[0]](line);
	}


	static void initFactory()
	{
		stmtFac["declscal"] = declscal::declScal;


	}
	*/

public:
	static std::vector<std::string> matchString(const std::string& line)
	{
		std::regex words_regex("[\\S]+");
		auto words_begin = std::sregex_iterator(line.begin(), line.end(), words_regex);
		auto words_end = std::sregex_iterator();

		int count = (int)std::distance(words_begin, words_end);
		std::vector <std::string> list;
		std::sregex_iterator iter = words_begin;

		for (int i = 0; i < count; i++)
		{
			std::smatch match = *iter;
			list.push_back(match.str());
			iter++;
		}

		return list;
	}

	//Stmt* next;
	static std::list<Stmt*> undef;
	static std::list<Stmt*> stmts;
	virtual void vf() {}
	virtual std::string makeStmt() { return "default"; }
	virtual void updateLoc() {};
	virtual ~Stmt() {}
	

private:
	//static std::map<std::string, func> stmtFac;

	//static Stmt* stmtList;
	
	

protected:
	std::string stmt;
	
	
};


class declscal : public Stmt
{
public:
	static void declScal(const std::string& line);	//add to symbol table, storage ++
	declscal();
private:
	std::string input = "declscal";
	std::string var_;
	
};

class declarr : public Stmt
{
public:
	static void declArr(const std::string& line);	//add to symbol table, storage + length
	declarr();
private:
	std::string input = "declarr";
	std::string var_;
	//int length;
	
};

class label_ : public Stmt
{
public:
	static void declLabel(const std::string& line);
	label_();
private:
	std::string input = "label";
	std::string labelName;
	
	//add to symbol table
};

class gosublabel : public Stmt
{
public:
	std::string makeStmt();
	//void changeSize();
	void changeSize(int new_size);
	void declLabel();
	gosublabel(const std::string& line);

private:
	std::string input = "gosublabel";
	std::string output = "gosublabel";
	std::string labelName;
	int size;
	
	//add to table
	//level ++
	
	
};

class start : public Stmt
{
public:
	int getStartSize();
	std::string makeStmt();
	void changeSize(int);
	start();
private:
	std::string input = "start";
	std::string output = "Start";
	int size = -1;
};

class end : public Stmt
{
public:
private:
	std::string input = "end";
};

class exit_ : public Stmt
{
public:
	exit_();
	std::string makeStmt();
private:
	std::string input = "exit";
	std::string output = "Exit";
	
};

class jump : public Stmt
{
public:
	jump(const std::string& line);
	void updateLoc();
	std::string makeStmt();
private:
	std::string input = "jump";
	std::string output = "Jump";
	std::string label;
	int labelLoc;
	
	
};

class jumpzero : public Stmt
{
public:
	jumpzero(const std::string& line);
	void updateLoc();
	std::string makeStmt();

private:
	std::string input = "jumpzero";
	std::string output = "JumpZero";
	std::string label;
	int labelLoc;
};

class jumpnzero : public Stmt
{
public:
	jumpnzero(const std::string& line);
	void updateLoc();
	std::string makeStmt();
private:
	std::string input = "jumpnzero";
	std::string output = "JumpNZero";
	std::string label;
	int labelLoc;
	
};

class gosub : public Stmt
{
public:
	gosub(const std::string& line);
	void updateLoc();
	std::string makeStmt();
private:
	std::string input = "gosub";
	std::string output = "GoSub";
	std::string label;
	int labelLoc;
	
};

class return_ : public Stmt
{
public:
	static gosublabel* find_gosub();
	static void findSize_clean();
	std::string makeStmt();
private:
	std::string input = "return";
	std::string output = "Return";
	std::string size;
	

};

class pushscal : public Stmt
{
public:
	pushscal(const std::string& line);

	std::string makeStmt();
private:
	std::string input = "pushscal";
	std::string output = "PushScalar";
	std::string var_;
	int loc;
	
};

class pusharr : public Stmt
{
public:
	pusharr(const std::string& line);
	std::string makeStmt();
private:
	std::string input = "pusharr";
	std::string output = "PushArray";
	std::string var_;
	int loc;
	
};

class pushi : public Stmt
{
public:
	pushi(const std::string& line);
	std::string makeStmt();
private:
	std::string input = "pushi";
	std::string output = "PushI";
	int intVal;
	
};

class pop : public Stmt
{
public:
	pop();
	std::string makeStmt();
private:
	std::string input = "pop";
	std::string output = "Pop";
	
};

class popscal : public Stmt
{
public:
	popscal(const std::string& line);
	std::string makeStmt();
private:
	std::string input = "popscal";
	std::string output = "PopScal";
	std::string var_;
	int loc;
	
};

class poparr : public Stmt
{
public:
	poparr(const std::string& line);
	std::string makeStmt();
private:
	std::string input = "poparr";
	std::string output = "PopArray";
	std::string var_;
	int loc;
	
};

class dup : public Stmt
{
public:
	dup();
	std::string makeStmt();
private:
	std::string input = "dup";
	std::string output = "Dup";
	
};

class swap : public Stmt
{
public:
	swap();
	std::string makeStmt();
private:
	std::string input = "swap";
	std::string output = "Swap";
	
};

class add : public Stmt
{
public:
	add();
	std::string makeStmt();
private:
	std::string input = "add";
	std::string output = "Add";
	
};

class negate : public Stmt
{
public:
	negate();
	std::string makeStmt();
private:
	std::string input = "negate";
	std::string output = "Negate";
	
};

class mul : public Stmt
{
public:
	mul();
	std::string makeStmt();
private:
	std::string input = "mul";
	std::string output = "Mul";
	
};

class div_ : public Stmt
{
public:
	div_();
	std::string makeStmt();
private:
	std::string input = "div";
	std::string output = "Div";
	
};

class printtos : public Stmt
{
public:
	printtos();
	std::string makeStmt();
private:
	std::string input = "printtos";
	std::string output = "PrintTOS";
	
};

class prints_ : public Stmt
{
public:
	prints_(const std::string& line);
	std::string makeStmt();
private:
	std::string input = "prints";
	std::string output = "Prints";
	std::string str;
	int location;
	
};


#endif /* STMT_H_ */