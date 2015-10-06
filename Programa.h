#ifndef PROGRAMA_H
#define PROGRAMA_H
#include <fstream>
#include <iostream>
#include <cstring>
#include "Nodosecundario.h"
#include "Secundario.h"
#include "leerentero.h"
#include "ListaDoble.h"
#include <cstdlib>
using namespace std;
ListaSimple<Indice> l;
ListaSimple<Indice> l2;
ListaSimple<Nodosecundario> lS;
int numpos=0;
void Guardar_lista();
void Cargar_lista();
void ligarlista(Nodosecundario bus);
void seguimiento(Nodosecundario bus);

class Programa
{
public:
    char autor[MAX];
    char nombre[MAX];
    char extension[MAX];
    char version[MAX];
    char compuesta[MAX];
public:
    void Capturar();
    void Mostrar();
    void Mostrarsin();
    bool Modificar(char bus[MAX]);
    bool Buscar(char bus[MAX]);
    bool Eliminar(char bus[MAX]);
}objeto;

void Programa::Capturar()
{
    int opt,band1=0;
    char extension2[MAX],autor2[MAX];
    cout<<"MENU CAPTURAR\n";
    do{
        cout<<"Ingresa el autor:\n";
        cin.getline(autor,MAX);
        if(strlen(autor)<3)cout<<"Debe ser mayor a 3 caracteres\n\n";
    }while(strlen(autor)<3);
    cout<<"Ingresa el nombre:\n";
    cin.getline(nombre,MAX);
    do{
    cout<<"Ingresa el extension:\n";
    cout<<"1.- .jpg\n";
    cout<<"2.- .pdf\n";
    cout<<"3.- .doc\n";
    cout<<"4.- .xml\n";
    opt=leer_int();
    switch (opt) {
    case 1:
        strcpy(extension,".jpg");
        strcpy(extension2,"jpg");
        band1=1;
        break;
    case 2:
        strcpy(extension,".pdf");
        strcpy(extension2,"pdf");
        band1=1;
        break;
    case 3:
        strcpy(extension,".doc");
        strcpy(extension2,"doc");
        band1=1;
        break;
    case 4:
        strcpy(extension,".xml");
        strcpy(extension2,"xml");
        band1=1;
        break;
    default:
        break;
    }}while(band1==0);
    cout<<"Ingresa el version:\n";
    cin.getline(version,MAX);
    cout<<"Autor    :"<<autor<<endl;
    cout<<"Nombre   :"<<nombre<<endl;
    cout<<"Extension:"<<extension<<endl;
    cout<<"Version  :"<<version<<endl;


    strcpy(compuesta,extension2);
    strncpy(autor2,autor,sizeof(char)*3);
    strcat(compuesta,autor2);
    compuesta[6]='\0';
    cout<<"Compuesta  :"<<compuesta<<endl<<endl;
    strcpy(indice.llave,compuesta);
            NodoDoble<Indice> *encontrado;
     if(l.isEmpty())
             {
             ofstream escpro("Programa.txt",ios::app);
             escpro.write((char *)&objeto,sizeof(objeto));
             strcpy(indice.llave,compuesta);
             escpro.seekp(0,escpro.end); //ESTA LINEA NO ES NECESARIA REALMENTE SOLO SI QUIERES VERIFICAR QUE EL PUNTERO S� ESTE AL FINAL
             indice.posicion=escpro.tellp();
             indice.posicion=indice.posicion-sizeof(objeto);
             l.insertOneAfter(indice,l.last());
             strcpy(nodosecundario.extension,extension2);
             escpro.close();
             }
     else if(!l.isEmpty()){
     encontrado=l.linealSearch(indice);

    if(encontrado==NULL){
    ofstream escpro("Programa.txt",ios::app);
    escpro.write((char *)&objeto,sizeof(objeto));
    strcpy(indice.llave,compuesta);
    escpro.seekp(0,escpro.end); //ESTA LINEA NO ES NECESARIA REALMENTE SOLO SI QUIERES VERIFICAR QUE EL PUNTERO S� ESTE AL FINAL
    indice.posicion=escpro.tellp();
    indice.posicion=indice.posicion-sizeof(objeto);
    strcpy(nodosecundario.extension,extension2);
    l.insertOneAfter(indice,l.last());
    escpro.close();
     }
        else
        {
            cout<<"No se puede guardar tu archivo , YA EXISTE OTRO CON LA MISMA LLAVE\n";
        }

    }
     ofstream escind("Indice.txt",ios::app);
     escind.write((char *)&indice, sizeof(indice));
     escind.close();
     //aqui es el proceso para lista invertida

     strcpy(nodosecundario.compuesta,l.last()->getData().llave);
     lS.insertOneAfter(nodosecundario,lS.last());
     lS.last()->setposn(numpos);
     numpos++;
     strcpy(nodosecundario.extension,extension2);
     ligarlista(nodosecundario);
}

