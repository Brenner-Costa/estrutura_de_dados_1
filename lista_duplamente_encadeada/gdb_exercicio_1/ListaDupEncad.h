#ifndef LISTADUPENCAD_H__
#define LISTADUPENCAD_H__

#include <iostream>

#include "NoDupEncad.h"

class ListaDupEncad
{
    public:
        ListaDupEncad();              // construtor
        ~ListaDupEncad();             // destrutor
        void Insere(int val);         // insere um elemento no final da lista
        void InserePrimeiro(int val); // insere na primeira posição da lista
        void InserePos(int val, int pos); // insere um elemento em uma posição específica
        void Imprime();                   // imprime os elementos da lista
        void ImprimeReverso();            // imprime os elementos da lista em ordem reversa
        NoDupEncad* BuscaNo(int val); // busca um elemento na lista
        int  Tamanho(); // retorna o número de elementos da lista
        
    private:
        NoDupEncad *primeiro; // ponteiro para o nó cabeça
        NoDupEncad *ultimo;  // ponteiro para o nó cauda
        int n; // número de elementos armazenados
};

#endif /* LISTADUPENCAD_H__ */