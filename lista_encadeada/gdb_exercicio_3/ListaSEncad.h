#pragma once

#include "NoSEncad.h"


class ListaSEncad
{
    public:
    
        // Cria uma lista vazia
        ListaSEncad();
        
        // Verifica se lista está vazia
        bool EhVazia();
        
        // Insere elementos em ordem ascendente de valores
        void InsereOrdenado(int val);
    
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
        


    private:

        // ponteiro para primeiro elemento da lista
        NoSEncad *primeiro;
};
