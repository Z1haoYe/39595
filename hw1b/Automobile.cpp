#include <string>
#include "Automobile.h"

Automobile::Automobile(int _id, float _mile, int _mm, int _dd, int _yy)
{
	id = _id;
	mile = _mile;
	mm = _mm;
	dd = _dd;
	yy = _yy;
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
	std::string maintenance = "" + std::to_string(mm) + "/" + std::to_string(dd) + "/" + std::to_string(yy);
	return maintenance;
}

std::string Automobile::toString()
{
	std::string autos = "Vehicle Identification Number: " + std::to_string(id) + "\n";
	autos += "Miles Driven: " + std::to_string(mile) + "\n";
	autos += "Lastest Maintenace: " + getMaintenance() + "\n";
	return autos;
}
