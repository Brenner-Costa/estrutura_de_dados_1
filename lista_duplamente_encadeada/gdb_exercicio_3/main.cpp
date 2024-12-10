
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

    cout << "Digite posição inicial e final: ";
    int start, end;
    cin >> start >> end;
    cout << "Lista Original: ";
    lista.Imprime();
    
    ListaDupEncad *sublista = lista.ExtraiSublista(start, end);

    cout << "Lista Final: ";
    lista.Imprime();
    cout << "Sublista: ";
    sublista->Imprime();

    delete sublista;    

    return 0;

}

