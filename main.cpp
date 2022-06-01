#include <iostream>
#include "Contact.h"
#include<string>
#include<fstream>
#include<list> //Libreria de c++ para crear listas rapido
#include<vector> //Libreria de c++ para arrays/vectores

using namespace std;

int hashkey(contact); //Funcion parael hash

int main(){
    vector<list<contact>> lista; //Un vector es como un array pero mas dinamico, en c++, al usar librerias como esta, requieren plantilla,
                                //la plantilla no es mas que especificarle de que tipo sera tu objeto, en este caso, declaramos un vector que guarde listas
                                //y las listas guardan objetos de tipo contact (Una clase que yo hice)

    lista.resize(10); //Le especifico que estoy creando 10 listas por asi decirlo, el vector sera de tamaño 10, en cada uno hay una lista

    contact aux; //aux es un objeto al que le agrego los datos para luego meterlos a la lista
    string data;
    ofstream file;
    int i=0;


    do
    {
        cout<<"Ingrese el nombre del usuario: "; getline(cin, data);
        aux.setName(data);
        cout<<"Ingrese el numero del usuario: "; getline(cin, data);
        aux.setNumber(stoi(data)); //stoi, string to int

        lista[hashkey(aux)].push_back(aux); //hashkey obtiene la posicion en el vector, push back es la funcion de la lista para agregar elementos al final
        i++;
        cout<<endl;
    } while (i<10);

    file.open("user_data.txt", ios::out);
    if(file.fail())
    {
        cout<<"Problema al crear al archivo"<<endl;
        exit(1);
    }

    for(i=0; i<10;i++)      //Imprimir y guardar en el archivo
    {
        for(auto it=lista[i].begin(); it!=lista[i].end(); it++)
        {
            aux = *it;
            cout<<i<<" "<<aux.toString()<<endl;
            file<<i<<" " + aux.toString()<<endl;
        }

    }
    system("pause");
    return 0;
}

int hashkey(contact aux){
    int c=0, multiplicador=1;

    for(int i=0; i<aux.getName().length(); i++) //Obtenemos el largo del nombre y se revisa cada caracter
    {
        c+=aux.getName()[i]*multiplicador++;
    }
    c=c%10;
    cout<<"Indice asignado al usuario registrado: "<<c<<endl;
    return c;
}
