#include <iostream>
#include <string>
#include "Person.h"

Person::Person(const std::string& _name, int _birthMonth, int _birthDay, int _birthYear, const Address& _address) 
	: name(_name), address(_address)
{ 
   dateOfBirth = std::string(std::to_string(_birthMonth)+"/"+std::to_string(_birthDay)+"/"+std::to_string(_birthYear)); // this should be the only line in the constructor body
}

std::string Person::getRole( ) { 
   return "unknown";
}

std::string Person::getAddress()
{
	return address.getAddress();
}

std::string Person::getName()
{
	return name;
}

int Person::getZipCode()
{
	return address.getZipCode();
}

std::string Person::getDateOfBirth()
{
	return dateOfBirth;
}