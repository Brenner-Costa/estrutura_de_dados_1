#include "ArvBin.h"
#include <iostream>
using namespace std;

int main()
{
    // Criando os nós da árvore
    NoArvBin *no7 = new NoArvBin(7, nullptr, nullptr);
    NoArvBin *no99 = new NoArvBin(99, nullptr, nullptr);
    NoArvBin *no5 = new NoArvBin(5, nullptr, nullptr);
    NoArvBin *no14 = new NoArvBin(14, no5, nullptr);
    NoArvBin *no13 = new NoArvBin(13, nullptr, nullptr);
    NoArvBin *no88 = new NoArvBin(88, nullptr, nullptr);

    NoArvBin *no11 = new NoArvBin(11, no7, no99);
    NoArvBin *no2 = new NoArvBin(2, nullptr, no14);
    NoArvBin *no15 = new NoArvBin(15, nullptr, nullptr);
    NoArvBin *no20 = new NoArvBin(20, no13, no88);
    NoArvBin *no90 = new NoArvBin(90, no11, no2);
    NoArvBin *no27 = new NoArvBin(27, no15, no20);

    NoArvBin *raiz = new NoArvBin(76, no90, no27);

    // Criando a árvore binária e configurando a raiz
    ArvBin arv;
    arv.setRaiz(raiz);

    cout << "--------------------------------------------" << endl;
    // Chamando o método impares() e exibindo o resultado
    int totalImpares = arv.impares();
    cout << "LETRA (A) -> Número de nós ímpares: " << totalImpares << endl;

    cout << "--------------------------------------------" << endl;

    int resultadoSoma = arv.soma();
    cout << "LETRA (B) -> Soma: " << resultadoSoma << endl;

    cout << "--------------------------------------------" << endl;

    float resultadoMedia = arv.media(resultadoSoma);
    cout << "LETRA (C) -> Media: " << resultadoMedia << endl;

    cout << "--------------------------------------------" << endl;

    float resultadoMediaPares = arv.mediaPares(resultadoSoma);
    cout << "LETRA (D) -> Media (Pares): " << resultadoMediaPares << endl;

    cout << "--------------------------------------------" << endl;

    float resultadoMaiorNo = arv.maior();
    cout << "LETRA (E) -> Maior Nó: " << resultadoMaiorNo << endl;

    cout << "--------------------------------------------" << endl;

    float resultadoMenorNo = arv.menor();
    cout << "LETRA (F) -> Menor Nó: " << resultadoMenorNo << endl;

    cout << "--------------------------------------------" << endl;

    float resultadoMaioresNo = arv.maiores(11);
    cout << "LETRA (G) -> Quantidade de nós maiores que val: " << resultadoMaioresNo << endl;

    cout << "--------------------------------------------" << endl;

    return 0;
}
