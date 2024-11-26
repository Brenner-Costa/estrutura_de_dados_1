#include "ListaCont.h"
#include <iostream>
using namespace std;

// Implemente aqui
void intercep(ListaCont &l1, ListaCont &l2, ListaCont &l3)
{
    // NumElem retorna a quantidade de elementos do vetor
    int tamLista1 = l1.numElem();
    int tamLista2 = l2.numElem();

    for (int i = 0; i < tamLista1; i++)
    {
        // Percorrer a lista 1 e ir comparando elemento
        // Criar uma verificação para ver se já está na lista l3
        for (int j = 0; j < tamLista2; j++)
        {
            if (l1.obter(i) == l2.obter(j))
            {
                int val = l1.obter(i);

                if (l3.numElem() == 0)
                {
                    cout << "Inserido no inicio!" << endl;
                    l3.insereInicio(val);
                }
                else
                {
                    bool jaExiste = false;
                    for (int k = 0; k < l3.numElem(); k++)
                    {
                        if (val == l3.obter(k))
                        {
                            jaExiste = true;
                            cout << "O número " << val << " já está na lista!" << endl;
                            break;
                        }
                    }

                    if(!jaExiste) {
                        l3.insere(val);
                    }
                    break;
                }
            }
        }
    }
}

int main()
{
    int n1, n2;
    // Obter dados para os testes
    cout << "Digite o tamano do vetor 1: ";
    cin >> n1;
    cout << endl;
    int valores1[n1];
    for (int i = 0; i < n1; i++)
    {
        cout << "Digite o valor " << i << " do vetor 1: ";
        cin >> valores1[i];
    }
    cout << endl;
    cout << "Digite o tamano do vetor 2: ";
    cin >> n2;
    cout << endl;
    int valores2[n2];
    for (int i = 0; i < n2; i++)
    {
        cout << "Digite o valor " << i << " do vetor 2: ";
        cin >> valores2[i];
    }
    cout << endl;

    // Cria as listas
    ListaCont lista1(10);
    ListaCont lista2(10);
    ListaCont lista3(10);

    // insere dados na lista
    for (int i = 0; i < n1; i++)
        lista1.insere(valores1[i]);
    for (int i = 0; i < n2; i++)
        lista2.insere(valores2[i]);

    // chama a função intercep
    intercep(lista1, lista2, lista3);

    // imprime o resultado
    cout << lista3.numElem() << endl;
    cout << lista3 << endl;

    return 0;
}