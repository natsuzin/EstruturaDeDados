#ifndef LISTASIMPLESMENTEENCADEADA_H_INCLUDED
#define LISTASIMPLESMENTEENCADEADA_H_INCLUDED

#include <iostream>

using namespace std;

template <typename T>
struct Nodo {
    T elemento;
    Nodo<T>* proximo;
};

template<typename T>
struct ListaSimplesmenteEncadeada
{
    int cardinalidade;
    Nodo<T>* inicio;
};

template<typename T>
void cria(ListaSimplesmenteEncadeada<T> &lista)
{
    lista.cardinalidade = 0;
    lista.inicio = NULL;
}

template<typename T>
int ehVazia(ListaSimplesmenteEncadeada<T> lista)
{
    return lista.cardinalidade == 0;
}

template<typename T>
int numeroDeElementos(ListaSimplesmenteEncadeada<T> lista)
{
    return lista.cardinalidade;
}

template<typename T>
bool existeElemento(ListaSimplesmenteEncadeada<T> lista, T elemento)
{
    Nodo<T> *p = lista;
    while(p != NULL)
    {
        if(p->elemento == elemento)
            return true;
        p = p->proximo;
    }
    return false;
}

template<typename T>
bool validaPosicao(ListaSimplesmenteEncadeada<T> lista, int posicao)
{
    return (posicao >= 1) && (posicao <= lista.cardinalidade);
}

template<typename T>
T recuperaElemento(ListaSimplesmenteEncadeada<T> lista, int posicao)
{
    Nodo<T> *p = lista;
    int contador = 1;
    if(posicao < 1 || posicao > lista.cardinalidadde)
        throw "Posicao invalida"
    while(p != NULL)
    {
        if(contador == posicao)
            return p->elemento;
        p = p->proximo;
        contador++;
    }
}

template<typename T>
int posicao(ListaSimplesmenteEncadeada<T> lista, T elemento)
{
    Nodo<T> *p = lista;
    int contador = 1;
    while(p != NULL)
    {
        if(p->elemento == elemento)
            return contador;
        p = p->proximo;
        contador++;
    }
    throw "Elemento inexistente";
}

template<typename T>
void insere(ListaSimplesmenteEncadeada<T> &lista, T elemento)
{
    Nodo<T> *panterior, *p = new Nodo;
    p->elemento = elemento;
    p->proximo = NULL;
    if (lista.inicio == NULL)
    {
        *lista = p;
        lista.cardinalidade++;
        return;
    }
    panterior = ;
    while (panterior->proximo != NULL)
        panterior = panterior->prox;
    panterior->proximo = p;
    lista.cardinalidade++;
}

template<typename T>
void exibelista(Nodo<T> *p){
    while (p != NULL){
        cout << "[" << p->elemento << "]";
        p = p->proximo;
    }
}

template<typename T>
void destroi(ListaSimplesmenteEncadeada<T> &lista)
{
    Nodo<T> *p;
    while (lista.inicio != NULL)
    {
        p = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        delete p;
    }
    lista.cardinalidade = 0;
}


#endif // LISTASIMPLESMENTEENCADEADA_H_INCLUDED
