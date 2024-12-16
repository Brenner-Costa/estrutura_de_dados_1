#ifndef LISTAENCAD_H
#define LISTAENCAD_H
#include "noEncad.h"

class ListaCirc
{
private:
    No *head;
    No *ultimo;
    int n;

public:
    ListaCirc();               // Construtor
    ~ListaCirc();              // Destrutor
    void adiciona(int valor);   // Adiciona um novo nó
    void insereOrdenado (int val );
    void insereFinal(int val);
    void imprimeLista();
    int remove(int valor);
    bool busca(int val);
};

#endif
