#include "ListaCont.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n1, n2;

    cout << "Digite o tamano do vetor 1: ";
    cin >> n1;
    int valores1[n1];
    cout << endl;

    for (int i = 0; i < n1; i++)
    {
        cout << "Digite o valor " << i << " do vetor 1: ";
        cin >> valores1[i];
    }
    cout << endl;

    cout << "Digite o tamano do vetor 2: ";
    cin >> n2;
    int valores2[n2];
    for (int i = 0; i < n2; i++)
    {
        cout << "Digite o valor " << i << " do vetor 2: ";
        cin >> valores2[i];
    }
    cout << endl;

    ListaCont lista1(25);
    ListaCont lista2(10);

    for (int i = 0; i < n1; i++)
        lista1.insere(valores1[i]);
    for (int i = 0; i < n2; i++)
        lista2.insere(valores2[i]);

    lista1.concatena(lista2);

    cout << "Tamanho da lista: " << lista1.numElem() << endl;
    cout << "Lista: " << lista1 << endl;

    return 0;
}