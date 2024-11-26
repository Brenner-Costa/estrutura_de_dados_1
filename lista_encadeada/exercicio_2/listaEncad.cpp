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
    if (n == 0)
    {
        // Lista vazia e colocando o primeiro nó na lista
        No *p = new No();
        p->setInfo(valor);
        p->setProx(nullptr);
        head = p;
        aux = head;
        n++;
    }

    No *new_no = new No();
    head = new_no;
    new_no->setInfo(valor);
    new_no->setProx(aux);

    cout << n << endl;
    aux = new_no;
    n++;
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
    //Verificar se o info de um nó é maior que val
    // No *atual = head;
    // int maiores = 0;

    // for(int i = 0; i < n; i++) {
    //     if(atual->getInfo() < valor) {
    //         atual->setProx()
    //     }
    // }

    // while(atual->getInfo() ) {
    //     cout << "Teste" << endl;
    //     cout << atual-> getInfo() << endl;
    //     maiores++;
    // }
    
    // return maiores;
}