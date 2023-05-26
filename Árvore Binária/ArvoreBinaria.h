#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED

#include <iostream>

using namespace std;

template <typename T>
struct Nodo {
    T elemento;
    Nodo<T>* direita;
    Nodo<T>* esquerda;
};

template<typename T>
struct ArvoreBinaria
{
    int cardinalidade;
    Nodo<T>* raiz;
};

template<typename T>
void cria(ArvoreBinaria<T> &arvore)
{
    arvore.cardinalidade = 0;
    arvore.raiz = NULL;
}

template<typename T>
int ehVazia(ArvoreBinaria<T> arvore)
{
    return arvore.cardinalidade == 0;
}

template<typename T>
int numeroDeElementos(ArvoreBinaria<T> arvore)
{
    return arvore.cardinalidade;
}

template<typename T>
void insereNaArvore(T elemento, Nodo<T> &p)
{
    if(p == NULL)
    {
        p->elemento = elemento;
        p->esquerda = NULL;
        p->direita = NULL;
    }
    else
    {
        if(elemento < p->elemento)
        {
            insereNaArvore(elemento, p->esquerda);
        }
        else
        {
            insereNaArvore(elemento, p->direita);
        }
    }
}

template<typename T>
void insere(ArvoreBinaria<T> &arvore, T elemento)
{

    Nodo<T>* p = new Nodo<T>;

    insereNaArvore(elemento, p);
    arvore = p;

    arvore.cardinalidade++;
}

/*
template<typename T>
void retiraDaArvore(T elemento, Nodo<T> &p)
{

}
*/


template<typename T>
void mostra(ArvoreBinaria<T> arvore)
{


    for (Nodo<T>* p = arvore.raiz; p != NULL; p = p->esquerda)
        cout << "[" << p->elemento << "]";
    cout << endl;
}


template<typename T>
void destroi(ArvoreBinaria<T> &arvore)
{
    Nodo<T> *p;
    while (arvore.raiz != NULL)
    {
        p = arvore.raiz;
        arvore.raiz = arvore.raiz->proximo;
        delete p;
    }
    arvore.cardinalidade = 0;
}



#endif // ARVOREBINARIA_H_INCLUDED
