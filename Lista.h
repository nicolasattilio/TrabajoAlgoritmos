#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

template <typename generico>
class Lista
{
    public:
        Lista();
        ~Lista();
        void agregarPrincipio(const generico & elem);
        void agregarFinal(const generico & elem);
        void agregarArbitrariamente(const generico & elem, int index);
        unsigned int cantElemento();
        bool existeElemento(const generico & elem) const;
        bool esVacia();
        void eliminarElemento(const generico & elem);
        void eliminartodo();
        void mostrar(int index);  //Consultar

    private:
        struct nodoLista{
        generico elem;
        nodoLista * sig;
        };
        nodoLista * dato;
        void vaciar();
};


#endif // LISTA_H_INCLUDED