void Programa::Mostrar()
{
    int i=0;
    NodoDoble<Indice> *aux;
    aux=l.first();
    if(l.isEmpty()){
       cout<<"No se han guardado datos\n";
    }
    else{
        while(aux!=NULL)
        {
            i++;
            indice=aux->getData();
            ifstream leeprogras("Programa.txt",ios::out);
            leeprogras.seekg(indice.posicion,ios::beg);
            leeprogras.read((char*)&objeto,sizeof(objeto));
            if(leeprogras.eof())break;
            cout<<"------- PRORAMA num:"<<i<<"--------"<<endl;
            cout<<"Autor    :"<<objeto.autor<<endl;
            cout<<"Nombre   :"<<objeto.nombre<<endl;
            cout<<"Extension:"<<objeto.extension<<endl;
            cout<<"Version  :"<<objeto.version<<endl;
            cout<<"Llave    :"<<objeto.compuesta<<endl;
            cout<<"----------------------   "<<endl;
            aux=aux->getNext();
        }
    }
}

bool Programa::Buscar(char bus[MAX])
{
    int i=0;
    bool existe=false;
    NodoDoble<Indice> *aux;
    aux=l.first();
    if(l.isEmpty()){
       cout<<"No se han guardado datos\n";
    }
    else{
        while(aux!=NULL)
        {
            i++;
            indice=aux->getData();
            if(strcmp(indice.llave,bus)==0)
            {
                ifstream leeprogras("Programa.txt",ios::out);
                leeprogras.seekg(indice.posicion,ios::beg);
                leeprogras.read((char*)&objeto,sizeof(objeto));
                cout<<"------- PRORAMA num:"<<i<<"--------"<<endl;
                cout<<"Autor    :"<<objeto.autor<<endl;
                cout<<"Nombre   :"<<objeto.nombre<<endl;
                cout<<"Extension:"<<objeto.extension<<endl;
                cout<<"Version  :"<<objeto.version<<endl;
                cout<<"Llave    :"<<objeto.compuesta<<endl;
                cout<<"----------------------   "<<endl;
                existe=true;
            }
            aux=aux->getNext();
        }
    }
    return existe;
}

