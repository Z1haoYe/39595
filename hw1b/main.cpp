#include <iostream>
#include "Automobile.h"

int main(int argc, char* argv[]) {
    Automobile* auto1 = new Automobile(1, 85992.56, 12, 16, 1);
    std::cout << auto1 -> toString();

    Automobile* auto2 = new Automobile(2, 78492.79, 2, 8, 2);
    std::cout << auto2 -> toString();

    delete auto1;
    delete auto2;

    return EXIT_SUCCESS;
}
