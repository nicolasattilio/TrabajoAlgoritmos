#include "Lista.h"
#include <cstddef>



template <typename generico> Lista<generico>::Lista(){
    dato=NULL;
}


template <typename generico> Lista<generico>::~Lista(){
    vaciar();
}

template <typename generico> unsigned int Lista<generico>::cantElemento() {
    if(dato == NULL) {
        return 0;
    }
    int contador = 0;
    nodoLista * auxPunt;
    auxPunt = dato;

    while(auxPunt != NULL) {
        contador++;
        auxPunt= auxPunt->sig;
    }
    return contador;
}

template <typename generico> void Lista<generico>::agregarArbitrariamente(const generico & elem, int index){
    int posicion = 0;
    bool agrego = false;
    nodoLista * auxPunt;
    auxPunt = dato;
    nodoLista * aux = new nodoLista;
    aux->elem = elem;
    if(dato == NULL) {
        aux->sig = dato;
        dato = aux;
    }
    else {
        int cantElemento = this->cantElemento();
        if(index > cantElemento) {
            index = cantElemento;
        }
        while(auxPunt != NULL && !agrego) {
            if(index == 0 || !index) {
                aux->sig = auxPunt;
                dato = aux;
                agrego = true;
            } else if(posicion == (index - 1)) {
                aux->sig = auxPunt->sig;
                auxPunt->sig = aux;
                agrego = true;
            } else {
                auxPunt = auxPunt->sig;
                posicion++;
            }
        }
    }
}

template <typename generico> void Lista<generico>::agregarPrincipio(const generico & elem) {
    this->agregarArbitrariamente(elem, 0);
}

template <typename generico> void Lista<generico>::agregarFinal(const generico & elem) {
    this->agregarArbitrariamente(elem, cantElemento());
}

template <typename generico> void Lista<generico>::eliminarElemento(const generico & elem){
    nodoLista * auxPunt;
    auxPunt = dato;
    nodoLista * auxPunt2;
    auxPunt2 = dato;
    if(auxPunt != NULL)
        if(auxPunt->elem == elem) {
            auxPunt = dato->sig;
            dato = auxPunt;
        }
        while(auxPunt!= NULL){
            if(auxPunt->elem == elem) {
                auxPunt = auxPunt2;
                auxPunt2 = auxPunt->sig;
                auxPunt->sig =auxPunt2->sig;
                delete auxPunt2;
            }
            else{
                auxPunt2 = auxPunt;
                auxPunt = auxPunt->sig;

            }
        }
}
template <typename generico> bool Lista<generico>::esVacia(){
    if (dato!=NULL)
        return false;
    else
        return true;
}

template <typename generico> void Lista<generico>::eliminartodo(){
    while (dato!=NULL){
        nodoLista * borrador;
        borrador=dato;
        dato=dato->sig;
        delete borrador;
    }
}

template <typename generico> generico Lista<generico>::mostrar(int index) const{
    int diferencia;
    nodoLista * auxPunt;
    auxPunt = dato;
    for (diferencia = 1;diferencia<index;diferencia++)
            if (auxPunt!=NULL)
                auxPunt = auxPunt->sig;
    if (diferencia==index)
        return auxPunt->elem;
}


template <typename generico> generico Lista<generico>::mostrarElemento(){
    nodoLista*auxPunt;
    auxPunt=dato;
    if (auxPunt!=NULL)
        return auxPunt->elem;
    else{
        dato=punteroLista;
         return NULL;
    }
}

template <typename generico> void Lista<generico>::siguiente(){
    if (punteroLista==NULL)
        punteroLista=dato;
    nodoLista * auxPunt;
    auxPunt =dato;
     if (auxPunt->sig!=NULL){
        auxPunt = auxPunt->sig;
        dato = auxPunt;
    }
    else
        dato=NULL;
}



template <typename generico> bool Lista<generico>::existeElemento(const generico & elem) const{
    nodoLista * auxPunt;
    auxPunt = dato;
    if (auxPunt==NULL)
        return false;
    else
    while (auxPunt!=NULL){
        if (auxPunt->elem = elem)
            return true;
        else
            auxPunt= auxPunt->sig;
    }
}



template <typename generico> void Lista<generico>::vaciar(){
    nodoLista * aux;
    while (dato !=NULL){
        aux = dato -> sig;
        delete dato;
        dato = aux;
    }
    dato=NULL;
}


template class Lista<unsigned int>;
