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
    for (int i = max(a.size(),b.size())-1;i >= 0; i--)
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
        if (compa != compb) return (compa < compb?true:false);
    }
    return false;
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
    for (int i = max(a.size(),b.size())-1;i >= 0; i--)
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
        if (compa != compb) return (compa > compb?true:false);
    }
    return false;
}

/// Opérateur ==
bool operator==(Numerus const& a, Numerus const& b)
{
    int compa(0), compb(0);
    for (int i = 0; i < max(a.size(),b.size()); i++)
    {
        if (a.size() <= i) {compa = 0;}
        else {compa = a[i];
        if (b.size() <= i) {compb = 0;}
        else {compb = b[i];}

        if (compa != compb) return false;
    }
    return true;
}

/// Opérateur !=
bool operator!=(Numerus const& a, Numerus const& b)
{
    return !(a == b);
}

/// Operator < using integer
bool operator< (Numerus const& a, int const& b)
{
    int compa(0), compb(0);
    for (int i = max(a.size(),Numerus::getIntSize(b)-1)-1;i >= 0; i--)
    {
        if (a.size() <= i)
        {
            compa = 0;
        }
        else
        {
            compa = a[i];
        }
        compb = Numerus::getIntRow(b,i);

        if (compa != compb) return (compa < compb?true:false);
    }
    return false;
}

/// Operator > using integer
bool operator> (Numerus const& a, int const& b)
{
    int compa(0), compb(0);
    for (int i = max(a.size(), Numerus::getIntSize(b)-1)-1;i >= 0; i --)
    {
        if (a.size() <= i)
        {
            compa = 0;
        }
        else
        {
            compa = a[i];
        }
        compb = Numerus::getIntRow(b,i);

        if (compa != compb) return (compa > compb?true:false);
    }
    return false;
}

/// Operator <= using integer
bool operator<=(Numerus const& a, int const& b)
{
    return (a < b || a == b);
}

/// Operator >= using integer
bool operator>=(Numerus const& a, int const& b)
{
    return (a > b || a == b);
}

/// Operator == using integer
bool operator==(Numerus const& a, int const& b)
{
    int copa(0), copb(0);
    for (int i = max(a.size(),Numerus::getIntSize(b)-1)-1;i >= 0;i--)
    {
        if (a.size() >= i) {copa = 0;}
        else copa = a[i];
        copb = Numerus::getIntRow(b,i);
        if (!copa == copb) return false;
    }
    return true;
}

/// Operator != using integer
bool operator!=(Numerus const& a, int const& b)
{
    return !(a == b);
}
