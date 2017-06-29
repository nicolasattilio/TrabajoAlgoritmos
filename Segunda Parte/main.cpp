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
        int r=rand() % 10;
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




void Strassen(Matriz<int> MatrizA,Matriz<int> MatrizB,Matriz<int> & MatrizC,int longitud){
    Matriz<int> A11(longitud);Matriz<int> A12(longitud);Matriz<int> A21(longitud);Matriz<int> A22(longitud);
    Matriz<int> B11(longitud);Matriz<int> B12(longitud);Matriz<int> B21(longitud);Matriz<int> B22(longitud);
    Matriz<int> C11(longitud);Matriz<int> C12(longitud);Matriz<int> C21(longitud);Matriz<int> C22(longitud);
    Matriz<int> M1(longitud);Matriz<int> M2(longitud);Matriz<int> M3(longitud);Matriz<int> M4(longitud);Matriz<int> M5(longitud);Matriz<int> M6(longitud);Matriz<int> M7(longitud);
    Matriz<int> AA(longitud);Matriz<int> BB(longitud);
if (longitud==2){
    MatrizC.multi(MatrizA,MatrizB);
}else{
    for(int i=0; i<longitud/2; i++){
           for(int j=0; j<longitud/2; j++) {
                A11.setvalue(i,j,(MatrizA.getvalue(i,j)));
                A12.setvalue(i,j,(MatrizA.getvalue(i,j+longitud/2)));
                A21.setvalue(i,j,(MatrizA.getvalue(i+longitud/2,j)));
                A22.setvalue(i,j,(MatrizA.getvalue(i+longitud/2,j+longitud/2)));

                B11.setvalue(i,j,(MatrizB.getvalue(i,j)));
                B12.setvalue(i,j,(MatrizB.getvalue(i,j+longitud/2)));
                B21.setvalue(i,j,(MatrizB.getvalue(i+longitud/2,j)));
                B22.setvalue(i,j,(MatrizB.getvalue(i+longitud/2,j+longitud/2)));
                }

        }
    AA.suma(A11,A22,longitud/2);
    BB.suma(B11,B22,longitud/2);
    Strassen(AA,BB,M1,longitud/2);

    AA.suma(A21,A22,longitud/2);
    Strassen(AA,B11,M2,longitud/2);

    BB.resta(B12,B22,longitud/2);
    Strassen(A11,BB,M3,longitud/2);

    BB.resta(B21,B11,longitud/2);
    Strassen(A22,BB,M4,longitud/2);

    AA.suma(A11,A12,longitud/2);
    Strassen(AA,B22,M5,longitud/2);

    AA.suma(A21,A11,longitud/2);
    BB.resta(B11,B12,longitud/2);
    Strassen(AA,BB,M6,longitud/2);

    AA.resta(A12,A22,longitud/2);
    BB.suma(B21,B22,longitud/2);
    Strassen(AA,BB,M7,longitud/2);

    ///-------------------///

    AA.suma(M1,M4,longitud/2);
    BB.resta(M7,M5,longitud/2);
    C11.suma(AA,BB,longitud/2);

    C12.suma(M3,M5,longitud/2);

    C21.suma(M2,M4,longitud/2);

    AA.resta(M1,M2,longitud/2);
    BB.suma(M3,M6,longitud/2);
    C22.suma(AA,BB,longitud/2);

    for(int i=0; i<longitud/2; i++) {
           for(int j=0; j<longitud/2; j++) {
              MatrizC.setvalue(i,j,C11.getvalue(i,j));
              MatrizC.setvalue(i,j+longitud/2,C12.getvalue(i,j));
              MatrizC.setvalue(i+longitud/2,j,C21.getvalue(i,j));
              MatrizC.setvalue(i+longitud/2,j+longitud/2,C22.getvalue(i,j));
           }
        }



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
//addElementsMatrix(MatrizB,longitud);
fillMatrix(MatrizA,longitud);
fillMatrix(MatrizB,longitud);
Strassen(MatrizA,MatrizB,MatrizC,longitud);

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
