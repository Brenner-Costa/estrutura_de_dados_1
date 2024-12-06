
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
    for (int i = 0; i < n_nos; i++)
    {
        cin >> no;
        lista.Insere(no);
    }

    int pos, val;
    cout << "Digite posição: ";
    cin >> pos;
    cout << endl;
    cout << "Digite o valor que será removido: ";
    cin >> val; 
    // cout << "Lista Antes: ";
    lista.Imprime();
    lista.Remove(val);
    // cout << "Lista Remove: ";
    lista.Imprime();
    lista.RemovePos(pos);
    // cout << "Lista RemovePos: ";
    lista.Imprime();
    // cout << "Lista Reversa: ";
    lista.ImprimeReverso();

    return 0;
}
