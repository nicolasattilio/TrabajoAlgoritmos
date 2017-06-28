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
  void suma(int i,int j,int k,int l,T & value);
  void resta(int i,int j,int k,int l,T & value);
  //void subMatrix(

private:
    T** matrix;

};



#endif // MATRIZ_H_INCLUDED
