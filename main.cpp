#include <iostream>
#include "numerus.h"

using namespace std;

int main()
{

    std::vector<int> vect(0);
    vect.push_back(1);
    vect.push_back(8);

    Numerus sao(0), an(1), dwa(2), fra(3), rah(4), shi(5), phi(6), pia(7);
    cout << pia << " * " << pia << " = ";
    Numerus neo(0);
    neo = pia * pia;
    cout << neo << endl;

    return 0;
}
