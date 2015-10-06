#ifndef INDICE_H
#define INDICE_H
#define MAX 20
#include <iostream>
using namespace std;
class Indice
{
public:
    char llave[MAX];
    long int posicion;
public:
    friend ostream&operator<<(ostream& os,Indice &d);
    bool operator==(const Indice &d);
    bool operator<(const Indice &d);
    bool operator<=(const Indice &d);
} indice;
bool Indice::operator==(const Indice &d){
    string obj1,obj2;
    obj1=llave;
    obj2=d.llave;
     return obj1==obj2;
    }
bool Indice::operator<(const Indice &d){
    string obj1,obj2;
    obj1=llave;
     obj2=d.llave;
    return obj1<obj2;
    }
bool Indice::operator<=(const Indice &d){
    string obj1,obj2;
    obj1=llave;
     obj2=d.llave;
    return obj1<=obj2;
    }
ostream& operator<<(ostream& os,Indice &d){
       os<<"-----------------\n";
       os<<"Posicion    :"<<d.posicion<<endl;
       os<<"Llave    :"<<d.llave<<endl;
       os<<"-----------------\n\n";
    return os;
    }
#endif // INDICE_H
