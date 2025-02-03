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

void ArvBin::conta(int val)
{
    int contFolhas = 0;
    int contMultVal = 0;

    contagens(raiz, val, contFolhas, contMultVal);

    cout << "Nós folhas ou com 1 filho: " << contFolhas << endl;
    cout << "Folhas Multiplas de VAL: " << contMultVal << endl;
}

void ArvBin::contagens(NoArvBin *no, int val, int &contFolhas, int &contMultVal)
{
    if (no == nullptr)
    {
        return;
    }

    // esquerda -> no -> direita

    contagens(no->getEsq(), val, contFolhas, contMultVal);

    // Um dos dois filhos ser null
    if (no->getEsq() == nullptr || no->getDir() == nullptr)
    {
        if(no->getEsq() == nullptr && no->getDir() == nullptr) {
            //Se for folha, vai contar 1
            //cout << "Folha -> " << no->getChave() << endl; 
            contFolhas++;
        }else {
            //se tiver só um filho, vai contar 1
            //cout << "1 Filho -> " << no->getChave() << endl;
            contFolhas++;
        }
    }

    if(no->getChave() % val == 0) {
        //cout << "Multiplo -> " << no->getChave() << endl;
        contMultVal++;
    }

    contagens(no->getDir(), val, contFolhas, contMultVal);
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
