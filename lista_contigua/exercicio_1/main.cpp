#include <iostream>
#include "listaCont.h"

using namespace std;

int main()
{
    // Criação de uma lista com capacidade máxima de 10
    ListaCont lista(10);

    // Adicionando elementos à lista
    lista.adiciona(1);
    lista.adiciona(2);
    lista.adiciona(3);
    lista.adiciona(4);

    cout << "Lista antes da troca: ";
    lista.imprime();
    cout << endl;

    // Testando a troca
    if (lista.troca(1, 3))
    {
        cout << "Troca realizada com sucesso!" << endl;
    }
    else
    {
        cout << "Troca falhou. Índices inválidos." << endl;
    }

    cout << endl;
    cout << "Lista após a troca: ";
    lista.imprime();
    cout << endl;

    return 0;
}
