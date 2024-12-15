#include <iostream>
#include "listaCont.h"

using namespace std;

int main() {
    // Criação da lista com capacidade inicial 3
    ListaCont lista(3);

    lista.adiciona(10);
    lista.adiciona(20);
    lista.adiciona(30);

    cout << "Lista original: ";
    lista.imprime();

    // Tenta aumentar a capacidade para 5
    if (lista.aumentaCapacidade(10)) {
        cout << "Capacidade aumentada com sucesso!" << endl;
    } else {
        cout << "Falha ao aumentar a capacidade." << endl;
    }

    lista.adiciona(40);
    lista.adiciona(50);

    cout << "Lista após aumento de capacidade: ";
    lista.imprime();

    return 0;
}