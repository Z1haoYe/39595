#include <iostream>
#include "Staticy.h"

int Staticy::count = 0;

Staticy::Staticy(int i)
{
	if (i % 2 == 0) count++;
}

Staticy* Staticy::makeStaticy(int i)
{
	return new Staticy(i);
}

int Staticy::getEvenCount()
{
	return count;
}