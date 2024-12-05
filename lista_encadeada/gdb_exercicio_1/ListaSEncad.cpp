#include <iostream>
using namespace std;

#include "ListaSEncad.h"

// IMPLEMENTE AQUI
void ListaSEncad::InsereApos(int n, int s, int tamLista)
{
    if (primeiro == nullptr)
    {
        cout << "Lista Vazia!" << endl;
        return;
    }

    // Apontando para o primeiro da lista!
    NoSEncad *atual = this->primeiro;

    // Enquanto atual diferente de nullptr (último próximo)
    while (atual != nullptr)
    {
        if (atual->ObterValor() == n)
        {
            cout << "N encontrado!" << endl;
            NoSEncad *novo_no = new NoSEncad(s);
            cout << "Endereco do novo_no: " << novo_no << endl;
            cout << "Valor do novo no: " << novo_no->ObterValor() << endl;
            novo_no->AlteraProximo(atual->ObterProximo());
            cout << "Endereco do proximo do novo no: " << novo_no->ObterProximo() << endl;
            atual->AlteraProximo(novo_no);
            if (atual->ObterProximo() == novo_no)
            {
                atual = novo_no;
                cout << "No adicionado com sucesso!" << endl;
            }
            else
            {
                cout << "Novo no não conectado a lista encadeada!" << endl;
                break;
            }
            cout << endl;
        }
        else
        {
            // Andar com o ponteiro atual até encontrar N
            cout << "Endereco do atual: " << atual << endl;
            cout << "Endereco do proximo do atual: " << atual->ObterProximo() << endl;
            cout << "Valor do atual: " << atual->ObterValor() << endl;
            cout << endl;
            cout << "Ponteiro andou!";
            cout << endl;
            atual = atual->ObterProximo();
        }
    }
}
// }

ListaSEncad::ListaSEncad() : primeiro(nullptr)
{
}

// Verifica se lista está vazia
bool ListaSEncad::EhVazia()
{
    return this->primeiro == nullptr;
}

// Insere valor na frente da lista
void ListaSEncad::InserePrimeiro(int valor)
{

    // Se lista vazia, crie novo nó e faça primeiro apontar para ele
    if (this->primeiro == nullptr)
    {
        this->primeiro = new NoSEncad(valor);
        return;
    }

    // Para lista não vazia,
    // Crie novo nó, faça o atual primeiro ser
    // o proximo do novo no e faça primeiro apontar
    // para o novo no.

    NoSEncad *node = new NoSEncad(valor);
    node->AlteraProximo(primeiro);
    primeiro = node;
}

// Insere valor na ultima posição da lista
void ListaSEncad::Insere(int valor)
{

    // Se lista vazia, crie novo nó e faça primeiro apontar para ele
    if (this->primeiro == nullptr)
    {
        this->primeiro = new NoSEncad(valor);
        return;
    }

    // Percorrer a lista até chegar no ultimo nó
    NoSEncad *atual = primeiro;
    while (atual->ObterProximo() != nullptr)
        atual = atual->ObterProximo();

    // Aloque o novo no e faça o proximo do ultimo atual apontar
    // para o proximo no
    NoSEncad *node = new NoSEncad(valor);
    atual->AlteraProximo(node);
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
