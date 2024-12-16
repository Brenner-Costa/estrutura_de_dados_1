#include "ListaCirc.h"
#include <iostream>

using namespace std;

int main() {
    ListaCirc lista;

    // Inserindo elementos
    lista.adiciona(10);
    lista.adiciona(20);
    lista.insereFinal(30);
    lista.insereFinal(40);

    // Exibindo a lista
    cout << "Lista Circular: ";
    lista.imprimeLista();

    // Removendo um elemento
    // lista.remove(20);
    // cout << "Após remover 20: ";
    // lista.imprimeLista();

    // Buscando um elemento
    cout << "Busca pelo valor 30: " << (lista.busca(30) ? "Encontrado" : "Não encontrado") << endl;
    cout << "Busca pelo valor 50: " << (lista.busca(50) ? "Encontrado" : "Não encontrado") << endl;

    return 0;
}
