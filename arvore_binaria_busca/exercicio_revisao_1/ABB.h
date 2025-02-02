#ifndef ABB_H__
#define ABB_H__

#include <iostream>
#include <string>
using namespace std;

#include "NoABB.h"

class ABB {
    public:
        ABB();
        ~ABB();
        void insere(int chave);
        void remove(int chave);
        NoABB *buscar(int chave);

        bool   vazia();
        void  imprimePreOrdem();
        void  imprimeEmOrdem();
        void  imprimePosOrdem();
        void  imprimeArvore();

        int segundoMaior();
        bool verifica();

    private:
        NoABB *raiz;


        NoABB *sucessor(NoABB *no);
        NoABB *antecessor(NoABB *no);
        NoABB* remove(NoABB *raiz, int chave);
        void   destruir(NoABB *raiz);
        void   imprimePreOrdem(NoABB *raiz);
        void   imprimeEmOrdem(NoABB *raiz);
        void   imprimePosOrdem(NoABB *raiz);
        void   imprimeArvore(NoABB *raiz, string prefixo, bool esquerda);

        NoABB* segundoMaior(NoABB *raiz);
        bool verificaArvore(NoABB *no, int minVal, int maxVal);
};
#endif /* ABB_H__ */