bool Programa::Modificar(char bus[MAX])
{
    int i=0;
    char extension2[MAX],autor2[MAX];
    int band1=1;
    bool existe=false;
    NodoDoble<Indice> *nodoin;
    nodoin=l.first();
    if(l.isEmpty()){
       cout<<"No se han guardado datos\n";
    }
    else{
        while(nodoin!=NULL)
        {
            i++;
            indice=nodoin->getData();
            cout<<indice<<endl;
            if(strcmp(indice.llave,bus)==0)
            {
                char aux[MAX];
                int opt;
                ifstream leeprogras("Programa.txt",ios::out);
                leeprogras.seekg(indice.posicion,ios::beg);
                leeprogras.read((char*)&objeto,sizeof(objeto));
                leeprogras.close();
                cout<<"------- PRORAMA num:"<<i<<"--------"<<endl;
                cout<<"Autor    :"<<objeto.autor<<endl;
                cout<<"Nombre   :"<<objeto.nombre<<endl;
                cout<<"Extension:"<<objeto.extension<<endl;
                cout<<"Version  :"<<objeto.version<<endl;
                cout<<"Llave    :"<<objeto.compuesta<<endl;
                cout<<"----------------------   "<<endl;
                cout<<" QUE DESEAS MODIFICAR:\n";
                cout<<" 1.-Autor \n";
                cout<<" 2.-Nombre\n";
                cout<<" 3.-Extension\n";
                cout<<" 4.-Version\n";
                cout<<" 9.-Salir\n";
                opt=leer_int();
                switch (opt) {
                case 1:
                    cout<<"Ingresa el nuevo autor:\n";
                    cin.getline(aux,MAX);
                    strcpy(objeto.autor,aux);
                    objeto.compuesta[3]='\0';
                    strncpy(autor2,objeto.autor,sizeof(char)*3);
                    strcat(objeto.compuesta,autor2);
                    objeto.compuesta[6]='\0';
                    break;
                case 2:
                    cout<<"Ingresa el nuevo nombre:\n";
                    cin.getline(aux,MAX);
                    strcpy(objeto.nombre,aux);
                    break;
                case 3:
                    do{
                        cout<<"Ingresa la nueva extension:\n";
                        cout<<"1.- .jpg\n";
                        cout<<"2.- .pdf\n";
                        cout<<"3.- .doc\n";
                        cout<<"4.- .xml\n";
                        opt=leer_int();
                        switch (opt) {
                        case 1:
                            strcpy(objeto.extension,".jpg");
                            strcpy(extension2,"jpg");
                            objeto.compuesta[0]='\0';
                            strcpy(objeto.compuesta,extension2);
                            strncpy(autor2,objeto.autor,sizeof(char)*3);
                            strcat(objeto.compuesta,autor2);
                            objeto.compuesta[6]='\0';
                            band1=1;
                            break;
                        case 2:
                            strcpy(objeto.extension,".pdf");
                            strcpy(extension2,"pdf");
                            objeto.compuesta[0]='\0';
                            strcpy(objeto.compuesta,extension2);
                            strncpy(autor2,objeto.autor,sizeof(char)*3);
                            strcat(objeto.compuesta,autor2);
                            objeto.compuesta[6]='\0';
                            band1=1;
                            break;
                        case 3:
                            strcpy(objeto.extension,".doc");
                            strcpy(extension2,"doc");
                            objeto.compuesta[0]='\0';
                            strcpy(objeto.compuesta,extension2);
                            strncpy(autor2,objeto.autor,sizeof(char)*3);
                            strcat(objeto.compuesta,autor2);
                            objeto.compuesta[6]='\0';
                            band1=1;
                            break;
                        case 4:
                            strcpy(objeto.extension,".xml");
                            strcpy(extension2,"xml");
                            objeto.compuesta[0]='\0';
                            strcpy(objeto.compuesta,extension2);
                            strncpy(autor2,objeto.autor,sizeof(char)*3);
                            strcat(objeto.compuesta,autor2);
                            objeto.compuesta[6]='\0';
                            band1=1;
                            break;
                        default:
                            break;
                        }}while(band1==0);
                    break;
                case 4:
                    cout<<"Ingresa el nuevo version:\n";
                    cin.getline(aux,MAX);
                    strcpy(objeto.version,aux);
                    break;
                case 9:

                    break;
                default:
                    cout<<"Esta opcion no existe\n";
                    break;
                }
                objeto.compuesta[6]='\0';
                cout<<"Compuesta  :"<<objeto.compuesta<<endl<<endl;
                strcpy(indice.llave,objeto.compuesta);
                cout<<"PROGRAMA A GUARDAR\n";
                cout<<"Autor    :"<<objeto.autor<<endl;
                cout<<"Nombre   :"<<objeto.nombre<<endl;
                cout<<"Extension:"<<objeto.extension<<endl;
                cout<<"Version  :"<<objeto.version<<endl;
                cout<<"Llave    :"<<objeto.compuesta<<endl;

                NodoDoble<Indice> *encontrado;
                if(!l.isEmpty()){
                     encontrado=l.linealSearch(indice);

                    if(encontrado==NULL|| (encontrado!=NULL && (strcmp(encontrado->getData().llave,objeto.compuesta)==0))){
                    ofstream escpro;
                    escpro.open("ProgramaAux.txt",ios::app);
                    escpro.write((char *)&objeto,sizeof(objeto));
                    strcpy(indice.llave,objeto.compuesta);
                    nodoin->setData(indice);
                    escpro.close();
                    existe =true;
                     }
                        else
                        {
                            cout<<"No se puede guardar tu archivo , YA EXISTE OTRO CON LA MISMA LLAVE\n";
                        }
                    }
            }else
            {
                ifstream leeprogras("Programa.txt");
                leeprogras.seekg(indice.posicion,ios::beg);
                leeprogras.read((char*)&objeto,sizeof(objeto));
                ofstream escpro("ProgramaAux.txt",ios::app);
                cout<<"PROGRAMA A GUARDAR\n";
                cout<<"Autor    :"<<objeto.autor<<endl;
                cout<<"Nombre   :"<<objeto.nombre<<endl;
                cout<<"Extension:"<<objeto.extension<<endl;
                cout<<"Version  :"<<objeto.version<<endl;
                cout<<"Llave    :"<<objeto.compuesta<<endl;

                escpro.write((char *)&objeto,sizeof(objeto));
                escpro.close();
                leeprogras.close();
            }
            nodoin=nodoin->getNext();
        }
    }

    remove("IndiceAux.txt");
    rename("IndiceAux.txt","Indice.txt");
    remove("Programa.txt");
    rename("ProgramaAux.txt","Programa.txt");
    lS.deleteAll();
    l.deleteAll();
    Cargar_lista();
    strcpy(nodosecundario.extension,"doc");
    ligarlista(nodosecundario);
    strcpy(nodosecundario.extension,"xml");
    ligarlista(nodosecundario);
    strcpy(nodosecundario.extension,"pdf");
    ligarlista(nodosecundario);
    strcpy(nodosecundario.extension,"jpg");
    ligarlista(nodosecundario);

    return existe;
}

