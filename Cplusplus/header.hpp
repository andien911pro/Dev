#pragma once
#include <iostream>

constexpr size_t sz = 100;

struct Data
{
    int n;
    int arr[sz];
};

using DATA = Data;

bool primeNumber(int n);
void input (DATA &d);
void output (DATA d);
bool checkIfArrayIsAllPrime(DATA d);

