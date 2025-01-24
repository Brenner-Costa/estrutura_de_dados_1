#include "ListaEncad.h"
#include <iostream>
using namespace std;

// Construtor
ListaEncad::ListaEncad() {
    primeiro = nullptr;
    ultimo = nullptr;
    n = 0;
}

// Destrutor - Libera memória
ListaEncad::~ListaEncad() {
    No* atual = primeiro;
    while (atual != nullptr) {
        No* temp = atual;
        atual = atual->getProx();
        delete temp;
    }
}

// Função para inserir um valor no final da lista
void ListaEncad::insereFinal(int val) {
    No* novo = new No();
    novo->setInfo(val);

    if (primeiro == nullptr) {
        primeiro = novo;
        ultimo = novo;
    } else {
        ultimo = novo;
    }
    n++;
}

// Função para exibir todos os elementos da lista
void ListaEncad::exibirLista() {
    No* atual = primeiro;
    while (atual != nullptr) {
        cout << atual->getInfo() << " ";
        atual = atual->getProx();
    }
    cout << endl;
}

// Função para imprimir os elementos que estão ordenados em relação aos vizinhos
void ListaEncad::imprimeElemsEmOrdem() {
    //So vai imprimir se o valor de P:
    // P > Anterior
    // P < Sucessor
    // Criar um ponteiro auxiliar para o anterior e iniciar com nullptr
    //Percorre a lista 
    //cria um ponteiro que aponta para o primeiro
    // percorrer a lista e a cada nó fazer a verificação
        // Se a info do anterior for menor e a info do prox for maior que o p 
            //Vai exibir o p
            //Se não, vai andar para o próximo nó
    //Para os nós da extremidade:
        //Se o prox de p for Nullptr
            //verificar apenas se o ponteiro anterior é menor que p
        //Se o anteriro de p for Nullptr, comparar apenas com o primeiro.

    No *anterior = nullptr;
    No *atual = primeiro;

    while(atual != nullptr) {
        if(anterior == nullptr) {
            cout << "Teste1" << endl;
            //Estamos no inicio da lista
            if(atual->getInfo() < atual->getProx()->getInfo()) {
                cout << "Exibe: " << atual->getInfo() << endl;
                anterior = atual;
                atual = atual->getProx(); 
            } else {
                //Se a condição nao for atendida, andar para o próximo
                anterior = atual;
                atual = atual->getProx();
                return;
            } 
        }

        if(atual->getProx() == nullptr) {
            //Final da lista
            if(anterior->getInfo() < atual->getInfo()) {
                cout << "Exibe: " << atual->getInfo() << endl;
                anterior = atual;
                atual = atual->getProx();

            } else {
                //anda para o próximo
                anterior = atual;
                atual = atual->getProx();
                break;
            }
        }

        if(anterior->getInfo() < atual->getInfo() && atual->getInfo() < atual->getProx()->getInfo()) {
            cout << "Intermediário" << endl;
            cout << atual->getInfo() << endl;
            anterior = atual;
            atual = atual->getProx();
        } else {
            anterior = atual;
            atual = atual->getProx();
        }   
    }    
}
