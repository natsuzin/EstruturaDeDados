#include <iostream>
#include "ListaDuplamenteEncadeada.h"

using namespace std;

int main()
{
    ListaDuplamenteEncadeada<int> lista1;
    cria(lista1);

    insere(lista1, 10, 1);
    mostra(lista1);
    insere(lista1, 20, 2);
    mostra(lista1);
    insere(lista1, 30, 3);
    mostra(lista1);
    insere(lista1, 40, 4);
    mostra(lista1);
    insere(lista1, 50, 5);
    mostra(lista1);
    retira(lista1, 1);
    mostra(lista1);
    retira(lista1, 3);
    mostra(lista1);

    cout << "e vazia = " << ehVazia(lista1) << endl;

    cout << "40 esta na lista? ";

    existeElemento(lista1, 40)? cout << "sim": cout << "nao" << endl;

    try
    {
        cout << recuperaElemento(lista1, 1);
    }
    catch (const char* msg)
    {
        cerr << msg << endl;
    }

    cout << endl;

    try
    {
        cout << recuperaPosicao(lista1,30);
    }
    catch (const char* msg)
    {
        cerr << msg << endl;
    }

    cout << endl;
    ListaDuplamenteEncadeada<char> lista2;

    cria(lista2);

    for (int i = 65; i <= 90; i++)
        insere(lista2, char(i), numeroDeElementos(lista2) + 1);
    mostra(lista2);

    destroi(lista1);

    try
    {
        retira (lista1, 10);
    }
    catch (const char* msg)
    {
        cerr << msg << endl;
    }
    destroi(lista2);

    return 0;
}
