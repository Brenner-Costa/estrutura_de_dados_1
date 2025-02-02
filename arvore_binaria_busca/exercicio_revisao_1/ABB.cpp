
#include "ABB.h"

#include <iostream>
#include <climits>
using namespace std;

bool ABB::verifica()
{

    return verificaArvore(raiz, INT_MIN, INT_MAX);
}

bool ABB::verificaArvore(NoABB *no, int minVal, int maxVal)
{
    /*
        - Caso chegue em null, significa que a árvore foi até o nível mais baixo. O que significa que a ABB é válida!
        - No IF seguinte, verifico se o nó atual está dentro dos limites estabelecidos.
            - minVal -> menor valor que o nó pode ter para ser válido.
            - maxVal -> Maior valor que o nó pode ter para ser válido.
            - Dependendo de onde está sendo verificado o nó atual, não vai ser necessário um limite, apenas tenderá para um infinito de valores
            pequenos ou grandes.
            - Se estiver na direita, não importa o quão grande ele seja, ele só não pode ser menor que o pai.
            - Se estiver na esquerda é o mesmo esquema, mas ele não pode ser maior que o pai.

            - Por isso passo o no.getchave() como parâmetro -> Para que o esquerdo ou o direito não o ultrapasse.

            No retorno eu só verifico se ambas variáveis são true, se sim, a ABB é válida!
            Vai retornar 1 ou 0
    */

    if(no == nullptr){
        return true;
    }

    if(no-> getChave() <= minVal || no->getChave() >= maxVal) {
        cout << "Chave inválida! -> " << no->getChave() << endl;
        return false;
    }

    bool esq = verificaArvore(no->getEsq(), minVal, no->getChave());
    bool dir = verificaArvore(no->getDir(), no->getChave(), maxVal);

    return esq && dir;
}


NoABB* ABB::segundoMaior(NoABB* raiz) {
    if (!raiz || (!raiz->getDir() && !raiz->getEsq())) {
        cout << "NÃO POSSUI 2 NÓS" << endl;
        return nullptr;
    }
    
    if (raiz->getDir() && !raiz->getDir()->getDir() && !raiz->getDir()->getEsq()) {
        return raiz;
    }
    
    if (raiz->getDir()) {
        return segundoMaior(raiz->getDir());
    }
    
    NoABB* atual = raiz->getEsq();
    while (atual->getDir()) {
        atual = atual->getDir();
    }
    return atual;
}

int ABB::segundoMaior() {
    NoABB* segundoMaiorRetorno = segundoMaior(raiz);
    if (!segundoMaiorRetorno) {
        return -1;
    }
    return segundoMaiorRetorno->getChave();
}

ABB::ABB()
{
    raiz = nullptr;
}

ABB::~ABB()
{
    destruir(raiz);
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
