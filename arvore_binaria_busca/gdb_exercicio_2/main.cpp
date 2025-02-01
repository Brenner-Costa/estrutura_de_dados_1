#include <iostream>
#include <string>
using namespace std;

#include "ABB.h"



void test1()
{
    cout << endl;
    cout << "Teste 1: " << endl;
    ABB bst;

    // iserir os elementos 15, 10, 20, 25, 17.
    bst.insere(15);
    bst.insere(10);
    bst.insere(20);
    bst.insere(25);
    bst.insere(17);

    // Exibindo a árvore antes da remoção
    cout << "Impressão em ordem: ";
    bst.imprimeEmOrdem();
    cout << endl;

    int chave = bst.segundoMaior();
    cout << "Segundo maior elemento: " << chave << endl;
    cout << endl;

}


void test2()
{
    cout << "Teste 2: " << endl;
    ABB bst;

    // inserir os elementos 15, 10, 20, 30, 17, 19, 24, 23, 28.
    /*
                            15
                           /  \
                          /    \
                        10      20
                              /    \
                            17      30
                             \     /  
                              19  23    
                                   \                              
                                    24
                                     \
                                      28
                                
    
    */
    bst.insere(15);
    bst.insere(10);
    bst.insere(20);
    bst.insere(30);
    bst.insere(17);
    bst.insere(19);
    bst.insere(24);
    bst.insere(23);
    bst.insere(28);


    // Exibindo a árvore
    cout << "Impressão em ordem: ";
    bst.imprimeEmOrdem();
    cout << endl;

    int chave = bst.segundoMaior();
    cout << "Segundo maior elemento: " << chave << endl;
    cout << endl;
}


void test3()
{
    cout << "Teste 3: " << endl;
    ABB bst;

    // inserir os elementos 15.
    bst.insere(15);

    // Exibindo a árvore
    cout << "Impressão em ordem: ";
    bst.imprimeEmOrdem();
    cout << endl;


    int chave = bst.segundoMaior();
    cout << "Segundo maior elemento: " << chave << endl;
    cout << endl;


}



void test4()
{
    cout << "Teste 4:" << endl;
    ABB bst;

    // Exibindo a árvore
    cout << "Impressão em ordem: ";
    bst.imprimeEmOrdem();
    cout << endl;


    int chave = bst.segundoMaior();
    cout << "Segundo maior elemento: " << chave << endl;
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