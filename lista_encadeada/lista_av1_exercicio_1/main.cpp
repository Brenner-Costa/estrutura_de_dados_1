#include "listaEncad.h"
#include <iostream>

using namespace std;

int main()
{
    ListaEncad lista; // Cria uma lista simplesmente encadeada

    // Adiciona elementos na lista
    lista.adiciona(10);
    lista.adiciona(20);
    lista.adiciona(30);
    lista.adiciona(40);
    lista.adiciona(50);
    lista.adiciona(60);
    lista.adiciona(70);
    lista.adiciona(80);
    lista.adiciona(90);
    lista.adiciona(100);
    lista.adiciona(110);

    // Exibe o comprimento da lista
    cout << "Comprimento da lista: " << lista.getComprimento() << endl;
    lista.imprimeLista();

    return 0;
}
