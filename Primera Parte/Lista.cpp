#include "Lista.h"
#include <cstddef>



template <typename generico> Lista<generico>::Lista(){      //O(1);
    dato=NULL;      //O(1);
}


template <typename generico> Lista<generico>::~Lista(){     //O(n);
    vaciar();       //O(n);
}

template <typename generico> unsigned int Lista<generico>::cantElemento() {     //O(n);
    if(dato == NULL) {      //O(1);
        return 0;           //O(1);
    }
    int contador = 0;       //O(1);
    nodoLista * auxPunt;    //O(1);
    auxPunt = dato;         //O(1);

    while(auxPunt != NULL) {        //O(n);
        contador++;                 //O(1);
        auxPunt= auxPunt->sig;      //O(1);
    }
    return contador;        //O(1);
}

template <typename generico> void Lista<generico>::agregarArbitrariamente(const generico & elem, int index){    //O(n);
    int posicion = 0;                       //O(1);
    bool agrego = false;                    //O(1);
    nodoLista * auxPunt;                    //O(1);
    auxPunt = dato;                         //O(1);
    nodoLista * aux = new nodoLista;        //O(1);
    aux->elem = elem;                       //O(1);
    if(dato == NULL) {                          //O(1);
        aux->sig = dato;                        //O(1);
        dato = aux;                             //O(1);
    }
    else {                                              //O(n);
        int cantElemento = this->cantElemento();        //O(1);
        if(index > cantElemento) {                      //O(1);
            index = cantElemento;                       //O(1);
        }
        while(auxPunt != NULL && !agrego) {             //O(n);
            if(index == 0 || !index) {                  //O(1);
                aux->sig = auxPunt;                     //O(1);
                dato = aux;                             //O(1);
                agrego = true;                          //O(1);
            } else if(posicion == (index - 1)) {        //O(1);
                aux->sig = auxPunt->sig;                //O(1);
                auxPunt->sig = aux;                     //O(1);
                agrego = true;                          //O(1);
            } else {                                    //O(1);
                auxPunt = auxPunt->sig;                 //O(1);
                posicion++;                             //O(1);
            }
        }
    }
}

template <typename generico> void Lista<generico>::agregarPrincipio(const generico & elem) {    //O(n);
    this->agregarArbitrariamente(elem, 0);                  //O(n);
}

template <typename generico> void Lista<generico>::agregarFinal(const generico & elem) {        //O(n);
    this->agregarArbitrariamente(elem, cantElemento());     //O(n);
}

template <typename generico> void Lista<generico>::eliminarElemento(const generico & elem){     //O(n);
    nodoLista * auxPunt;                    //O(1);
    auxPunt = dato;                         //O(1);
    nodoLista * auxPunt2;                   //O(1);
    auxPunt2 = dato;                        //O(1);
    if(auxPunt != NULL)                     //O(1);
        if(auxPunt->elem == elem) {         //O(1);
            auxPunt = dato->sig;            //O(1);
            dato = auxPunt;                 //O(1);
        }
        while(auxPunt!= NULL){                  //O(n);
            if(auxPunt->elem == elem) {         //O(1);
                auxPunt = auxPunt2;             //O(1);
                auxPunt2 = auxPunt->sig;        //O(1);
                auxPunt->sig =auxPunt2->sig;    //O(1);
                delete auxPunt2;                //O(1);
            }
            else{                               //O(1);
                auxPunt2 = auxPunt;             //O(1);
                auxPunt = auxPunt->sig;         //O(1);
            }
        }
}
template <typename generico> bool Lista<generico>::esVacia(){       //O(1);
    if (dato!=NULL)//O(1);
        return false;//O(1);
    else//O(1);
        return true;//O(1);
}

template <typename generico> void Lista<generico>::eliminartodo(){      //O(n);
    while (dato!=NULL){             //O(n);
        nodoLista * borrador;       //O(1);
        borrador=dato;              //O(1);
        dato=dato->sig;             //O(1);
        delete borrador;            //O(1);
    }
}

template <typename generico> generico Lista<generico>::mostrarPorIndice(int index) const{       //O(n);
    int diferencia;             //O(1);
    nodoLista * auxPunt;        //O(1);
    auxPunt = dato;             //O(1);
    for (diferencia = 1;diferencia<index;diferencia++)      //O(n);
            if (auxPunt!=NULL)                              //O(1);
                auxPunt = auxPunt->sig;                     //O(1);
    if (diferencia==index)      //O(1);
        return auxPunt->elem;   //O(1);
}


template <typename generico> generico Lista<generico>::mostrarElemento(){   //O(1);
    nodoLista*auxPunt;      //O(1);
    auxPunt=dato;           //O(1);
    if (auxPunt!=NULL)      //O(1);
        return auxPunt->elem;       //O(1);
    else{                   //O(1);
        dato=punteroLista;  //O(1);
         return NULL;       //O(1);
    }
}

template <typename generico> void Lista<generico>::siguiente(){     //O(1);
    if (punteroLista==NULL)     //O(1);
        punteroLista=dato;      //O(1);
    nodoLista * auxPunt;        //O(1);
    auxPunt =dato;              //O(1);
     if (auxPunt->sig!=NULL){   //O(1);
        auxPunt = auxPunt->sig; //O(1);
        dato = auxPunt;         //O(1);
    }
    else                        //O(1);
        dato=NULL;              //O(1);
}



template <typename generico> bool Lista<generico>::existeElemento(const generico & elem) const{ //O(n);
    nodoLista * auxPunt;        //O(1);
    auxPunt = dato;             //O(1);
    if (auxPunt==NULL)          //O(1);
        return false;           //O(1);
    else                            //O(n);
    while (auxPunt!=NULL){          //O(n);
        if (auxPunt->elem = elem)   //O(1);
            return true;            //O(1);
        else                        //O(1);
            auxPunt= auxPunt->sig;  //O(1);
    }
}



template <typename generico> void Lista<generico>::vaciar(){    //O(n);
    nodoLista * aux;            //O(1);
    while (dato !=NULL){        //O(n);
        aux = dato -> sig;      //O(1);
        delete dato;            //O(1);
        dato = aux;             //O(1);
    }
    dato=NULL;                  //O(1);
}


template class Lista<unsigned int>;
