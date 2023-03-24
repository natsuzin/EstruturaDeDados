#ifndef LISTADUPLAMENTEENCADEADA_H_INCLUDED
#define LISTADUPLAMENTEENCADEADA_H_INCLUDED

#include <iostream>

using namespace std;

template <typename T>
struct Nodo {
    T elemento;
    Nodo<T>* proximo;
    Nodo<T>* anterior;
};

template<typename T>
struct ListaDuplamenteEncadeada
{
    int cardinalidade;
    Nodo<T>* inicio;
    Nodo<T>* fim;
};

template<typename T>
void cria(ListaDuplamenteEncadeada<T> &lista)
{
    lista.cardinalidade = 0;
    lista.inicio = NULL;
    lista.fim = NULL;
}

template<typename T>
int ehVazia(ListaDuplamenteEncadeada<T> lista)
{
    return lista.cardinalidade == 0;
}

template<typename T>
int numeroDeElementos(ListaDuplamenteEncadeada<T> lista)
{
    return lista.cardinalidade;
}

template<typename T>
bool existeElemento(ListaDuplamenteEncadeada<T> lista, T elemento)
{
    Nodo<T> *p = lista.inicio;
    while(p != NULL)
    {
        if(p->elemento == elemento)
            return true;
        p = p->proximo;
    }
    return false;
}

template<typename T>
bool validaPosicao(ListaDuplamenteEncadeada<T> lista, int posicao)
{
    return (posicao >= 1) && (posicao <= lista.cardinalidade);
}

template<typename T>
T recuperaElemento(ListaDuplamenteEncadeada<T> lista, int posicao)
{
    Nodo<T> *p = lista.inicio;
    int contador = 1;
    if(posicao < 1 || posicao > lista.cardinalidadde)
        throw "Posicao invalida";
    while(p != NULL)
    {
        if(contador == posicao)
            return p->elemento;
        p = p->proximo;
        contador++;
    }
}

template<typename T>
int posicao(ListaDuplamenteEncadeada<T> lista, T elemento)
{
    Nodo<T> *p = lista.inicio;
    int contador = 1;
    if(!existeElemento(lista,elemento))
        throw "Elemento inexistente";
    while(p != NULL)
    {
        if(p->elemento == elemento)
            return contador;
        p = p->proximo;
        contador++;
    }
}

template<typename T>
void insere(ListaDuplamenteEncadeada<T> &lista, T elemento, int posicao)
{
    if(posicao < 1 || posicao > lista.cardinalidade + 1)
        throw "POSICAO INVALIDA";


    Nodo<T>* q = new Nodo<T>;
    q->elemento = elemento;
    q->proximo = NULL;
    q->anterior = NULL;
    if (lista.inicio == NULL){
        lista.inicio = q;
        lista.fim = q;
    }
    else
    {
        Nodo<T>* p = lista.inicio;
        if (posicao == 1){
            q->proximo = lista.inicio;
            p->anterior = q;
            lista.inicio = q;
        }
        else{
            int contador = 1;
            while (contador != posicao - 1){
                p = p->proximo;
                contador++;
            }
            q->proximo = p->proximo;
            p->proximo = q;
            q->anterior = p;
            p->proximo = q->proximo;
            p->anterior = q;
        }
    }
    lista.cardinalidade++;
}

template<typename T>
void retira (ListaDuplamenteEncadeada<T> &lista, int posicao)
{
    if(lista.cardinalidade == 0)
        throw "UNDERFLOW";

    if(posicao < 1 || posicao > lista.cardinalidade)
        throw "POSICAO INVALIDA";

    Nodo<T>* q = lista.inicio;
    if (posicao == 1)
        lista.inicio = lista.inicio->proximo;
    else
    {
        Nodo<T>* p = lista.inicio;
        int contador = 1;
        while (contador != posicao - 1)
        {
            p = p->proximo;
            contador++;
        }
        q = p->proximo;
        p->proximo = q->proximo;
    }
    delete q;
    lista.cardinalidade--;
    }


template<typename T>
void mostra(ListaDuplamenteEncadeada<T> lista){
    Nodo<T> *p = lista.inicio;
    while (p != NULL){
        cout << "[" << p->elemento << "]";
        p = p->proximo;
    }
}

template<typename T>
void destroi(ListaDuplamenteEncadeada<T> &lista)
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



#endif // LISTADUPLAMENTEENCADEADA_H_INCLUDED
