/*

    NUMERUS file containing
    definition of comparison operators

    CopyRight Mg 2015
    License GPLv3
*/


#include <iostream>
#include <vector>
#include <string>

#include "numerus.h"

using namespace std;

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
