#include <iostream>
using namespace std;

#include "ArvBin.h"

// Para Teste 1
void CriaArvore(ArvBin &arv)
{
    // Cria os nós da árvore e suas relações conforme a figura

    NoArvBin *no50 = new NoArvBin(50, nullptr, nullptr); //folha mult 5
    NoArvBin *no99 = new NoArvBin(99, nullptr, nullptr);
    NoArvBin *no5 = new NoArvBin(5, nullptr, nullptr); //folha mult 5
    NoArvBin *no14 = new NoArvBin(14, no5, nullptr);
    NoArvBin *no45 = new NoArvBin(45, nullptr, nullptr); //folha mult 5
    NoArvBin *no88 = new NoArvBin(88, nullptr, nullptr);

    NoArvBin *no11 = new NoArvBin(11, no50, no99);
    NoArvBin *no2 = new NoArvBin(2, nullptr, no14);
    NoArvBin *no15 = new NoArvBin(15, nullptr, nullptr); //folha mult 5
    NoArvBin *no20 = new NoArvBin(20, no45, no88);
    NoArvBin *no90 = new NoArvBin(90, no11, no2);
    NoArvBin *no27 = new NoArvBin(27, no15, no20);

    NoArvBin *raiz = new NoArvBin(76, no90, no27);

    arv.setRaiz(raiz);
}


void Teste1(ArvBin &arv)
{

    CriaArvore(arv);
    cout << "Pre-ordem: " << endl;
    arv.imprimePreOrdem();
    cout << endl;
    cout << "Arvore: " << endl;
    arv.imprimeArvore();

    cout << "--------------------------------------------" << endl;
    cout << "Contagens" << endl;
    cout << "--------------------------------------------" << endl;
    
    arv.conta(5);
}

int main()
{
    ArvBin arv;

    Teste1(arv);

    return 0;
}