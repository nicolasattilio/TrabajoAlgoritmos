#include "Arre*glo.h"
#include <cstddef>


template <typename generico> Arreglo<generico>::Arreglo(){
    dato=NULL;
}

template <typename generico> Arreglo<generico>::~Arreglo(){
    vaciar();
}

template <typename generico> void Arreglo<generico>::agregarArreglo(const generico & elem, int index);
    nodoArreglo * auxPunt;
    auxPunt = dato;
    nodoLista * nuevoNodo = new NodoLista;




template <typename generico> void Arreglo<generico>::vaciar(){
    nodoArreglo * aux;
    while (dato !=NULL){
        aux = dato -> sig;
        delete dato;
        dato = aux;
    }
    dato=NULL;
}



template class Arreglo<unsigned int>;