bool Programa::Eliminar(char bus[MAX])
{
    int i=0;
    bool existe=false;
    NodoDoble<Indice> *aux;
    NodoDoble<Indice> *otro;
    NodoDoble<Nodosecundario> *ajax;
    ofstream escpro("ProgramaAux.txt",ios::app);
    ifstream leeprogras("Programa.txt",ios::out);
    ofstream escind("IndiceAux.txt",ios::app);

    aux=l.first();
    if(l.isEmpty()){
       cout<<"No se han guardado datos\n";
    }
    else{
        while(aux!=NULL)
        {
            i++;
            indice=aux->getData();
            if(strcmp(indice.llave,bus)==0)
            {
                existe=true;
                ajax=lS.first();
                while(ajax!=NULL)
                {
                    if(strcmp(ajax->getData().compuesta,bus)==0)
                    {
                        lS.delete_e(ajax);
                    }
                    ajax=ajax->getNext();
                    if(ajax==NULL)break;
                }
                otro=aux;
                aux=aux->getNext();
                l.delete_e(otro);
                l.printAll();
                lS.printAll();
                strcpy(nodosecundario.extension,"doc");
                ligarlista(nodosecundario);
                strcpy(nodosecundario.extension,"xml");
                ligarlista(nodosecundario);
                strcpy(nodosecundario.extension,"pdf");
                ligarlista(nodosecundario);
                strcpy(nodosecundario.extension,"jpg");
                ligarlista(nodosecundario);

             }else
             {

                 leeprogras.seekg(indice.posicion,ios::beg);
                 leeprogras.read((char*)&objeto,sizeof(objeto));

                 escpro.write((char *)&objeto,sizeof(objeto));
                 strcpy(indice.llave,compuesta);
                 escpro.seekp(0,escpro.end); //ESTA LINEA NO ES NECESARIA REALMENTE SOLO SI QUIERES VERIFICAR QUE EL PUNTERO S� ESTE AL FINAL
                 indice.posicion=escpro.tellp();
                 indice.posicion=indice.posicion-sizeof(objeto);
                 aux->setData(indice);
                 aux=aux->getNext();
                 escind.write((char*)&indice,sizeof(Indice));
               }

        }
    }
    escpro.close();
    leeprogras.close();
    escind.close();
    remove("Programa.txt");
    rename("ProgramaAux.txt","Programa.txt");
    remove("Indice.txt");
    rename("IndiceAux.txt","Indice.txt");
    return existe;
}
void Programa::Mostrarsin()
{
    int i=0;
    NodoDoble<Indice> *aux;
    aux=l2.first();
    if(l.isEmpty()){
       cout<<"No se han guardado datos\n";
    }
    else{
        while(aux!=NULL)
        {
            i++;
            indice=aux->getData();
            ifstream leeprogras("Programa.txt",ios::out);
            leeprogras.seekg(indice.posicion,ios::beg);
            leeprogras.read((char*)&objeto,sizeof(objeto));
            if(leeprogras.eof())break;
            cout<<"------- PRORAMA num:"<<i<<"--------"<<endl;
            cout<<"Autor    :"<<objeto.autor<<endl;
            cout<<"Nombre   :"<<objeto.nombre<<endl;
            cout<<"Extension:"<<objeto.extension<<endl;
            cout<<"Version  :"<<objeto.version<<endl;
            cout<<"Llave    :"<<objeto.compuesta<<endl;
            cout<<"----------------------   "<<endl;
            aux=aux->getNext();
        }
    }
}


