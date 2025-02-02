#include <iostream>
#include <string>
using namespace std;

#include "ABB.h"

void test1()
{
    cout << endl;
    cout << "Teste 1: " << endl;
    ABB bst;

    bst.insere(10);
    bst.insere(5);
    bst.insere(15);
    bst.insere(20);
    bst.insere(2);
    bst.insere(7);

    bool result = bst.verifica();

    if(result == 1) {
        cout << "ABB válida!" << endl;
    } else {
        cout << "ABB inválida!" << endl;
    }
}

int main()
{
    test1();

    return 0;
}