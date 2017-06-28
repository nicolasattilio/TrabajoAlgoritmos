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
void Matriz<T>::suma(int i,int j,int k,int l,T & value){
    value=this->getvalue(i,j)+this->getvalue(k,l);
}

template <typename T>
void Matriz<T>::resta(int i,int j,int k,int l,T & value){
    value=this->getvalue(i,j)-this->getvalue(k,l);
}


/*
template <typename T>
void Matriz<T>::resta(T & MatrizA, T & MatrizC, int nFilas,int nColum){
   for(int i=0;i<nFilas;i++){
    for(int j=0;j<Matriz<int> MatrizA;
    Matriz<int> MatrizB;
    Matriz<int> MatrizC;nColum;j++)
        MatrizC = (*(*Mat+i)+j) - (*(*MatrizA+i)+j);

    }
}

template <typename T>
void Matriz<T>::multi(T & MatrizA, T & MatrizC, int nFilas, int nColum){
  for(int i=0;i<nFilas;i++)
    for(int j=0;j<nColum;j++)
      MatrizC = (*(*Mat+i)+j) * (*(*MatrizA+i)+j);
    }
*/
template class Matriz<int>;
