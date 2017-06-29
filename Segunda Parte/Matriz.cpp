#include "Matriz.h"
#include <cstddef>



template <typename T>
Matriz<T>::Matriz(int tamanio){
    this->matrix = new int*[tamanio];
    for(int i = 0; i < tamanio; ++i)
        this->matrix[i] = new int[tamanio];

    this->matrix[0][0];
}

template <typename T>
Matriz<T>::~Matriz(){
//Constructor con delete?
}

template <typename T>
void Matriz<T>::setvalue(int i,int j,T elemento){
    this->matrix[i][j]=elemento;
}

template <typename T>
T Matriz<T>::getvalue(int i,int j){
    return this->matrix[i][j];
}



template <typename T>
void Matriz<T>::suma(Matriz MatrizX,Matriz MatrizY,int longitud){
       for(int i=0; i<longitud; i++) {
        for(int j=0; j<longitud; j++) {
           this->setvalue(i,j,(MatrizX.getvalue(i,j)+MatrizY.getvalue(i,j)));
        }
     }
}

template <typename T>
void Matriz<T>::resta(Matriz MatrizX,Matriz MatrizY,int longitud){
    for(int i=0; i<longitud; i++) {
        for(int j=0; j<longitud; j++) {
           this->setvalue(i,j,(MatrizX.getvalue(i,j)-MatrizY.getvalue(i,j)));
        }
     }
}


template <typename T>
void Matriz<T>::multi(Matriz MatrizA,Matriz MatrizB){
  for(int i=0; i<2; i++)
        for(int j=0; j<2; j++) {
           this->setvalue(i,j,0);
           for(int t=0; t<2; t++)
              this->setvalue(i,j,(this->getvalue(i,j) + MatrizA.getvalue(i,t)*MatrizB.getvalue(t,j)));
           }
}

template class Matriz<int>;
