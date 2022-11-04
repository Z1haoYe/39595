#ifndef AUTO_H_
#define AUTO_H_

#include <string>

class Automobile {
private:
	int id;
	float mile;
	int mm;
	int dd;
	int yy;
	//std::string maintenance;

public:
	Automobile(int _id, float _mile, int mm, int dd, int yy);
	int getId();
	float getMile();
	std::string getMaintenance();
	std::string toString();
};
#endif
