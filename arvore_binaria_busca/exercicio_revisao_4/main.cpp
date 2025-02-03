#include <iostream>
#include <string>
using namespace std;

#include "ABB.h"

void test1()
{
    cout << endl;
    cout << "Somando Níveis" << endl;
    ABB bst;

    bst.insere(10);
    bst.insere(5);
    bst.insere(15);
    bst.insere(20);
    bst.insere(2);
    bst.insere(7);
    bst.insere(1);

    bst.nivel(2);

}

int main()
{
    test1();

    return 0;
}