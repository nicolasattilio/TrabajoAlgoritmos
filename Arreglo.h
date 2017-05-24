#ifndef ARREGLO_H_INCLUDED
#define ARREGLO_H_INCLUDED

template <typename generico>
class Arreglo
{
    public:
        Arreglo();
        ~Arreglo();
        void agregarArreglo(const generico & elem, int index);
        unsigned int longArreglo();
        generico darElemento(int index)const;

    private:
        struct nodoArreglo{
        generico elem;
        nodoArreglo*sig;
        nodoArreglo*ant;
        };
        nodoArreglo*dato;
        void vaciar();
};

#endif // ARREGLO_H_INCLUDED
