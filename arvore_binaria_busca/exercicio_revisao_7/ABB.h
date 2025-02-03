#ifndef ABB_H
#define ABB_H

#include "NoABB.h"

class ABB
{
public:
    ABB();
    ~ABB();

    void insere(int chave);
    int kMaior(int k);

private:
    NoABB *raiz;

    void percursoInvertido(NoABB *no, int k, int &contador, int &resultado);
    void destruir(NoABB *no);
};

#endif