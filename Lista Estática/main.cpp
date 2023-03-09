#include "listaestatica.h"
#include <iostream>

using namespace std;

int main(){
    ListaEstatica lista;
    int respostaInt, elemento, posicao, varauxiliar;
    bool respostaBool;

    criaLista(lista);

    do{
        cout << "\n0-Sair\n1-Verificar se esta vazia\n2-Verificar se ha espaço\n3-Recuperar numero de elementos\n";
        cout << "4-Verificar determinado elemento\n5-Verificar se posicao e valida\n6-Recuperar elemento\n";
        cout << "7-Recuperar posicao de elemento\n8-Inserir elemento\n9-Retirar elemento\n10-Exibir elementos\n";
        cin >> respostaInt;
        cin.ignore();
        system("cls");
        switch(respostaInt){
            case 1:
                respostaBool=verificaListaVazia(lista);
                if(respostaBool)
                    cout << "Lista vazia\n";
                else
                    cout << "Lista nao vazia\n";
                break;
            case 2:
                respostaBool=verificaEspaco(lista);
                if(respostaBool)
                    cout << "Ha espaco\n";
                else
                    cout << "Nao ha espaco\n";
                break;
            case 3:
                varauxiliar=recuperaNumeroElementos(lista);
                cout << "Número de elementos na lista: " << varauxiliar << endl;
                break;
            case 4:
                cout << "Informe o elemento: "; cin >> elemento;
                respostaBool=verificaElemento(lista, elemento);
                if(respostaBool)
                    cout << "Esta na lista\n";
                else
                    cout << "Nao esta na lista\n";
                break;
            case 5:
                cout << "Informe a posicao: "; cin >> posicao;
                respostaBool=verificaSePosicaoValida(lista, posicao);
                if(respostaBool)
                    cout << "Posicao valida\n";
                else
                    cout << "Posicao invalida\n";
                break;
            case 6:
                cout << "Informe a posicao: "; cin >> posicao;
                respostaInt=recuperaElemento(lista, posicao);
                if(respostaInt!=-1)
                    cout << "Elemento: " << respostaInt << endl;
                else
                    cout << "Elemento inexistente\n";
                break;
            case 7:
                cout << "Informe o elemento: "; cin >> elemento;
                respostaInt=recuperaPosicaoElemento(lista, elemento);
                if(respostaInt!=-1)
                    cout << "Posicao: " << respostaInt << endl;
                else
                    cout << "Elemento nao encontrado\n";
                break;
            case 8:
                cout << "Informe o elemento: "; cin >> elemento;
                cout << "Informe sua posicao: "; cin >> posicao;
                insereElemento(lista,elemento,posicao);
                cout << "Elemento inserido\n";
                break;
            case 9:
                cout << "Informe o elemento: "; cin >> elemento;
                retiraElemento(lista, elemento);
                cout << "Elemento retirado\n";
                break;
            case 10:
                exibeLista(lista);
                cout << endl;
        }
        system("pause");
        system("cls");
    }while(respostaInt!=0);

    return 0;
}
