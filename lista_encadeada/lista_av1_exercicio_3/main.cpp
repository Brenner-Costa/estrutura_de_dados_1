#include "listaEncad.h"
#include <iostream>

using namespace std;

int main()
{
    ListaEncad lista;

    // Inserindo elementos fora de ordem
    lista.insereOrdenado(10);
    lista.insereOrdenado(5);
    lista.insereOrdenado(20);
    lista.insereOrdenado(15);
    lista.insereOrdenado(1);

    // Exibindo a lista (deve estar ordenada)
    cout << "Lista encadeada ordenada: ";
    lista.imprimeLista();

    return 0;
}
