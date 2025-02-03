#include "ArvBin.h"

// Construtor
ArvBin::ArvBin()
{
    raiz = nullptr;
}

// Destrutor
ArvBin::~ArvBin()
{
    destruir(raiz);
}

void ArvBin::conta()
{
    int contDoisFilhos = 0;
    int contMultDeCinco = 0;

    contaElegante(raiz, contDoisFilhos, contMultDeCinco);

    cout << "Nós com 2 filhos: " << contDoisFilhos << endl;
    cout << "Folhas Multiplas de 5: " << contMultDeCinco << endl;

}

void ArvBin::contaElegante(NoArvBin *no, int &contDoisFilhos, int &contMultDeCinco)
{
    if(no == nullptr) {
        return;
    }

    if(no->getEsq() && no->getDir()) {
        contDoisFilhos++;
    }

    if(no->getEsq() == nullptr && no->getDir() == nullptr) {
        if(no->getChave() % 5 == 0) {
            contMultDeCinco++;
        }
    }

    contaElegante(no->getEsq(), contDoisFilhos, contMultDeCinco);
    contaElegante(no->getDir(), contDoisFilhos, contMultDeCinco);

}

// Função que destrói a árvore enraizada em um nó
void ArvBin::destruir(NoArvBin *no)
{
    if (no != nullptr)
    {
        destruir(no->getEsq());
        destruir(no->getDir());
        delete no;
        no = nullptr;
    }
}

// Retorna a raiz da árvore
NoArvBin *ArvBin::getRaiz()
{
    return raiz;
}

// Modifica a raiz da arvore somente se a raiz atual for nula
void ArvBin::setRaiz(NoArvBin *raiz)
{
    if (this->raiz == nullptr)
    {
        this->raiz = raiz;
        return;
    }
    cout << "A raiz da arvore ja foi definida" << endl;
}

void ArvBin::imprimePreOrdem(NoArvBin *no)
{
    if (no != nullptr)
    {
        cout << no->getChave() << " ";
        imprimePreOrdem(no->getEsq());
        imprimePreOrdem(no->getDir());
    }
}

void ArvBin::imprimePreOrdem()
{
    imprimePreOrdem(raiz);
    cout << endl;
}

void ArvBin::imprimeArvore(NoArvBin *no, string prefixo, bool esquerda)
{
    if (no != nullptr)
    {
        cout << prefixo;
        cout << (esquerda ? "├──" : "└──");
        cout << no->getChave() << endl;
        imprimeArvore(no->getEsq(), prefixo + (esquerda ? "│   " : "    "), true);
        imprimeArvore(no->getDir(), prefixo + (esquerda ? "│   " : "    "), false);
    }
    else
    {
        cout << prefixo;
        cout << (esquerda ? "├──" : "└──");
        cout << "[-]" << endl;
    }
}

void ArvBin::imprimeArvore()
{
    imprimeArvore(raiz, "", false);
}
