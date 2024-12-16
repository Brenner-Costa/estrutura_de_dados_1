#include "ListaCirc.h"
#include "noEncad.h"
#include <iostream>

using namespace std;

// Construtor: inicializa a lista como vazia
ListaCirc::ListaCirc()
{
    head = nullptr;
    ultimo = nullptr;
}

// Destrutor: libera a memória alocada para os nós
ListaCirc::~ListaCirc()
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
void ListaCirc::adiciona(int valor)
{
    if (head == nullptr)
    {
        No *p = new No();
        p->setInfo(valor);
        p->setProx(nullptr);
        ultimo = p; //Como esse e o primeiro no, e a funcao adiciona no inicio, ele vai continuar sendo o ultimo
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

void ListaCirc::imprimeLista()
{
    No *atual = head; // Começa pelo primeiro nó (head)

    if (atual == nullptr)
    {
        cout << "A lista está vazia!" << endl;
        return;
    }

    while (atual != ultimo)
    {
        cout << atual->getInfo() << " ";
        atual = atual->getProx();
    }
    cout << endl;
}

void ListaCirc::insereOrdenado(int valor)
{
    No *novoNo = new No();
    novoNo->setInfo(valor);

    // Caso a lista esteja vazia ou o novo valor é menor que o primeiro nó
    if (head == nullptr || valor < head->getInfo())
    {
        novoNo->setProx(head); // O novo nó aponta para o antigo início
        head = novoNo;         // Atualiza o início da lista
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

void ListaCirc::insereFinal(int val)
{
    cout << "Insere no final" << endl;
    cout << ultimo->getInfo() << endl;

    No *novoNo = new No();
    novoNo->setInfo(val);

    ultimo = novoNo; //Antes o ultimo apontava para o primeiro
    cout << ultimo->getInfo() << endl;
    novoNo->setProx(head);
}

int ListaCirc::remove(int valor)
{
    No *atual = head;
    No *anterior = nullptr;
    cout << "entrei1" << endl;

    while (atual != ultimo)
    {
        if (atual->getInfo() == valor)
        {
            cout << "entrei" << endl;
            No *tmp = atual;
            int valRemovido = tmp->getInfo();
            atual = atual->getProx();
            anterior->setProx(atual);
            delete tmp;
            tmp = nullptr;

            return valRemovido;
        }
        else
        {
            anterior = atual;
            atual = atual->getProx();
        }
    }

    cout << "Valor não encontrado!" << endl;
    return 0;
}

bool ListaCirc::busca(int val)
{
    No *atual = head;

    while (atual != ultimo)
    {
        if(atual->getInfo() == val) {
            cout << "Valor encontrado! -> " << val << endl;
            return true;
        } else {
            atual = atual->getProx();
        }
    }

    cout << "Valor não encontrado!" << endl;
    return false;
}