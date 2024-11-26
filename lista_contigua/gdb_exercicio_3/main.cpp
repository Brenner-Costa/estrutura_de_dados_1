#include "ListaCont.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

    int n1;

    cout << "Digite o tamano do vetor: ";
    cin >> n1;
    int valores1[n1];
    cout << endl;

    for (int i = 0; i < n1; i++)
    {
        cout << "Digite o valor " << i << " do vetor: ";
        cin >> valores1[i];
    }

    ListaCont lista1(n1);

    cout << "Lista não ordenada: " << lista1 << endl;

    for (int i = 0; i < n1; i++) {
        lista1.insere(valores1[i]);
        lista1.insere_ordenado(lista1.obter(i));
    }

    cout << "Tamanho da lista: " << lista1.numElem() << endl;
    cout << "Lista ordenada (ascendente): " << lista1 << endl;

    return 0;
}