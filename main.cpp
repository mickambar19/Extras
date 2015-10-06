#include <iostream>
#include "Programa.h"
using namespace std;
int main()
{
       char x[MAX];
       int menu;
       int opt2;
       remove("Secundario.txt");
       secundario.inicializar();
       do
       {
           cout<<"MENU PRINCIPAL\n";
           cout<<"Que deseas hacer:\n";
           cout<<"1.-Capturar\n";
           cout<<"2.-Mostrar\n";
           cout<<"3.-Buscar\n";
           cout<<"4.-Modificar\n";
           cout<<"5.-Eliminar\n";
           cout<<"6.-Cargar Archivo\n";
           cout<<"7.-Ordenar y mostrar\n";
           cout<<"8.-Buscar por extension\n";
           cout<<"9.-MostrarLista Secundaria\n";
           cout<<"10.-MostrarLista Archivo secundario\n";
           cout<<"0.-Salir\n";
           menu=leer_int();
           switch (menu) {
           case 1:
               objeto.Capturar();
               break;
           case 2:
               objeto.Mostrar();
               break;
           case 3:
               cout<<"Ingresa el objeto a buscar:\n";
               cin.getline(x,MAX);
               objeto.Buscar(x);
               break;
           case 4:
               cout<<"Ingresa el objeto a modificar:\n";
               cin.getline(x,MAX);
               objeto.Modificar(x);
               break;
           case 5:
               cout<<"Ingresa el objeto a eliminar:\n";
               cin.getline(x,MAX);
               objeto.Eliminar(x);
               break;
           case 6:
               cout<<"Cargaste la lista\n";
               Cargar_lista();
               strcpy(nodosecundario.extension,"doc");
               ligarlista(nodosecundario);
               strcpy(nodosecundario.extension,"xml");
               ligarlista(nodosecundario);
               strcpy(nodosecundario.extension,"pdf");
               ligarlista(nodosecundario);
               strcpy(nodosecundario.extension,"jpg");
               ligarlista(nodosecundario);
               break;
           case 7:
               cout<<"Ordenar lista y mostrar\n";
               cout<<"Elige opcion:\n";
               cout<<"1.-Ordenar,mostrar y  guardar\n";
               cout<<"2.-Ordenar mostrar\n";
               opt2=leer_int();
               switch (opt2) {
               case 1:
                    l.order();
                    objeto.Mostrar();
                    break;
               case 2:
                   l2=l;
                   l2.order();
                   objeto.Mostrarsin();
                   break;
               default:
                   break;
               }

               break;
           case  8:
               cout<<"Ingresa la extension a buscar:\n";
               cin.getline(x,MAX);
               strcpy(nodosecundario.extension,x);
               seguimiento(nodosecundario);
               break;
           case 9:
               lS.printAll();
               break;
           case 10:
               archivoS();
               break;
           case  0:
               l.deleteAll();
               l2.deleteAll();
               cout<<"estas por salir\n";
               break;
           default:
               cout<<"NO EXISTE LA OPCION ELEGIDA\n";
               break;
           }
       }while(menu!=0);


    return 0;
}

