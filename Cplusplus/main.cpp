#include "header.hpp"
#include <iostream>

int main()
{
    DATA d;
    input(d);
    output(d);
    if (checkIfArrayIsAllPrime(d))
        std::cout << "Array is prime!!";
    else
        std::cout << "Array is not prime";
    std::cout << std::endl;
}
