#ifndef LISTAESTATICA_H_INCLUDED
#define LISTAESTATICA_H_INCLUDED
#include <iostream>

using namespace std;

struct ListaEstatica
{
  int n, elementos[10];
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
    if(pos<10)
        return true;
    return false;
}

int recuperaElemento(ListaEstatica& v, int pos)
{
    for(int i = 0; i < v.n; i++)
        if(i==pos)
            return v.elementos[pos];
    else return -1;
}

int recuperaPosicaoElemento(ListaEstatica v, int elem)
{
    for(int i = 0; i < v.n; i++)
        if(v.elementos[i]==elem)
            return i;
    else return -1;
}

void insereElemento(ListaEstatica& v, int elem, int pos)
{
    for(int i=0;i<v.n;i++){
        if(pos==i){
            for (int j=v.n; j>=pos; j--)
                v.elementos[j]=v.elementos[j-1];
            v.elementos[pos-1]=elem;
            v.n++;
            break;
        }
    }
}

void retiraElemento(ListaEstatica& v, int elem)
{
    for(int i=0; i<v.n; i++){
        if(v.elementos[i]==elem){
             for(int j=i;j<v.n;j++){
                v.elementos[j]=v.elementos[++i];
                v.n--;
                break;
            }
        }
        break;
    }
}

void exibeLista(ListaEstatica v)
{
    for(int i=0; i<v.n; i++)
        cout << "[" << v.elementos[i] << "]" << endl;
}

#endif // LISTAESTATICA_H_INCLUDED
