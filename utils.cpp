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
