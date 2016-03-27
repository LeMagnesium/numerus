// Programm ßý Mg
/*
    Example of code using numerus class
    to do mathematics with quite big
    numbers
    Copyright 2015 (c) Mg, <insert real name here>
    License : GPLv3
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "numerus.h"

using namespace std;

/// Functions
void generateNumbers(std::vector<int> &vect, int limit);

int main()
{
    srand(time(NULL));

    Numerus * operand1(0), * operand2(0), * result(0);
    operand1 = new Numerus(0);
    operand2 = new Numerus(0);
    result = new Numerus(0);

    std::vector<int> res(0),domus(0);

    /// Addition
    generateNumbers(res, 10);
    generateNumbers(domus, 3);
    operand1->init(res); operand2->init(domus);
    cout << "Add:: ";
    cout << *operand1 << " + " << *operand2 << " = ";
    *result = *operand1 + *operand2;
    cout << *result << endl;

    /// Subtraction
    generateNumbers(res, 10);
    generateNumbers(domus, 3);
    operand1->init(res); operand2->init(domus);

    cout << "Sub:: ";
    cout << *operand1 << " - " << *operand2 << " = ";
    *result = *operand1 - *operand2;
    cout << *result << endl;

    /// Multiplication
    generateNumbers(res, 10);
    generateNumbers(domus, 3);
    operand1->init(res); operand2->init(domus);

    cout << "Mul:: ";
    cout << *operand1 << " * " << *operand2 << " = ";
    *result = *operand1 * *operand2;
    cout << *result << endl;

    /// Modulo
    operand1->init(10);
    operand2->init(3);
    *result = *operand1 % *operand2;

    cout << "Mod:: ";
    cout << *operand1 << " % " << *operand2 << " = " << *result << endl;

    /// Euclidean division
    operand1->init(10);
    operand2->init(3);
    *result = Numerus::euclidean(*operand1, *operand2);

    cout << "Euc:: ";
    cout << *operand1 << " ^ " << *operand2 << " = " << *result << endl;

    /// += using int
    operand1->init(78);
    int a = 9;
    *result = *operand1 + a;
    cout << "Adt:: ";
    cout << *operand1 << " + " << a << " = " << *result << endl;

    /// Power
    operand1->init(3);
    operand2->init(4);
    *result = pow(*operand1,*operand2);
    cout << "Pow:: ";
    cout << "pow(" << *operand1 << ", " << *operand2 << ") = " << *result << endl;

    /// Greater than
    operand1->init(8);
    operand2->init(10);
    cout << "Grt:: ";
    cout << *operand1 << " > " << *operand2 << " => " << (*operand1 > *operand2) << endl;

    /// Smaller than
    operand1->init(3);
    operand2->init(10);
    cout << "Smt:: ";
    cout << *operand1 << " < " << *operand2 << " => " << (*operand1 < *operand2) << endl;

    /// Utils : Get integer row and get integer size
    int d(rand()%100000), e(rand()%5);
    cout << "GIT:: ";
    cout << d << " #" << e << " => " << Numerus::getIntRow(d,e) << endl;
    cout << "GIS:: ";
    cout << "Size of " << d << " => " << Numerus::getIntSize(d) << endl;

    /// Liberate memory
    delete operand1;
    delete operand2;
    operand1 = operand2 = 0;

    return 0;
}

/// Create a list of random numbers in a vector
void generateNumbers(std::vector<int> &vect, int limit)
{
    for (int i = vect.size()-1;i >= 0;i--) {vect.pop_back();}
    for (int i = 0;i < limit;i++)
    {
        vect.push_back(rand() % 10);
    }
}
