#include "listaEncad.h"
#include "noEncad.h"
#include <iostream>

using namespace std;

// Construtor: inicializa a lista como vazia
ListaEncad::ListaEncad()
{
    head = nullptr;
    aux = nullptr;
    n = 0;
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
    if (head == nullptr)
    {
        No *p = new No();
        p->setInfo(valor);
        p->setProx(nullptr);
        head = p;
    }
    else
    {
        No *novoNo = new No();
        novoNo->setInfo(valor);
        novoNo->setProx(head);
        head = novoNo;
    }
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

void ListaEncad::insereOrdenado(int valor)
{
    No *novoNo = new No();
    novoNo->setInfo(valor);

    // Caso a lista esteja vazia ou o novo valor é menor que o primeiro nó
    if (head == nullptr || valor < head->getInfo())
    {
        novoNo->setProx(head); // O novo nó aponta para o antigo início
        head = novoNo;       // Atualiza o início da lista
        return;
    }

    // Percorre a lista para encontrar a posição correta
    No *atual = head;
    while (atual->getProx() != nullptr && atual->getProx()->getInfo() < valor)
    {
        atual = atual->getProx();
    }

    // Insere o novo nó na posição correta
    novoNo->setProx(atual->getProx());
    atual->setProx(novoNo);
}