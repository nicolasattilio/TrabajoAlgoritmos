#include <cstddef>
#include <iostream>

#include "Lista.h"+


using namespace std;

int main(){
    ///---------------Lista------------------------------

    Lista<unsigned int> miLista;
    miLista.agregarPrincipio(15);
    miLista.agregarPrincipio(5);
    miLista.agregarArbitrariamente(4,3);
    miLista.agregarArbitrariamente(7,2);
    miLista.agregarFinal(6);
    cout<<"\n";
    cout<<"La cantidad de elementos de la lista es de: "<<miLista.cantElemento()<<endl;
    if (miLista.esVacia())
        cout<<"La lista no tiene elementos."<<endl;
    else
        cout<<"La lista tiene elementos."<<endl;
    bool flag;
    int index=0;
    while ((index!=miLista.cantElemento())&&(flag==0)){
        cout<<index+1<<" elemento ";
        miLista.mostrar(index);
        index++;
        cout<<"Desea continuar? 0/1.."<<endl;
        cin>>flag;
        }
    cout<<"\n";
    if (miLista.existeElemento(15))
        cout<<"El elemento esta en la lista"<<endl;
    else
        cout<<"La elemento no esta en la lista"<<endl;

    miLista.eliminarElemento(4);
    miLista.eliminartodo();

return 0;
}

