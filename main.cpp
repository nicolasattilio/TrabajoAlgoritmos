#include <cstddef>
#include <iostream>

#include "Lista.h"
#include "Arreglo.h"


using namespace std;

int main(){
    ///---------------Lista------------------------------
    /*cout<<"LISTA"<<endl;
    Lista<unsigned int> miLista;
    miLista.agregarPrincipio(15);
    miLista.agregarPrincipio(5);
    miLista.agregarArbitrariamente(4,3);
    miLista.agregarArbitrariamente(7,2);
    miLista.agregarFinal(6);
    cout<<endl;
    cout<<"La cantidad de elementos de la lista es de: "<<miLista.cantElemento()<<endl;
    if (miLista.esVacia())
        cout<<"La lista no tiene elementos."<<endl;
    else
        cout<<"La lista tiene elementos."<<endl;

    cout<<"Elemento a buscar en la posicion posicion 2 :"<<miLista.mostrar(2)<<endl;


    cout<<endl;

     while(miLista.mostrarElemento()!=NULL){
        cout<<miLista.mostrarElemento()<<endl;
        miLista.siguiente();
    }

    cout<<endl;
    miLista.eliminarElemento(4);
    cout<<"Elimine el elemento en el indice 4."<<endl;

    while(miLista.mostrarElemento()!=NULL){
        cout<<miLista.mostrarElemento()<<endl;
        miLista.siguiente();
    }
    cout<<endl;

     if (miLista.existeElemento(15))
        cout<<"El elemento esta en la lista"<<endl;
    else
        cout<<"La elemento no esta en la lista"<<endl;
    cout<<endl;

    miLista.eliminartodo();
    cout<<"Elimine todo"<<endl;

    if (miLista.esVacia())
        cout<<"La lista no tiene elementos."<<endl;
    else
        cout<<"La lista tiene elementos."<<endl;

*/
    ///---------------Arreglo------------------------------

    Arreglo<unsigned int> miArreglo;
    cout<<miArreglo.longArreglo()<<endl;
    miArreglo.agregarArreglo(33,1);
    miArreglo.agregarArreglo(25,2);
    miArreglo.agregarArreglo(4,4);
    cout<<miArreglo.longArreglo()<<endl;
    miArreglo.agregarArreglo(3,4);
    miArreglo.agregarArreglo(1,1);
    cout<<miArreglo.longArreglo()<<endl;
    cout<<"ELEMENTO :"<<miArreglo.darElemento(1)<<endl;
    cout<<"ELEMENTO :"<<miArreglo.darElemento(2)<<endl;
    cout<<"ELEMENTO :"<<miArreglo.darElemento(3)<<endl;
    cout<<"ELEMENTO :"<<miArreglo.darElemento(4)<<endl;
    cout<<"ELEMENTO :"<<miArreglo.darElemento(5)<<endl;
return 0;
}

