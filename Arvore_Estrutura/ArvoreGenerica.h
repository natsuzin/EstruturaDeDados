#ifndef ARVOREGENERICA_H_INCLUDED
#define ARVOREGENERICA_H_INCLUDED

using namespace std;

template<typename T>
struct Nodo
{
    int chave;
    T elemento;
    struct Nodo* esquerda;
    struct Nodo* direita;
};

template<typename T>
struct Arvore
{
    int cardinalidade;
    Nodo<T>* raiz;
};

template<typename T>
void cria(Arvore<T> &lista)
{
    lista.cardinalidade = 0;
    lista.raiz = NULL;
}

template<typename T>
bool ehVazia(Arvore<T> lista)
{
    return lista.cardinalidade == 0;
}

template<typename T>
int numeroDeElementos(Arvore<T> lista)
{
    return lista.cardinalidade;
}

template<typename T>
Nodo<T>* criaNodo(T valor)
{
    Nodo<T>* novo = new Nodo<T>();
    novo->elemento = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

template<typename T>
void insere(Arvore<T>& arvore, T elemento)
{
    if (arvore.raiz == NULL)
    {
        arvore.raiz = criaNodo(elemento);
        return;
    }
    Nodo<T>* atual = arvore.raiz;
    while(atual != NULL)
    {
        if (elemento < atual->elemento)
        {
            if (atual->esquerda == NULL)
            {
                atual->esquerda = criaNodo(elemento);
                return;
            }
            atual = atual->esquerda;
        }
        else
        {
            if (elemento > atual->elemento)
            {
                if (atual->direita == NULL)
                {
                    atual->direita = criaNodo(elemento);
                    return;
                }
                atual = atual->direita;
            }
            else return;
        }
    }
}
template<typename T>
void destroiArvore(Nodo<T>* q)
{
    if(q->esquerda != NULL)
    {
        destroiArvore(q->esquerda);
    }
    else if(q->direita != NULL)
    {
        destroiArvore(q->direita);
    }
    else
    {
        delete q;
    }
}
/*
template<typename T>
void retiraAux(Nodo<T> *p, T elemento)
{
    Nodo<T> *q;
    if(elemento < p->elemento)
        retiraAux(p->esquerda, elemento);
    else
    {
        if(elemento > p->elemento)
            retiraAux(p->direita, elemento);
        else
        {
            q = p;
            if(q->direita == NULL)
                p = q->esquerda;
            else
            {
                if(q->esquerda == NULL)
                    p = q->direita;
                else
                {
                    Nodo<T> *r = q;
                    while(r->direita != NULL)
                    {
                        if(r->direita == NULL)
                        {
                            q->elemento = r->elemento;
                            q = r;
                            r = r->direita;
                        }
                        r = r->direita;
                    }
                }
            }
            delete q;
        }
    }
}

template<typename T>
void retira(Arvore<T> &arvore, T elemento)
{
    retiraAux(arvore.raiz, elemento);
    arvore.cardinalidade--;
}
*/
template<typename T>
void destroi(Arvore<T> &arvore)
{
    destroiArvore(arvore.raiz);
    arvore.cardinalidade = 0;
}

template<typename T>
void mostraArvore(Nodo<T> *p)
{
    if(p != NULL)
    {
        cout<<"["<<p->elemento<<"]"<<endl;
        mostraArvore(p->esquerda);
        mostraArvore(p->direita);
    }
}

template<typename T>
void mostra(Arvore<T> arvore)
{
    mostraArvore(arvore.raiz);
}

#endif // ARVOREGENERICA_H_INCLUDED
