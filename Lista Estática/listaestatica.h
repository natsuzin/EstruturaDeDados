#ifndef LISTAESTATICA_H_INCLUDED
#define LISTAESTATICA_H_INCLUDED
#include <iostream>

using namespace std;

struct ListaEstatica
{
  int n, elementos[]; // onde n é a cardinalidade e elementos[] é o vetor
};

void criaLista(ListaEstatica& v)
{
    v.n=0;
}

bool verificaListaVazia(ListaEstatica v)
{
    if(v.n==0) return true;
    else return false;
}

bool verificaEspaco(ListaEstatica v)
{
    if(v.n<10) return true;
    else return false;
}

int recuperaNumeroElementos(ListaEstatica v)
{
    return v.n;
}

bool verificaElemento(ListaEstatica v, int elem)
{
    for(unsigned int i = 0; i < v.n; i++)
        if(v.elementos[i]==elem)
            return true;
    return false;
}

bool verificaSePosicaoValida(ListaEstatica v, int pos)
{
    if(pos>v.n)
        return false;
    return true;
}

int recuperaElemento(ListaEstatica& v, int elem)
{
    for(unsigned int i = 0; i < v.n; i++)
        if(v.elementos[i]==elem)
            return elem;
    else return 0;
}

int recuperaPosicaoElemento(ListaEstatica v, int elem)
{
    for(unsigned int i = 0; i < v.n; i++)
        if(v.elementos[i]==elem)
            return i;
    else return 0;
}

void insereElemento(ListaEstatica& v, int elem, int pos)
{
    for(unsigned int i = 0; i < v.n; i++){
        if(v.n==0){
            v.elementos[v.n]=elem;
            break;
        }
        if(i==pos){
            for(unsigned int j = v.n - 1; j > i; j++){
                v.elementos[j]=v.elementos[pos];
            }
            v.elementos[i]=elem;
            break;
        }
        v.elementos[++i]=elem;
    }
    v.n++;
}



void excluiElemento(ListaEstatica& v, int elem, int pos)
{
    for(unsigned int i = 0; i < v.n; i++){
        if(i==pos){
            for(unsigned int j = i + 1; j < v.n; j++){
                v.elementos[j]=v.elementos[i];
            }
            v.elementos[i]=elem;
        }
        break;
    }
    v.n--;
}

void excluiElemento(ListaEstatica& v)
{
    v.elementos[v.n--];
}

void mostraLista(ListaEstatica v)
{
    for(unsigned int i = 0; i < v.n; i++)
        cout << "[" << v.elementos[i] << "]";
}

#endif // LISTAESTATICA_H_INCLUDED
