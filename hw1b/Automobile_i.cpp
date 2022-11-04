#include <string>
#include "Automobile.h"

Automobile::Automobile(int _id, float _mile, int mm, int dd, int yy)
{
	id = _id;
	mile = _mile;
	maintenance = "" + std::to_string(mm) + "/" + std::to_string(dd) + "/" + std::to_string(yy);
}

int Automobile::getId()
{
	return id;
}

float Automobile::getMile()
{
	return mile;
}

std::string Automobile::getMaintenance()
{
	return maintenance;
}

std::string Automobile::toString()
{
	std::string autos = "Vehicle Identification Number: " + std::to_string(id) + "\n";
	autos += "Miles Driven: " + std::to_string(mile) + "\n";
	autos += "Lastest Maintenace: " + maintenance + "\n";
	return autos;
}
