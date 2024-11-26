#pragma once

#include "NoSEncad.h"


class ListaSEncad
{
    public:
    
        // Cria uma lista vazia
        ListaSEncad();
        
        // Verifica se lista está vazia
        bool EhVazia();
        
        // Insere valor na frente da lista
        void InserePrimeiro(int valor);
        
        // Insere valor na ultima posição da lista
        void Insere(int valor);

        // Remove o primeiro elemento da lista
        void RemovePrimeiro();
        
        // Remove o Ultimo elemento da lista
        void RemoveUltimo();
        
        // Remove a primeira ocorrência de valor 
        void Remove(int valor);

        // Busca nó que contem valor 
        NoSEncad * Procura(int valor);
        
        // Retorna o tamanho da lista
        int  Tamanho();
    
        // Imprime a lista
        void Imprime();
        
        // Destrutor
        ~ListaSEncad();
        
        //
        void InsereApos(int n, int s, int tamLista);

    private:

        // ponteiro para primeiro elemento da lista
        NoSEncad *primeiro;
};
