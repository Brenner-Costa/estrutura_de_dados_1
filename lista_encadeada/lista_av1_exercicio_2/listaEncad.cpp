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
    if(head == nullptr) {
        No *p = new No();
        p->setInfo(valor);
        p->setProx(nullptr);
        head = p;
    } else {
        No *novoNo = new No();
        novoNo->setInfo(valor);
        novoNo->setProx(head);
        head = novoNo;
    }
}

void ListaEncad::imprimeLista() {
    No* atual = head; // Começa pelo primeiro nó (head)
    
    if (atual == nullptr) {
        cout << "A lista está vazia!" << endl;
        return;
    }

    cout << "Elementos da lista: ";
    while (atual != nullptr) { 
        cout << atual->getInfo() << " "; 
        atual = atual->getProx();     
    }
    cout << endl;
}

int ListaEncad::contaMaiores(int valor) {
    No *atual = head;

    int acumuladora = 0;
    while(atual != nullptr) {
        if(atual->getInfo() > valor) {
            acumuladora++;
            // cout << "Maior: " << atual->getInfo() << endl;
            atual = atual->getProx();
        } else {
            // cout << "Menor: " << atual->getInfo() << endl;
            atual = atual->getProx();
        }
    }

    return acumuladora;
}