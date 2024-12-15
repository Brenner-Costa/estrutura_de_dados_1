#include <iostream>
#include "listaCont.h"

using namespace std;

ListaCont::ListaCont(int capacidadeMax)
{
    quantNos = 0;
    maxTam = capacidadeMax;
    vet = new int[maxTam];
}

ListaCont::~ListaCont()
{
    delete[] vet;
    cout << "Memória Liberada!" << endl;
}

bool ListaCont::adiciona(int valor)
{
    if (quantNos < maxTam)
    {
        vet[quantNos] = valor;
        quantNos++;
        return true;
    }
    else if (quantNos == maxTam)
    {
        cout << "Lista cheia!" << endl;
    }

    return false;
}

bool ListaCont::aumentaCapacidade(int novoMax)
{
    if(novoMax < maxTam) {
        cout << "Tamanho inválido!" << endl;
        return false;
    }

    int *novoVetor = new int[novoMax];

    for(int i = 0; i < quantNos; i++) {
        cout << "Valor adicionado na nova lista: " << vet[i] << endl;
        novoVetor[i] = vet[i];
    }

    delete [] vet;

    vet = novoVetor;
    maxTam = novoMax;

    return true;
}

void ListaCont::imprime() const
{
    for (int i = 0; i < quantNos; i++)
    {
        cout << vet[i] << " ";
    }

    cout << endl;
}
