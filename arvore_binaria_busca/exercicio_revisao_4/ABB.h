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

        void nivel(int k);

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

        void somaNivel(NoABB *no, int k, int nivel, int *soma);


};
#endif /* ABB_H__ */
