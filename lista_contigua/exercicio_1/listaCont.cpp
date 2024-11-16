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
    // Como a lista esta vazia, a última posição do array é a primeira (ZERO)
    // Fazer quantNos++ ao final de cada inserção
    // Para adicionar, vamos verificar se quantNos é maior do que zero e menor do que max
    // Para saber aonde adicionar faça um QUANTNOS + 1 (Que ai vai pegar a posição após o último nó presente)
    // ERREI NA VERIFICAÇÃO DA LISTA VAZIA, FOI DESNECESSÁRIO. DE RESTO EU FIZ TUDO CERTO.

    if (quantNos < maxTam)
    {
        vet[quantNos] = valor;
        quantNos++;
        return true;
    }

    return false;
}

// Troca dois elementos na lista
bool ListaCont::troca(int posicao1, int posicao2)
{
    // Criar variavel auz para auxiliar na troca.
    // aux recebe posicao1 -> posicao1 recebe posicao2 -> posicao2 recebe aux

    if (posicao1 >= 0 && posicao2 >= 0 && posicao1 <= quantNos && posicao2 <= quantNos)
    {
        int aux = vet[posicao1];
        vet[posicao1] = vet[posicao2];
        vet[posicao2] = aux;
        return true;
    }

    return false;
}

void ListaCont::imprime() const
{
    for (int i = 0; i < quantNos; i++)
    {
        cout << vet[i] << " ";
    }

    cout << endl;
}
