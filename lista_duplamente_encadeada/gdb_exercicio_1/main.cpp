
#include <iostream>
#include "ListaDupEncad.h"

using namespace std;


int main()
{
    ListaDupEncad lista;

    int n_nos;
    int no;

    cout << "Digite o número de nós: ";
    cin >> n_nos;
    cout << "Digite os valores dos nós: ";
    for(int i = 0; i < n_nos; i++) {
        cin >> no;
        lista.Insere(no);
    }

    cout << "Digite posição e valor para inserir: ";
    int pos, val;
    cin >> pos >> val;
    lista.InserePos(val, pos);

    cout << "Lista: ";
    lista.Imprime();


    return 0;
}

