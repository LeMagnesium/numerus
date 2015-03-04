/* Numerus ex machina */

#ifndef NUMERUS_H_INCLUDED
#define NUMERUS_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

class Numerus
{
public:
    Numerus(int init_number = 0);
    Numerus(long init_numbers);
    Numerus(std::vector<int> init_array);
    Numerus(Numerus const& a);
    ~Numerus();
    void init(long init_numbers);
    Numerus& operator+=(Numerus const& to_add);
    Numerus& operator-=(Numerus const& to_add);
    Numerus& operator*=(Numerus const& to_add);
    Numerus& operator/=(Numerus const& to_add); /// WIP
    int size() const;

private:

    void check();
    bool isCorrect() const;
    int operator[](int num) const;

    std::vector<int> numbers;

    friend std::ostream &operator<<(std::ostream &flux, Numerus const& numere);
    friend bool operator< (Numerus const& a, Numerus const& b);
    friend bool operator> (Numerus const& a, Numerus const& b);
    friend bool operator==(Numerus const& a, Numerus const& b);
};

std::ostream &operator<<(std::ostream &flux, Numerus const& numere);
Numerus operator+ (Numerus const& a, Numerus const& b);
Numerus operator- (Numerus const& a, Numerus const& b);
Numerus operator* (Numerus const& a, Numerus const& b);
Numerus operator/ (Numerus const& a, Numerus const& b); /// WIP
bool operator< (Numerus const& a, Numerus const& b);
bool operator<=(Numerus const& a, Numerus const& b);
bool operator> (Numerus const& a, Numerus const& b);
bool operator>=(Numerus const& a, Numerus const& b);
bool operator==(Numerus const& a, Numerus const& b);
bool operator!=(Numerus const& a, Numerus const& b);

#endif // NUMERUS_H_INCLUDED
