#ifndef NODOSECUNDARIO_H
#define NODOSECUNDARIO_H
#include<iostream>
#include "Nododoble.h"
using namespace std;
class Nodosecundario
{
   public:
    char extension[20];
    char compuesta[20];
    NodoDoble<Nodosecundario>* sigNodo;
   public:
    friend ostream&operator<<(ostream& os,Nodosecundario &d);
    bool operator==(const Nodosecundario &d);
    bool operator<(const Nodosecundario &d);
    bool operator<=(const Nodosecundario &d);
    bool operator!=(const Nodosecundario &d);
} nodosecundario;
bool Nodosecundario::operator==(const Nodosecundario &d){
    string obj1,obj2;
    obj1=extension;
    obj2=d.extension;
     return obj1==obj2;
    }
bool Nodosecundario::operator<(const Nodosecundario &d){
    string obj1,obj2;
    obj1=extension;
     obj2=d.extension;
    return obj1<obj2;
    }
bool Nodosecundario::operator<=(const Nodosecundario &d){
    string obj1,obj2;
    obj1=extension;
     obj2=d.extension;
    return obj1<=obj2;
    }
ostream& operator<<(ostream& os,Nodosecundario &d){
       os<<"\n-----------------\n";
       os<<"compuesta       :"<<d.compuesta<<endl;
       os<<"siguientenodo   :"<<d.sigNodo<<endl;
       os<<"extension       :"<<d.extension<<endl;
       os<<"-----------------\n\n";
    return os;
    }
bool Nodosecundario::operator!=(const Nodosecundario &d){
    string obj1,obj2;
    obj1=extension;
    obj2=d.extension;
     return obj1!=obj2;
    }
#endif // NODOSECUNDARIO_H
