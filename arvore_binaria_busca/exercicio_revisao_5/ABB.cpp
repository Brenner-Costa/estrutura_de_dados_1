#include "ABB.h"

ABB::ABB() : raiz(nullptr) {}

ABB::~ABB() {
    destruir(raiz);
}

void ABB::destruir(NoABB* no) {
    if(no) {
        destruir(no->getEsq());
        destruir(no->getDir());
        delete no;
    }
}

int ABB::absoluto(int x) {
    return (x < 0) ? -x : x;
}

void ABB::insere(int chave)
{
    if (raiz == nullptr)
    {
        raiz = new NoABB(chave);
        return;
    }
    NoABB *atual = raiz;
    NoABB *anterior = nullptr;
    while (atual != nullptr)
    {
        anterior = atual;
        if (chave < atual->getChave())
        {
            atual = atual->getEsq();
        }
        else
        {
            atual = atual->getDir();
        }
    }
    if (chave < anterior->getChave())
    {
        anterior->setEsq(new NoABB(chave));
    }
    else
    {
        anterior->setDir(new NoABB(chave));
    }
}

void ABB::encontrarMaiorDiff(NoABB* no, int a, int b, int val, int& maiorDiff) {

    if(no == nullptr) 
        return;

    if(no->getChave() >= a && no->getChave() <= b) {
        //está dentro do limite
        int valorAbsoluto = val - no->getChave();

        if(maiorDiff < valorAbsoluto) {
            maiorDiff = valorAbsoluto;
        }

        encontrarMaiorDiff(no->getEsq(), a, b, val, maiorDiff);
        encontrarMaiorDiff(no->getDir(), a, b, val, maiorDiff);

    }

    if(no->getChave() < a) {
        //Por mais que essa chave esteja fora do limite inferior, o nó a direita dele pode acabar estando no limite, por isso tem que ir para a direita.
        //Porém na esquerda não vai ter nada, pois é ainda menor do que esse nó

        encontrarMaiorDiff(no->getDir(), a, b, val, maiorDiff);
    }
}


int ABB::maiorDiferenca(int a, int b, int val) {
    int maiorDiff = -1;
    encontrarMaiorDiff(raiz, a, b, val, maiorDiff);
    return maiorDiff;
}