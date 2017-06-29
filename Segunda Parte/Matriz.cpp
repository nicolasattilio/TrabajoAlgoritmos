#include "Matriz.h"
#include <cstddef>



template <typename T>
Matriz<T>::Matriz(int tamanio){                                                 //O(n)
    this->matrix = new int*[tamanio];                                           //O(1)
    for(int i = 0; i < tamanio; ++i)                                            //O(n)
        this->matrix[i] = new int[tamanio];                                     //O(1)
    this->matrix[0][0];                                                         //O(1)
}

template <typename T>
Matriz<T>::~Matriz(){                                                           //O(1)
    //int tamanio;                                                                //O(1)
    //eliminar(tamanio);                                                          //O(1)
}

/*template <typename T>
void Matriz<T>::eliminar(int tamanio){                                          //O(n)
for (int i=0;i<tamanio;i++)                                                     //O(n)
    delete [] this->matrix[i];                                                  //O(1)
delete[] this->matrix ;                                                         //O(1)
}*/

template <typename T>
void Matriz<T>::setvalue(int i,int j,T elemento){                               //O(1)
    this->matrix[i][j]=elemento;                                                //O(1)
}

template <typename T>
T Matriz<T>::getvalue(int i,int j){                                             //O(1)
    return this->matrix[i][j];                                                  //O(1)
}



template <typename T>
void Matriz<T>::suma(Matriz MatrizX,Matriz MatrizY,int longitud){               //O(n^2)
       for(int i=0; i<longitud; i++) {                                          //O(n^2)
        for(int j=0; j<longitud; j++) {                                         //O(n)
           this->setvalue(i,j,(MatrizX.getvalue(i,j)+MatrizY.getvalue(i,j)));   //O(1)
        }
     }
}

template <typename T>
void Matriz<T>::resta(Matriz MatrizX,Matriz MatrizY,int longitud){              //O(n^2)
    for(int i=0; i<longitud; i++) {                                             //O(n^2)
        for(int j=0; j<longitud; j++) {                                         //O(n)
           this->setvalue(i,j,(MatrizX.getvalue(i,j)-MatrizY.getvalue(i,j)));   //O(1)
        }
     }
}


template <typename T>
void Matriz<T>::multi(Matriz MatrizA,Matriz MatrizB){   //O(n^3)
  for(int i=0; i<2; i++)                                //O(n^3)
        for(int j=0; j<2; j++) {                        //O(n^2)
           this->setvalue(i,j,0);                       //O(1)
           for(int t=0; t<2; t++)                       //O(n)
              this->setvalue(i,j,(this->getvalue(i,j) + MatrizA.getvalue(i,t)*MatrizB.getvalue(t,j)));  //O(1)
           }
}

template class Matriz<int>;
