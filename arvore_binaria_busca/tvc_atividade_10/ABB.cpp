
#include "ABB.h"

#include <iostream>
#include <climits>
using namespace std;

ABB::ABB()
{
    raiz = nullptr;
}

ABB::~ABB()
{
    destruir(raiz);
}

int ABB::ipmParcial()
{
    return impressaoParcial(raiz, 2, 16);
}

int ABB::impressaoParcial(NoABB *no, int a, int b) {
    if (no == nullptr) return 0;

    int soma = 0;

    if (no->getChave() > a) {
        soma += impressaoParcial(no->getEsq(), a, b);
    }

    if (no->getChave() > a && no->getChave() < b) {
        int somaFilhos = (no->getEsq() ? no->getEsq()->getChave() : 0) + (no->getDir() ? no->getDir()->getChave() : 0);
        
        if (somaFilhos % 2 == 0) {
            soma += no->getChave();
            cout << "No: " << no->getChave() << endl;
        }
    }

    if (no->getChave() < b) {
        soma += impressaoParcial(no->getDir(), a, b);
    }

    return soma;
}

NoABB *ABB::buscar(int chave)
{
    NoABB *atual = raiz;
    while (atual != nullptr && atual->getChave() != chave)
    {
        if (chave < atual->getChave())
        {
            atual = atual->getEsq();
        }
        else
        {
            atual = atual->getDir();
        }
    }
    return atual;
}

NoABB *ABB::sucessor(NoABB *no)
{
    if (no->getDir() != nullptr)
    {
        NoABB *min = no->dir;
        while (min->esq != nullptr)
        {
            min = min->esq;
        }
        return min;
    }
    NoABB *sucessor = nullptr;
    NoABB *aux = raiz;
    while (aux != no)
    {
        if (no->getChave() < aux->getChave())
        {
            sucessor = aux;
            aux = aux->getEsq();
        }
        else
        {
            aux = aux->getDir();
        }
    }
    return sucessor;
}

NoABB *ABB::antecessor(NoABB *no)
{
    if (no->getEsq() != nullptr)
    {
        NoABB *max = no->esq;
        while (max->dir != nullptr)
        {
            max = max->dir;
        }
        return max;
    }
    NoABB *antecessor = nullptr;
    NoABB *aux = raiz;
    while (aux != no)
    {
        if (no->getChave() > aux->getChave())
        {
            antecessor = aux;
            aux = aux->getDir();
        }
        else
        {
            aux = aux->getEsq();
        }
    }
    return antecessor;
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

void ABB::destruir(NoABB *raiz)
{
    if (raiz != nullptr)
    {
        destruir(raiz->getEsq());
        destruir(raiz->getDir());
        delete raiz;
    }
}

void ABB::imprimePreOrdem()
{
    imprimePreOrdem(raiz);
}

void ABB::imprimeEmOrdem()
{
    imprimeEmOrdem(raiz);
}

void ABB::imprimePosOrdem()
{
    imprimePosOrdem(raiz);
}

void ABB::imprimePreOrdem(NoABB *raiz)
{
    if (raiz != nullptr)
    {
        cout << raiz->getChave() << " ";
        imprimePreOrdem(raiz->getEsq());
        imprimePreOrdem(raiz->getDir());
    }
}

void ABB::imprimeEmOrdem(NoABB *raiz)
{
    if (raiz != nullptr)
    {
        imprimeEmOrdem(raiz->getEsq());
        cout << raiz->getChave() << " ";
        imprimeEmOrdem(raiz->getDir());
    }
}

void ABB::imprimePosOrdem(NoABB *raiz)
{
    if (raiz != nullptr)
    {
        imprimePosOrdem(raiz->getEsq());
        imprimePosOrdem(raiz->getDir());
        cout << raiz->getChave() << " ";
    }
}

void ABB::imprimeArvore()
{
    imprimeArvore(raiz, "", false);
}

void ABB::imprimeArvore(NoABB *raiz, string prefixo, bool esquerda)
{
    if (raiz != nullptr)
    {
        cout << prefixo;
        cout << (esquerda ? "├──" : "└──");
        cout << raiz->getChave() << endl;
        imprimeArvore(raiz->getEsq(), prefixo + (esquerda ? "│   " : "    "), true);
        imprimeArvore(raiz->getDir(), prefixo + (esquerda ? "│   " : "    "), false);
    }
    else
    {
        cout << prefixo;
        cout << (esquerda ? "├──" : "└──");
        cout << "[-]" << endl;
    }
}

bool ABB::vazia()
{
    return raiz == nullptr;
}

void ABB::remove(int chave)
{
    raiz = remove(raiz, chave);
}

NoABB *ABB::remove(NoABB *raiz, int chave)
{
    NoABB *atual = raiz;
    NoABB *anterior = nullptr;
    NoABB *substituto = nullptr;

    // Busca do nó a ser removido
    while (atual != nullptr && atual->chave != chave)
    {
        anterior = atual;
        if (chave < atual->chave)
        {
            atual = atual->esq;
        }
        else
        {
            atual = atual->dir;
        }
    }

    // Caso: chave não encontrada
    if (atual == nullptr)
    {
        return raiz;
    }

    // Caso 1: Nó folha ou com um único filho
    if (atual->esq == nullptr || atual->dir == nullptr)
    {
        substituto = (atual->esq != nullptr) ? atual->esq : atual->dir;

        // Se o nó removido é a raiz
        if (anterior == nullptr)
        {
            delete atual;
            return substituto; // Nova raiz
        }

        // Ajuste do ponteiro do pai
        if (atual == anterior->esq)
        {
            anterior->esq = substituto;
        }
        else
        {
            anterior->dir = substituto;
        }

        delete atual;
    }
    else
    {
        // Caso 2: Nó com dois filhos
        NoABB *paiSubstituto = atual;
        substituto = atual->dir;

        // Busca o menor valor da subárvore direita
        while (substituto->esq != nullptr)
        {
            paiSubstituto = substituto;
            substituto = substituto->esq;
        }

        // Substitui o valor do nó a ser removido pelo do sucessor
        atual->chave = substituto->chave;

        // Ajusta o pai do sucessor
        if (paiSubstituto->esq == substituto)
        {
            paiSubstituto->esq = substituto->dir;
        }
        else
        {
            paiSubstituto->dir = substituto->dir;
        }

        delete substituto;
    }

    return raiz;
}
