#include <iostream>
#include "ListaDuplamenteEncadeada.h"

using namespace std;

int main()
{
    ListaSimplesmenteEncadeada<int> lista1;
    cria(lista1);

    insere(lista1, 10, 1);
    mostra(lista1);
    cout << endl;
    insere(lista1, 20, 2);
    mostra(lista1);
    cout << endl;
    insere(lista1, 30, 3);
    mostra(lista1);
    cout << endl;

    retira(lista1, 1);
    mostra(lista1);
    cout << endl;
    retira(lista1, 1);
    mostra(lista1);
    cout << endl;

    cout << "eh vazia = " << ehVazia(lista1) << endl;

    cout << "25 estah na lista? ";

    existeElemento(lista1, 25)? cout<< "sim": cout << "nao" << endl;

    ListaSimplesmenteEncadeada<char> lista2;

    cria(lista2);

    for (int i = 65; i <= 90; i++)
        insere(lista2, char(i), numeroDeElementos(lista2) + 1);
    mostra(lista2);

    destroi(lista1);

    cout << endl;

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
