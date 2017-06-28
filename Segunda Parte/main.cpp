#include <iostream>
#include "Matriz.h"
#include <math.h>
#include <cstdlib>

using namespace std;

void addElementsMatrix(Matriz<int> & MatrizA,int longitud){
for(int i=0;i<longitud;i++)
    for(int j=0;j<longitud;j++){
        int value=0;
        cout<<"ingrese valor a la matriz"<<endl;
        cin>>value;
        MatrizA.setvalue(i,j,value);
        }
}

void fillMatrix(Matriz<int> & MatrizA,int longitud){
for(int i=0;i<longitud;i++)
    for(int j=0;j<longitud;j++){
        int r=rand() % 100;
        MatrizA.setvalue(i,j,r);
        }
}

void showMatrix(Matriz<int> MatrizA,int longitud){
cout<<endl;
cout<<endl;
for(int i=0;i<longitud;i++){
    cout<<" "<<endl;
    for(int j=0;j<longitud;j++)
        cout<<MatrizA.getvalue(i,j)<<" ";

}
}

void strassen(Matriz<int> MatrizA,Matriz<int> MatrizB,Matriz<int> & MatrizC){
int t;
int r;
//BLOQUE 1
MatrizA.suma(0,0,1,1,t);
MatrizB.suma(0,0,1,1,r);
int I=t*r;
//FIN BLOQUE 1
//BLOQUE 2
MatrizA.suma(1,0,1,1,t);
r=MatrizB.getvalue(0,0);
int II=t*r;
//FIN BLOQUE 2
//BLOQUE 3
r=MatrizA.getvalue(0,0);
MatrizB.resta(0,1,1,1,t);
int III=t*r;
//FIN BLOQUE 3
//BLOQUE 4
r=MatrizA.getvalue(1,1);
MatrizB.resta(1,0,0,0,t);
int IV=t*r;
//FIN BLOQUE 4
//BLOQUE 5
MatrizA.suma(0,0,0,1,t);
r=MatrizB.getvalue(1,1);
int V=t*r;
//FIN BLOQUE 5
//BLOQUE 6
MatrizA.resta(1,0,0,0,t);
MatrizB.suma(0,0,0,1,r);
int VI=t*r;
//FIN BLOQUE 6
//BLOQUE 7
MatrizA.resta(0,1,1,1,t);
MatrizB.suma(1,0,1,1,r);
int VII=t*r;
//FIN BLOQUE 7

MatrizC.setvalue(0,0,(I+IV-V+VII));
MatrizC.setvalue(0,1,(III+V));
MatrizC.setvalue(1,0,(II+IV));
MatrizC.setvalue(1,1,(I+III-II+VI));

}

void divideAndConquestMatrix(Matriz<int> MatrizA,Matriz<int> MatrizB,Matriz<int> & MatrizC,int longitud){
if (longitud<=2)
    strassen(MatrizA,MatrizB,MatrizC);
else{
    /*divideAndConquestMatrix(MatrizA.subMatriz(A11),MatrizB.subMatriz(B11),matrizC,longitud-2);
    divideAndConquestMatrix(MatrizA.subMatriz(A12),MatrizB.subMatriz(B12),matrizC,longitud-2);
    divideAndConquestMatrix(MatrizA.subMatriz(A21),MatrizB.subMatriz(B21),matrizC,longitud-2);
    divideAndConquestMatrix(MatrizA.subMatriz(A22),MatrizB.subMatriz(B22),matrizC,longitud-2);*/
}
}

int main(){
int k=0;
cout<<"Tamanio de la matriz ";
cin>>k;
int longitud=pow(2,k);
Matriz<int> MatrizA(longitud);
Matriz<int> MatrizB(longitud);
Matriz<int> MatrizC(longitud);
//addElementsMatrix(MatrizA,longitud);
fillMatrix(MatrizA,longitud);
fillMatrix(MatrizB,longitud);
//addElementsMatrix(MatrizB,longitud);
divideAndConquestMatrix(MatrizA,MatrizB,MatrizC,longitud);

showMatrix(MatrizA,longitud);
cout<<"       <-- Matriz A";
showMatrix(MatrizB,longitud);
cout<<"       <-- Matriz B";
showMatrix(MatrizC,longitud);
cout<<"       <-- Matriz C";
cout<<endl;
cout<<endl;
return 0;
}
