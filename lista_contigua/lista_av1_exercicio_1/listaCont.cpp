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

// Troca dois elementos na lista
bool ListaCont::troca(int posicao1, int posicao2)
{

    if (posicao1 <= quantNos && posicao1 > 0 && posicao2 <= quantNos && posicao2 > 0 && posicao1 < maxTam && posicao2 < maxTam)
    {
        int auxiliar;
        auxiliar = vet[posicao1];
        vet[posicao1] = vet[posicao2];
        vet[posicao2] = auxiliar;
        return true;
    } else {
        cout << "Posições inválidas!" << endl;
        return false;
    }
}

void ListaCont::imprime() const
{
    for (int i = 0; i < quantNos; i++)
    {
        cout << vet[i] << " ";
    }

    cout << endl;
}
