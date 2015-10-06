#ifndef SECUNDARIO_H
#define SECUNDARIO_H
#include <iostream>
using namespace std;
class Secundario
{
  public:
    char extension[50];
    int primerNodo;
  public:
    void inicializar();
    friend ostream&operator<<(ostream& os,Secundario &d);
    bool operator==(const Secundario &d);
    bool operator<(const Secundario &d);
    bool operator<=(const Secundario &d);
} secundario;
bool Secundario::operator==(const Secundario &d){
    string obj1,obj2;
    obj1=extension;
    obj2=d.extension;
     return obj1==obj2;
    }
bool Secundario::operator<(const Secundario &d){
    string obj1,obj2;
    obj1=extension;
     obj2=d.extension;
    return obj1<obj2;
    }
bool Secundario::operator<=(const Secundario &d){
    string obj1,obj2;
    obj1=extension;
     obj2=d.extension;
    return obj1<=obj2;
    }
ostream& operator<<(ostream& os,Secundario &d){
       os<<"-----------------\n";
       os<<"Primer nodo     :"<<d.primerNodo<<endl;
       os<<"extension   :"<<d.extension<<endl;
       os<<"-----------------\n\n";
    return os;
    }



void Secundario::inicializar()
{
    ofstream escS("Secundario.txt",ios::app);
    int a;
    a=-1;
    strcpy(secundario.extension,"doc");
    secundario.primerNodo=a;
    escS.write((char*)&secundario,sizeof(Secundario));
    strcpy(secundario.extension,"xml");
    secundario.primerNodo=a;
    escS.write((char*)&secundario,sizeof(Secundario));
    strcpy(secundario.extension,"jpg");
    secundario.primerNodo=a;
    escS.write((char*)&secundario,sizeof(Secundario));
    strcpy(secundario.extension,"pdf");
    secundario.primerNodo=a;
    escS.write((char*)&secundario,sizeof(Secundario));
    escS.close();
}
#endif // SECUNDARIO_H
