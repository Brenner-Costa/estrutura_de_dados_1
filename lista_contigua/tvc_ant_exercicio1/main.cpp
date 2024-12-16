#include "ListaCont.h"
#include <iostream>
using namespace std;

int main() {
    
    ListaCont lista(10);


    lista.insereFinal(3);
    lista.insereFinal(2);
    lista.insereFinal(5);
    lista.insereFinal(5);
    lista.insereFinal(9);

    cout << "Lista original antes da operação: ";
    lista.exibir();

    ListaCont *novaLista = lista.copiar(5);

    cout << "Lista original após a operação: ";
    lista.exibir();

    cout << "Nova lista copiada: ";
    novaLista->exibir();

    delete novaLista;

    return 0;
}
