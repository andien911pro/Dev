#include "header.hpp"
#include <iostream>

bool primeNumber(int n)
{
    int cnt = 0;
    if (n <= 2)
        return 0;
    for (int i = 2; i <= n / 2; ++i)
        if (n % i == 0)
            ++cnt;
    if (cnt > 0)
        return 0;
    return 1;
}

void input(DATA &d)
{
    do
    {
        std::cout << "Enter number of elements: ";
        std::cin >> d.n;
    } while (d.n < 0 || d.n > 100);

    for (int i = 0; i != d.n; ++i)
    {
        std::cout << "Enter arr[" << i << "]: ";
        std::cin >> d.arr[i];
    }
}

void output (DATA d)
{
    for (int i = 0; i != d.n; ++i)
        std::cout << "arr[" << i << "]: " << d.arr[i] << std::endl;
}

bool checkIfArrayIsAllPrime(DATA d)
{
    for (int i = 0; i != d.n; ++i)
        if (!primeNumber(d.arr[i]))
            return 0;
    return 1;
}
