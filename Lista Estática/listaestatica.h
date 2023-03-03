#ifndef LISTAESTATICA_H_INCLUDED
#define LISTAESTATICA_H_INCLUDED

struct ListaEstatica
{
  int n, elementos[];
};

void criaLista(ListaEstatica& v)
{
    v.n=0;
};

bool verificaListaVazia(ListaEstatica v)
{
    if(v.n==0) return true;
    else return false;
};

bool verificaEspaço(ListaEstatica v)
{
    if(v.n<10) return true;
    else return false;
};

int recuperaNumeroElementos(ListaEstatica v)
{
    return v.n;
};

bool verificaElemento(ListaEstatica v, int elem)
{
    for(unsigned int i = 0; i < v.n; i++)
        if(v.elementos[i]==elem)
            return true;
    return false;
};

bool verificaSePosicaoValida(ListaEstatica v, int pos)
{
    if(pos>v.n)
        return false;
    return true;
};

int recuperaElemento(ListaEstatica& v, int elem)
{
    for(unsigned int i = 0; i < v.n; i++)
        if(v.elementos[i]==elem)
            return elem;
    else return 0;
};

int recuperaPosicaoElemento(ListaEstatica v, int elem)
{
    for(unsigned int i = 0; i < v.n; i++)
        if(v.elementos[i]==elem)
            return i;
    else return 0;
};

void insereElementoInicio(ListaEstatica& v, int elem, int pos)
{
    for(unsigned int i = 0; i < v.n; i++){
        if(i==pos){
            for(unsigned int j = v.n - 1; j > i; j++){
                v.elementos[j]=v.elementos[i];
            }
            v.elementos[i]=elem;
        }
        break;
    }
    v.n++;
};

void insereElementoFinal(ListaEstatica& v, int elem)
{
    v.elementos[v.n++]=elem;
};

void exclueElemento(ListaEstatica& v)
{
    v.elementos[v.n--];
};

void mostraLista(ListaEstatica v)
{
    for(unsigned int i = 0; i < v.n; i++)
        cout << v.elementos[i];
};

#endif // LISTAESTATICA_H_INCLUDED
