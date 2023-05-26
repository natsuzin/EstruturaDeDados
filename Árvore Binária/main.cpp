#include <iostream>
#include "ArvoreBinaria.h"
using namespace std;

int main()
{

    ArvoreBinaria<int> arvore;
    cria(arvore);

    insere(arvore, 10);


    return 0;
}
