#include "ListaEncad.h"
#include <iostream>

using namespace std;

int main() {
     ListaEncad lista;

    lista.insereFinal(3);
    lista.insereFinal(2);
    lista.insereFinal(5);
    lista.insereFinal(7);
    lista.insereFinal(9);

    cout << "Lista completa: ";
    lista.exibirLista();

    cout << "Elementos ordenados em relação aos vizinhos: ";
    lista.imprimeElemsEmOrdem();

    return 0;
}
