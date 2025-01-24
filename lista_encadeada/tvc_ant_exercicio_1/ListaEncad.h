#ifndef LISTAENCAD_H
#define LISTAENCAD_H

#include "noEncad.h" // Incluindo a estrutura do nó

class ListaEncad {
private:
    No* primeiro; // Ponteiro para o primeiro nó
    No* ultimo;   // Ponteiro para o último nó
    int n;        // Quantidade de elementos na lista

public:
    ListaEncad();               // Construtor
    ~ListaEncad();              // Destrutor

    void insereFinal(int val);  // Insere um valor no final da lista
    void imprimeElemsEmOrdem(); // Imprime os elementos ordenados em relação aos vizinhos
    void exibirLista();         // Exibe todos os elementos da lista
};

#endif // LISTAENCAD_H
