#ifndef ABB_H
#define ABB_H

#include "NoABB.h"

class ABB {
public:
    ABB();
    ~ABB();
    
    void insere(int chave);
    int maiorDiferenca(int a, int b, int val);

private:
    NoABB* raiz;
    
    int absoluto(int x);
    void encontrarMaiorDiff(NoABB* no, int a, int b, int val, int& maiorDiff);
    void destruir(NoABB* no);
};

#endif