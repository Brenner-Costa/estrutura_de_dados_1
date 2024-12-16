#include "ListaCont.h"
#include <iostream>
using namespace std;

// Construtor
ListaCont::ListaCont(int capacidade) {
    max = capacidade;
    n = 0;
    vet = new int[max];
}

// Destrutor
ListaCont::~ListaCont() {
    delete[] vet;
}

// Função para inserir elementos no final da lista
void ListaCont::insereFinal(int valor) {
    if (n < max) {
        vet[n] = valor;
        n++;
    } else {
        cout << "Lista cheia!" << endl;
    }
}

// Função para exibir os elementos da lista
void ListaCont::exibir() {
    for (int i = 0; i < n; i++) {
        cout << vet[i] << " ";
    }
    cout << endl;
}

// Função para copiar elementos a partir da primeira ocorrência de um valor
ListaCont* ListaCont::copiar(int valor) {
    ListaCont *novoVet = new ListaCont(max);
    
    int posicao = -1;
    for(int i = 0; i < n; i++) {
        if(vet[i] == valor) {
            posicao = i;
            break;
        }
    }


    int novaquant = 0; //Ir atualizando o N da lista antiga
    for(int i = posicao; i < n; i++) {
        novoVet->insereFinal(vet[i]);
        novaquant++;
    }

    n -= novaquant;

    return novoVet;
}
