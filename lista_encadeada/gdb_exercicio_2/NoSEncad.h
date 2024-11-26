#pragma once
#include <iostream>

// Implementa TAD no de uma lista simplesmente encadeada.
class NoSEncad
{
    public:

        // Construtores
        NoSEncad();
        NoSEncad(int valor);
        NoSEncad(int valor, NoSEncad* p);
        
        // Obtem valor 
        int  ObterValor();
        
        // altera valor
        void AlteraValor(int valor);
        
        // Obtem o ponteiro para o proximo no
        NoSEncad* ObterProximo();
        
        //Altera o ponteiro para o proximo no
        void      AlteraProximo(NoSEncad* p);
        ~NoSEncad();

    private:
        int       info;     // Armazena a valor do no
        NoSEncad *proximo;  // ponteiro para o proximo no 
}; 

