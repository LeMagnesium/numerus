// Programm ßý Mg
/*
    Implementation of the numerus class
    Copyright 2015 (c) Mg, <insert real name here>
    License GPLv3
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "numerus.h"

using namespace std;

/// Constructeur (int) (wrapper)
Numerus::Numerus(int init_number)
{
    init(init_number);
}

/// Constructeur (long)
Numerus::Numerus(long init_number)
{
    init(init_number);
}

/// Initialisation (long)
void Numerus::init(long init_number)
{
    if (Numerus::checkIntegrityOfNumber(init_number,false) == false)
    {
        init_number = 0;
    }

    //#0 Destruction du tableau
    for (int i = numbers.size()-1; i >= 0; i--)
    {
        numbers.pop_back();
    }

    //#1 Trouver le rang du nombre et créer le tableau
    int rang = 0;
    do
    {
        numbers.push_back(0);
        rang++;
    }
    while(init_number >= pow(10,rang));

    //#2 Copier les nombres dans le tableau
    int i = 0;
    do
    {
        int numAt = init_number%10;
        init_number -= numAt;
        init_number /= 10;
        numbers[i++] = numAt;
    }
    while (init_number > 0);

    // Check integrity of number
    check();
}

/// Constructeur (std::vector<int>)
Numerus::Numerus(std::vector<int> init_array)
{
    init(init_array);
}

/// Init with std::vector<int>
void Numerus::init(std::vector<int> init_array)
{
    if (Numerus::checkIntegrityOfNumber(init_array) == false) {init(0);return;}
    int rang(0);
    for (int i = init_array.size()-1; i >= 0; i--, rang++)
    {
        numbers.push_back(0);
        numbers[rang] = init_array[i];
    }

    // Check integrity of number
    check();
}

/// Constructeur de copie (Numerus const&)
Numerus::Numerus(Numerus const& a): numbers(a.numbers)
{
    ;
}

/// Destructeur ()
Numerus::~Numerus()
{
    ;
}

/// Opérateur <<
std::ostream &operator<<(std::ostream &flux, Numerus const& numere)
{
    for (int i = numere.numbers.size()-1; i >= 0; i--)
    {
        flux << numere.numbers[i];
    }
    return flux;
}

/// Opérateur +=
Numerus& Numerus::operator+=(Numerus const& a_add)
{

    Numerus to_add(a_add);

    // Equalizing
    for (int i = to_add.numbers.size()-numbers.size(); i > 0; i--)
    {
        numbers.push_back(0);
    }

    // Equalizing
    for (int i = numbers.size()-to_add.numbers.size(); i > 0; i--)
    {
        to_add.numbers.push_back(0);
    }

    // Adding
    for (int j = numbers.size()-1; j >= 0 ; j--)
    {
        numbers[j] += to_add.numbers[j];
    }

    // Check integrity of number
    check();

    return *this;
}

/// Opérateur -=
Numerus& Numerus::operator-=(Numerus const& a_sub)
{
    if (a_sub > *this)
    {
        ///FIXME I'm not mathematically logic
        return *this;
    }
    Numerus to_add(a_sub);

    // Equalizing
    for (int i = to_add.numbers.size()-numbers.size(); i > 0; i--)
    {
        numbers.push_back(0);
    }

    // Equalizing
    for (int i = numbers.size()-to_add.numbers.size(); i > 0; i--)
    {
        to_add.numbers.push_back(0);
    }

    // Substracting
    for (int j = numbers.size()-1; j >= 0 ; j--)
    {
        numbers[j] -= to_add.numbers[j];
    }

    // Check integrity of number
    check();

    return *this;
}
/// Check
void Numerus::check()
{
    while (!isCorrect())
    {
        for (unsigned int j = 0; j < numbers.size(); j++)
        {
            while (numbers.size() > 1 && numbers[numbers.size()-1] == 0)
            {
                numbers.pop_back();
            }
            while (numbers[j] < 0)
            {
                if (j+1 == numbers.size()) // END OF TABLE
                {
                    init(0);
                    return;
                }
                numbers[j+1]--;
                numbers[j]+=10;
            }
            while (numbers[j] > 9)
            {
                if (j+1 == numbers.size()) // END OF TABLE
                {
                    numbers.push_back(0);
                }
                numbers[j+1]++;
                numbers[j]-=10;
            }
        }
    }
}

/// is numerus correct?
bool Numerus::isCorrect() const
{
    // Check negative ones
    for (unsigned int a = 0; a < numbers.size(); a++)
    {
        if (numbers[a] < 0) return false;
    }

    // Check too-high-ish ones
    for (unsigned int b = 0; b < numbers.size(); b++)
    {
        if (numbers[b] > 9) return false;
    }

    // Check for too large table
    if (numbers.size() > 1 && numbers[numbers.size()-1] == 0) return false;

    return true;
}

/// Adding
Numerus operator+ (Numerus const& a, Numerus const& b)
{
    Numerus copie(a);
    copie+=b;
    return copie;
}

/// Size
int Numerus::size() const
{
    return numbers.size();
}

/// Opérateur [int]
int Numerus::operator[](int num) const
{
    return numbers[num];
}

/// Opérateur <
bool operator< (Numerus const& a, Numerus const& b)
{
    int compa(0), compb(0);
    for (int i = 0; i < max(a.size(),b.size()); i++)
    {
        if (a.size() <= i)
        {
            compa = 0;
        }
        else
        {
            compa = a[i];
        }
        if (b.size() <= i)
        {
            compb = 0;
        }
        else
        {
            compb = b[i];
        }

        if (compa >= compb) return false;
    }
    return true;
}

/// Opérateur <=
bool operator<=(Numerus const& a, Numerus const& b)
{
    return (a < b || a == b);
}

/// Opérateur >=
bool operator>=(Numerus const& a, Numerus const& b)
{
    return (a > b || a == b);
}

/// Opérateur >
bool operator> (Numerus const& a, Numerus const& b)
{
    int compa(0), compb(0);
    for (int i = 0; i < max(a.size(),b.size()); i++)
    {
        if (a.size() <= i)
        {
            compa = 0;
        }
        else
        {
            compa = a[i];
        }
        if (b.size() <= i)
        {
            compb = 0;
        }
        else
        {
            compb = b[i];
        }

        if (compa <= compb) return false;
    }
    return true;
}

/// Opérateur ==
bool operator==(Numerus const& a, Numerus const& b)
{
    int compa(0), compb(0);
    for (int i = 0; i < max(a.size(),b.size()); i++)
    {
        if (a.size() <= i)
        {
            compa = 0;
        }
        else
        {
            compa = a[i];
        }
        if (b.size() <= i)
        {
            compb = 0;
        }
        else
        {
            compb = b[i];
        }

        if (compa != compb) return false;
    }
    return true;
}

/// Opérateur !=
bool operator!=(Numerus const& a, Numerus const& b)
{
    return !(a == b);
}

/// Opérateur -
Numerus operator- (Numerus const& a, Numerus const& b)
{
    Numerus copie(a);
    copie-=b;
    return copie;
}

/// Opérateur *=
Numerus& Numerus::operator*=(Numerus const& a)
{
    Numerus to_add(a);

    // Equalizing
    for (int i = to_add.numbers.size()-numbers.size(); i > 0; i--)
    {
        numbers.push_back(0);
    }

    // Equalizing (other side)
    for (int i = numbers.size()-to_add.numbers.size(); i > 0; i--)
    {
        to_add.numbers.push_back(0);
    }

    // Multiplying
    for (int j = numbers.size()-1; j >= 0 ; j--)
    {
        int total(0);
        for (unsigned int i = 0;i < numbers.size();i++)
        {
            total += (numbers[j] * to_add.numbers[i]) * pow(10,i);
        }
        numbers[j] = total;
    }

    // Check integrity of number
    check();

    return *this;
}

/// Opérateur *
Numerus operator* (Numerus const& a, Numerus const& b)
{
    Numerus copie(a);
    copie*=b;
    return copie;
}

/// CHECK INTEGRITY OF GIVEN NUMBER
// A number is considered as non-acceptable when it is :
// - smaller than 0 (negative)
// - greater than 9 (for row initialization)
// - contains a number which complete one the statements above (vectors)
//

bool Numerus::checkIntegrityOfNumber(std::vector<int> to_check)
{
    for (unsigned int i = 0; i < to_check.size(); i++)
        if (Numerus::checkIntegrityOfNumber(to_check[i],true) == false) {return false;}

    return true;
}

template<typename T> bool Numerus::checkIntegrityOfNumber(T to_check, bool isRow)
{
    /// Check the conditions

    // #1 : Lesser than 0
    if (to_check < 0) return false;

    if (isRow)
    {
        // #2 : Greater than 9
        if (to_check > 9) return false;
    }

    return true;
}

/// Operator %=
Numerus& Numerus::operator%=(Numerus const& to_mod)
{
    while (to_mod <= *this) {*this+=to_mod;}
    return *this;
}

/// Opérateur %
Numerus operator% (Numerus const& a, Numerus const& b)
{
    Numerus copie(a);
    copie%=b;
    return copie;
}

/// Operator += using int
Numerus& Numerus::operator+=(int const& a)
{
    Numerus tmp(a);
    *this+=tmp;
    return *this;
}

/// Operator + using int
Numerus operator+ (Numerus const& a, int const& b)
{
    Numerus copie(a);
    copie+=b;
    return copie;
}
