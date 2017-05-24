#include "Arreglo.h"
#include <cstddef>


template <typename generico> Arreglo<generico>::Arreglo(){
    dato=NULL;
}

template <typename generico> Arreglo<generico>::~Arreglo(){
    vaciar();
}

template <typename generico> void Arreglo<generico>::agregarArreglo(const generico & elem, int index){
    int posicion=0;
    bool agrego=false;
    nodoArreglo * auxPunt;
    auxPunt = dato;
    nodoArreglo * nuevoNodo = new nodoArreglo;
    nuevoNodo->elem=elem;
    if (dato==NULL){
        nuevoNodo->sig=dato;
        nuevoNodo->ant=NULL;
        dato=nuevoNodo;
    }
    else{
        int longArreglo = this->longArreglo();
        if (index>longArreglo){
            index=longArreglo;
        }
        while (auxPunt!=NULL && !agrego){
            if (index==1){
                 nuevoNodo->sig=dato;
                 nuevoNodo->ant=NULL;
                 dato=nuevoNodo;
                 agrego=true;
            }
            else if (posicion== (index-1)){
                 nuevoNodo->sig=auxPunt->sig;
                 nuevoNodo->ant=auxPunt;
                 auxPunt->sig=nuevoNodo;
                 agrego=true;
                }
            else {
                auxPunt=auxPunt->sig;
                posicion++;
                }
            }
        }

}

template <typename generico> unsigned int Arreglo<generico>::longArreglo(){
    if (dato==NULL){
        return 0;
        }
    unsigned int contador = 0;
    nodoArreglo * auxPunt;
    auxPunt=dato;
    while (auxPunt!=NULL){
        auxPunt=auxPunt->sig;
        contador++;
        }
    return contador;
}

template <typename generico> generico Arreglo<generico>::darElemento(int index)const{
   int diferencia;
   nodoArreglo * auxPunt;
   auxPunt=dato;
   for (diferencia=1;diferencia<index;diferencia++)
        if (auxPunt!=NULL)
            auxPunt=auxPunt->sig;
   if (diferencia==index)
    return auxPunt->elem;
}

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