void Cargar_lista()
{
    ifstream leerind("Indice.txt");
    if(!leerind.good()){
        cout<<"Tu archivo no existe\n";
    }else{
        while(!leerind.eof()){
            leerind.read((char *)&indice, sizeof(indice));
            if(leerind.eof())break;
            l.insertOneAfter(indice,l.last());
            strcpy(nodosecundario.compuesta,l.last()->getData().llave);
            strncpy(nodosecundario.extension,l.last()->getData().llave,3);
              nodosecundario.extension[3] = '\0';
            lS.insertOneAfter(nodosecundario,lS.last());
            lS.last()->setposn(numpos);
            numpos++;

          }
        lS.printAll();
    }
    leerind.close();
}

void Guardar_lista()
{
    ofstream escind("Indice.txt",ios::app);
    NodoDoble<Indice> *aux;
    aux=l.first();
    if(!l.isEmpty()){
        while(aux!=NULL){
            indice=aux->getData();
            ofstream escind("Indice.txt",ios::app);
            escind.write((char *)&indice, sizeof(indice));
            aux=aux->getNext();
        }
    }else
    {
        cout<<"la lista esta vacia\n";
    }
}

void ligarlista(Nodosecundario bus)
{
    NodoDoble<Nodosecundario> *deaqui;
    NodoDoble<Nodosecundario> *aca;
    deaqui=lS.linealSearch(bus);
    if(deaqui==NULL){

    }else{
        ifstream leerS("Secundario.txt");
        ofstream escS("AuxiliarS.txt",ios::app);
        if(!leerS.good())
        {
            cout<<"Tu archivo no existe\n";
        }else
        {
            while(!leerS.eof())
            {

                leerS.read((char*)&secundario,sizeof(Secundario));
                if(leerS.eof())break;
                if(strcmp(secundario.extension,bus.extension)==0)
                {
                    if(deaqui==NULL)
                    {
                        escS.write((char *)&secundario,sizeof(Secundario));

                    }else
                    {
                        secundario.primerNodo=deaqui->getPosn();
                        escS.write((char *)&secundario,sizeof(Secundario));
                    }
                }else
                {
                    escS.write((char *)&secundario,sizeof(Secundario));
                }
                if(leerS.eof())break;
            }
        }

        leerS.close();
        escS.close();
        remove("Secundario.txt");
        rename("AuxiliarS.txt","Secundario.txt");

        while(deaqui!=NULL)
        {

            aca=deaqui;

            aca=aca->getNext();

            while(aca!=NULL){
                if(aca->getData()==bus )break;
                aca=aca->getNext();
            }


            if(aca!=NULL){
                nodosecundario=deaqui->getData();
                nodosecundario.sigNodo=aca;
                deaqui->setData(nodosecundario);
                nodosecundario=deaqui->getData();

                deaqui=aca;
            }
            if(aca==NULL)
            {
                nodosecundario=deaqui->getData();
                nodosecundario.sigNodo=NULL;
                deaqui->setData(nodosecundario);
                break;


            }
            if(aca->getNext()==NULL)
            {

                nodosecundario=deaqui->getData();
                nodosecundario.sigNodo=NULL;
                deaqui->setData(nodosecundario);
                nodosecundario=deaqui->getData();
                break;
            }

        }

    }

}
void seguimiento(Nodosecundario bus)
{
    NodoDoble<Nodosecundario> *deaqui;
    deaqui=lS.linealSearch(bus);
    cout<<"Aqui comienza seguimiento\n";
    while(deaqui!=NULL)
    {

        nodosecundario=deaqui->getData();
        cout<<nodosecundario;
        objeto.Buscar(nodosecundario.compuesta);
        deaqui=deaqui->getData().sigNodo;
        if(deaqui==NULL) break;
    }
}
void archivoS(){
    ifstream leerS("Secundario.txt");
    if(!leerS.good()){
        cout<<"Tu archivo no existe\n";
    }else
    {
        while(!leerS.eof())
        {
            leerS.read((char*)&secundario,sizeof(Secundario));
            if(leerS.eof())break;
            cout<<secundario;
        }
    }
    leerS.close();
}
#endif // PROGRAMA_H
