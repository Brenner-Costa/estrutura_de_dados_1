
#include <iostream>
#include <string>
using namespace std;

#include "ABB.h"



// Teste removendo o maior elemento da árvore. 
// maior nao tem filhos.
void test1()
{
    cout << endl;
    cout << "Teste 1:   Maior não tem filhos" << endl;
    ABB bst;

    // iserir os elementos 15, 10, 20, 25, 17.
    bst.insere(15);
    bst.insere(10);
    bst.insere(20);
    bst.insere(25);
    bst.insere(17);

    // Exibindo a árvore antes da remoção
    cout << "Árvore em ordem antes da remoção: ";
    bst.imprimeEmOrdem();
    cout << endl;

    bst.removeMaior();

    // Exibindo a árvore após a remoção
    cout << "Árvore em ordem após a remoção: ";
    bst.imprimeEmOrdem();
    cout << endl;

}

// Teste removendo o maior elemento da árvore. 
// maior tem filhos a esquerda.
void test2()
{
    cout << endl;
    cout << "Teste 2: Maior tem filho" << endl;
    ABB bst;

    // iserir os elementos 15, 10, 20, 25, 17, 19.
    bst.insere(15);
    bst.insere(10);
    bst.insere(20);
    bst.insere(25);
    bst.insere(17);
    bst.insere(22);

    // Exibindo a árvore antes da remoção
    cout << "Árvore em ordem antes da remoção: ";
    bst.imprimeEmOrdem();
    cout << endl;

    bst.removeMaior();

    // Exibindo a árvore após a remoção
    cout << "Árvore em ordem após a remoção: ";
    bst.imprimeEmOrdem();
    cout << endl;
}

// Teste removendo o maior elemento da árvore.
// A arvore tem apenas um elemento.
void test3()
{
    cout << endl;
    cout << "Teste 3: Arvore com apenas raiz" << endl;
    ABB bst;

    // inserir os elementos 15.
    bst.insere(15);

    // Exibindo a árvore antes da remoção
    cout << "Árvore em ordem antes da remoção: ";
    bst.imprimeEmOrdem();
    cout << endl;

    bst.removeMaior();


    if(bst.vazia())
    {
        cout << "Árvore vazia após a remoção." << endl;
    }
    else
    {
        cout << "Árvore em ordem após a remoção: ";
        bst.imprimeEmOrdem();
        cout << endl;
    }

}

// Teste removendo o maior elemento da árvore.
// Verificacao remocao do maior em uma arvore vazia.

void test4()
{
    cout << endl;
    cout << "Teste 4: Arvore Vazia" << endl;
    ABB bst;

    // Exibindo a árvore antes da remoção
    cout << "Árvore em ordem antes da remoção: ";
    bst.imprimeEmOrdem();
    cout << endl;

    bst.removeMaior();

    if(bst.vazia())
    {
        cout << "Árvore vazia após a remoção." << endl;
    }
    else
    {
        cout << "Árvore em ordem após a remoção: ";
        bst.imprimeEmOrdem();
        cout << endl;
    }

    cout << endl;
}


int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}