#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

template <typename T>
class Matriz
{
public:
  Matriz(int tamanio);                                          //O(n)
  ~Matriz();                                                    //O(1)
  void setvalue(int i,int j,T elemento);                        //O(1)
  T getvalue(int i,int j);                                      //O(1)
  void multi(Matriz MatrizA,Matriz MatrizB);                    //O(n^3)
  void suma(Matriz MatrizX,Matriz MatrizY,int longitud);        //O(n^2)
  void resta(Matriz MatrizX,Matriz MatrizY,int longitud);       //O(n^2)
private:
    T** matrix;
  //void eliminar(int tamanio);                                   //O(n)

};



#endif // MATRIZ_H_INCLUDED
