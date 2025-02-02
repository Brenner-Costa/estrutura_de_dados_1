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

    int contPares = 0;
    int contFolhas = 0;
    contaElegante(raiz, contPares, contFolhas);

    cout << "Quantidade de pares -> " << contPares << endl;
    cout << "Quantidade de folhas -> " << contFolhas << endl;
}

void ArvBin::contaElegante(NoArvBin *no, int &contPares, int &contFolhas)
{

    if (no == nullptr)
    {
        return;
    }

    if (no->getChave() % 2 == 0)
    {
        //cout << "Par -> " << no->getChave() << endl;
        contPares++;
    }

    if (no->getDir() == nullptr && no->getEsq() == nullptr)
    {
        //cout << "Folha -> " << no->getChave() << endl;
        contFolhas++;
    }

    contaElegante(no->getEsq(), contPares, contFolhas);
    contaElegante(no->getDir(), contPares, contFolhas);
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
