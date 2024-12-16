#include "listaEncad.h"
#include "noEncad.h"
#include <iostream>

using namespace std;

// Construtor: inicializa a lista como vazia
ListaEncad::ListaEncad()
{
    head = nullptr;
}

// Destrutor: libera a memória alocada para os nós
ListaEncad::~ListaEncad()
{
    // Como cada nó é um espaço separado na memória, vai ser necessário deletar um nó de cada vez.
    // Como o último nó sempre é NULL, vamos verificar isso e ficar monitorando. Quando chegar em null, vamos parar o laço e a lista terá sido apagada.

    No *p = head;
    while (p != nullptr)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }

    cout << "Memória Liberada!" << endl;
}

// Adiciona um novo nó no início da lista
void ListaEncad::adiciona(int valor)
{
    // fazer o novo no apontar para onde o primeiro aponta
    // Primeiro vai receber o novo no

    if (head == nullptr)
    {
        head = new No();
        head->setInfo(valor);
        head->setProx(nullptr);
    }
    else
    {
        No *novoNo = new No();
        novoNo->setInfo(valor);
        novoNo->setProx(head);
        head = novoNo;
    }
}

// Calcula o comprimento da lista
int ListaEncad::getComprimento() const
{
    No *atual = head;

    int acumuladora = 0;
    while (atual != nullptr)
    {
        atual = atual->getProx();
        acumuladora++;
    }

    return acumuladora;
}

void ListaEncad::imprimeLista()
{
    No *atual = head; // Começa pelo primeiro nó (head)

    if (atual == nullptr)
    {
        cout << "A lista está vazia!" << endl;
        return;
    }

    cout << "Elementos da lista: ";
    while (atual != nullptr)
    {
        cout << atual->getInfo() << " ";
        atual = atual->getProx();
    }
    cout << endl;
}