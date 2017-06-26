#include "Arreglo.h"
#include <cstddef>


template <typename generico> Arreglo<generico>::Arreglo(){      //O(1);
    dato=NULL;      //O(1);
}

template <typename generico> Arreglo<generico>::~Arreglo(){     //O(n);
    vaciar();       //O(n);
}

template <typename generico> void Arreglo<generico>::agregarArreglo(const generico & elem, int index){      //O(n);
    int posicion=0;         //O(1);
    bool agrego=false;              //O(1);
    nodoArreglo * auxPunt;          //O(1);
    auxPunt = dato;         //O(1);
    nodoArreglo * nuevoNodo = new nodoArreglo;   //O(1);
    nuevoNodo->elem=elem;       //O(1);
    if (dato==NULL){        //O(1);
        nuevoNodo->sig=dato;        //O(1);
        nuevoNodo->ant=NULL;            //O(1);
        dato=nuevoNodo;         //O(1);
    }
    else{                           //O(n);
        int longArreglo = this->longArreglo();      //O(1);
        if (index>longArreglo){     //O(1);
            index=longArreglo;      //O(1);
        }
        while (auxPunt!=NULL && !agrego){   //O(n);
            if (index==1){          //O(1);
                 nuevoNodo->sig=dato;       //O(1);
                 nuevoNodo->ant=NULL;       //O(1);
                 dato=nuevoNodo;            //O(1);
                 agrego=true;               //O(1);
            }
            else if (posicion== (index-1)){     //O(1);
                 nuevoNodo->sig=auxPunt->sig;       //O(1);
                 nuevoNodo->ant=auxPunt;            //O(1);
                 auxPunt->sig=nuevoNodo;            //O(1);
                 agrego=true;                       //O(1);
                }
            else {                      //O(1);
                auxPunt=auxPunt->sig;       //O(1);
                posicion++;                 //O(1);
                }
            }
        }

}

template <typename generico> unsigned int Arreglo<generico>::longArreglo(){     //O(n);
    if (dato==NULL){    //O(1);
        return 0;       //O(1);
        }
    unsigned int contador = 0;  //O(1);
    nodoArreglo * auxPunt;      //O(1);
    auxPunt=dato;               //O(1);
    while (auxPunt!=NULL){      //O(n);
        auxPunt=auxPunt->sig;       //O(1);
        contador++;                 //O(1);
    }
    return contador;            //O(1);
}

template <typename generico> generico Arreglo<generico>::darElemento(int index)const{       //O(n);
   int diferencia;              //O(1);
   nodoArreglo * auxPunt;       //O(1);
   auxPunt=dato;                //O(1);
   for (diferencia=1;diferencia<index;diferencia++)     //O(n);
        if (auxPunt!=NULL)          //O(1);
            auxPunt=auxPunt->sig;   //O(1);
   if (diferencia==index)           //O(1);
    return auxPunt->elem;           //O(1);
}

template <typename generico> void Arreglo<generico>::vaciar(){      //O(n);
    nodoArreglo * aux;      //O(1);
    while (dato !=NULL){        //O(n);
        aux = dato -> sig;      //O(1);
        delete dato;            //O(1);
        dato = aux;             //O(1);
    }
    dato=NULL;              //O(1);
}



template class Arreglo<unsigned int>;
