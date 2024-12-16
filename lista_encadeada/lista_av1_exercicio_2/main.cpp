#include "listaEncad.h"
#include <iostream>

using namespace std;

int main()
{
    ListaEncad lista;
    int n = 0, maior = 0;
    cout << "Quantidade de nós: ";
    cin >> n;

    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        int val = 0;
        cout << "Digite o valor do nó " << i << ": ";
        cin >> val;
        lista.adiciona(val);
    }

    cout << endl;

    cout << "Precisa ser maior do que: ";
    cin >> maior;

    lista.imprimeLista();
    cout << endl;

    cout << "Quantidade de maiores: " << lista.contaMaiores(maior) << endl;

    return 0;
}
