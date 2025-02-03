#include <iostream>
#include "ABB.h"

using namespace std;

int main()
{
    ABB arvore;

    // Inserção de valores de teste
    arvore.insere(20);
    arvore.insere(8);
    arvore.insere(22);
    arvore.insere(4);
    arvore.insere(12);
    arvore.insere(10);
    arvore.insere(14);

    // Teste da função
    // Testa k = 3
    cout << "3o maior elemento: " << arvore.kMaior(3) << endl; // Saída: 14

    return 0;
}