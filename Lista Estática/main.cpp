#include "listaestatica.h"
#include <iostream>

using namespace std;

int main()
{
    ListaEstatica lista;
    int elem, pos;

    criaLista(lista);
    while(elem!=-1){
        cout << "elemento: ";
        cin >> elem;
        if(elem==-1)
            break;
        cout << "posicao: ";
        cin >> pos;
        insereElemento(lista,elem,pos);
    }
    mostraLista(lista);




    return 0;
}
