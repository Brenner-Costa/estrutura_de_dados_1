#include <iostream>
using namespace std;

#include "ListaSEncad.h"

// IMPLEMENTE AQUI
void ListaSEncad::InsereOrdenado(int v)
{
    NoSEncad *p = new NoSEncad();
    NoSEncad *ant = nullptr, *atual = primeiro; //atual recebe o endereco de memoria apontado por primeiro 
    //atual sempre vai apontar para o primeiro
    p->AlteraValor(v);
    while (atual != nullptr && v >= atual->ObterValor())
    {
        //Para o atual ser diferente de nullptr a lista precisa ter pelo menos 1 nó
        // O valor a ser adicionado na lista precisa ser maior que o valor do atual 
        //Esse while basicamente faz o atual e anterior andarem do primeiro nó até o último.
        ant = atual; //ant recebe o endereco de memoria armazenado em atual
        atual = atual->ObterProximo();
    }
    if (ant == nullptr)
    {
    
        p->AlteraProximo(primeiro); // APONTA PARA O ANTIGO ENDEREÇO DE MEMORIA APONTADO POR PRIMEIRO
        primeiro = p; //PRIMEIRO AGORA APONTA PARA O NOVO PRIMEIRO NÓ DA LISTA
    }
    else
    {
        ant->AlteraProximo(p); //FAZ O ANTERIOR APONTAR PARA O ÚLTIMO QUE É O P 
        p->AlteraProximo(atual); //SEMPRE VAI APONTAR PARA NULL PORQUE ELE SERÁ O ÚLTIMO DA LISTA
    }
}

// Construtor
ListaSEncad::ListaSEncad() : primeiro(nullptr)
{
}

// Verifica se lista está vazia
bool ListaSEncad::EhVazia()
{
    return this->primeiro == nullptr;
}

// Retorna o tamanho da lista
int ListaSEncad::Tamanho()
{
    int n = 0;
    NoSEncad *tmp = primeiro;
    // percorre a lista no a no contando
    while (tmp != nullptr)
    {
        tmp = tmp->ObterProximo();
        n++;
    }

    return n;
}

// Busca nó que contem valor
NoSEncad *ListaSEncad::Procura(int valor)
{
    NoSEncad *tmp = primeiro;
    // Percorre a lista no-a-no, comparando
    // o valor armazendo com o pesquisado.
    // Ao encontrar, retorno o ponteiro do nó
    while (tmp != nullptr)
    {
        if (tmp->ObterValor() == valor)
            return tmp;
        tmp = tmp->ObterProximo();
    }

    // Se valor nao encontrada, retorne nullptr
    return nullptr;
}

// Destrutor da classe
ListaSEncad::~ListaSEncad()
{

    NoSEncad *no = this->primeiro;
    while (no != nullptr)
    {
        NoSEncad *tmp = no->ObterProximo();
        delete no;
        no = tmp;
    }

    this->primeiro = nullptr;
}

// Remove o no da frente da lista
void ListaSEncad::RemovePrimeiro()
{

    if (this->primeiro == nullptr)
        return;

    // Faz tmp apontar para no da frente atual
    NoSEncad *tmp = this->primeiro;

    // O primeiro da lista passa ser o proximo da primeiro
    this->primeiro = tmp->ObterProximo();

    // delete o no apontado por tmp
    delete tmp;
}

// Remove o ultimo elemento da lista
void ListaSEncad::RemoveUltimo()
{

    if (this->primeiro == nullptr)
        return;

    // percorre a lista para chegar no ultimo No
    NoSEncad *no = this->primeiro;

    while (no->ObterProximo() != nullptr)
        no = no->ObterProximo();

    // Delete o ultimo no
    delete no;
    no = nullptr;
}

// Remover no que tenha valor armazenado
void ListaSEncad::Remove(int valor)
{
    // Se lista vazia, não faça nada
    if (this->primeiro == nullptr)
        return;

    // Se houver apenas um elemento,
    // remove ele se tem o valor procurado e aponta primeiro para null
    if (this->primeiro->ObterProximo() == nullptr)
    {
        if (this->primeiro->ObterValor() == valor)
        {
            delete this->primeiro;
            this->primeiro = nullptr;
        }
        return;
    }

    // percorre a lista ate encontrar o no com valor
    // armazenado um ponteiro para nó anterior
    NoSEncad *no = this->primeiro;
    NoSEncad *no_ant = nullptr;

    while (no != nullptr)
    {
        if (no->ObterValor() == valor)
            break;
        no_ant = no;
        no = no->ObterProximo();
    }

    // verifica se no é valido
    if (no != nullptr)
    {
        // faça o proximo anterior apontar para o proximo do atual
        no_ant->AlteraProximo(no->ObterProximo());

        // delete o atual
        delete no;
    }
}

// Imprime a lista
void ListaSEncad::Imprime()
{
    NoSEncad *no = this->primeiro;
    cout << "[";
    while (no != nullptr)
    {
        cout << no->ObterValor();
        if (no->ObterProximo() != nullptr)
            cout << " ,";
        no = no->ObterProximo();
    }
    cout << "]" << endl;
}
