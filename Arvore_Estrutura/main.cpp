#include <iostream>
#include "ArvoreGenerica.h"

using namespace std;

int main()
{
    Arvore<int> arvore1;

    cria(arvore1);
    insere(arvore1, 5);
     insere(arvore1, 6);
      insere(arvore1, 8);
       insere(arvore1, 4);
    mostra(arvore1);
    retira(arvore1, 6);
    mostra(arvore1);
    destroi(arvore1);

    return 0;
}
