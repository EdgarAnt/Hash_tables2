#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED
#include <iostream>

using namespace std;

class contact{
    private:
        string name;
        int number;
    public:
        contact();
        contact(string, int);

        string getName();
        int getNumber();

        string toString();

        void setName(string);
        void setNumber(int);
};

#endif // CONTACT_H_INCLUDED
