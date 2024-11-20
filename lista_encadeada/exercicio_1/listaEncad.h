#ifndef LISTAENCAD_H
#define LISTAENCAD_H
#include "noEncad.h"

class ListaEncad
{
private:
    No *head;
    No *aux;
    int n;

public:
    ListaEncad();               // Construtor
    ~ListaEncad();              // Destrutor
    void adiciona(int valor);   // Adiciona um novo nó
    int getComprimento() const; // Calcula o comprimento da lista
    void imprimeLista();
};

#endif
