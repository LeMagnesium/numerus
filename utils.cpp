/*
    Useful functions for Numerus' class
    CopyRight Mg 2015
    License GPLv3
*/

#include <iostream>
#include <string>
#include <vector>
#include "numerus.h"

std::vector<int> Numerus::reverseArray(std::vector<int> &normal_array)
{
    std::vector<int> returned(0);
    for (unsigned int i = normal_array.size();i > 0;i--)
    {
        returned.push_back(normal_array[i-1]);
    }
    return returned;
}

Numerus pow(Numerus const& a, Numerus const& b)
{
    Numerus iter(b), me(a), copie(me);
    if (b == 0) {me.init(1);}

    for (;iter > 1;iter -= 1)
    {
        me *= copie;
    }

    return me;
}

int Numerus::getIntRow(int const& a, int const& b)
{
    if (b < 0 || Numerus::getIntSize(a)-1 < b) return 0;

    int copa(a);
    for (int i = 0; i < b; i++)
    {
        copa-=(copa%10);
        copa/=10;
    }
    return copa%10;
}

int Numerus::getIntSize(int const& a)
{
    int copa(a),iter(0);
    while (copa > 0)
    {
        copa-=(copa%10);
        copa/=10;
        iter++;
    }
    return iter;
}
