#include "Contact.h"
#include <string>

contact::contact(){}
contact::contact(string _name, int _number) : name(_name),number(_number){}

string contact::getName(){return name;}
int contact::getNumber(){return number;}
void contact::setName(string _name){name=_name;}
void contact::setNumber(int _number){number=_number;}

string contact::toString(){
    return "\nNombre: " + name + "\nNumero: " + to_string(number);
}

