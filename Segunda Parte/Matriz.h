#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

template <typename T>
class Matriz
{
public:
  Matriz(int tamanio);
  ~Matriz();
  void setvalue(int i,int j,T elemento);
  T getvalue(int i,int j);
  void multi(Matriz MatrizA,Matriz MatrizB);
  void suma(Matriz MatrizX,Matriz MatrizY,int longitud);
  void resta(Matriz MatrizX,Matriz MatrizY,int longitud);
private:
    T** matrix;

};



#endif // MATRIZ_H_INCLUDED
