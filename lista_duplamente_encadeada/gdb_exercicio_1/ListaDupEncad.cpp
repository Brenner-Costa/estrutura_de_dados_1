
#include "ListaDupEncad.h"
#include <iostream>

using namespace std;

// IMPLEMENTE AQUI
void ListaDupEncad::InserePos(int val, int pos)
{

    NoDupEncad *atual = primeiro;
    NoDupEncad *novoNo = new NoDupEncad(val);

    int acumuladora = 0;

    if (pos > 0 && pos < n)
    {
        while (atual != nullptr)
        {
            if (acumuladora == pos)
            {
                // Como eu possuo o ponteiro para o anterior, nao preciso de um aux
                // 1 - novoNo -> apontar para o proximo do NOanterior (no caso o atual)
                // 2 - Fazer o NOanterior apontar o proximo para o novoNO (vai deixar de apontar para atual)
                // 3 - Fazer o ant do novoNo apontar para o ant do Atual
                // 4 - O ponteiro ant de atual aponte para o novoNo (fazendo isso, o ponteiro ant de atual deixa de apontar para o NOanterior e aponta para o novoNO)

                cout << "Posicao " << acumuladora << " encontrada!" << endl;
                NoDupEncad *tmp = atual->ObterAnterior();
                novoNo->AlterarProximo(tmp->ObterProximo());
                tmp->AlterarProximo(novoNo);
                novoNo->AlterarAnterior(atual->ObterAnterior());
                atual->AlterarAnterior(novoNo);
            }
            else
            {
                atual = atual->ObterProximo();
            }
            acumuladora++;
        }
    } else {
        cout << "Posição inválida!" << endl;
        return;
    }
}

// construtor
ListaDupEncad::ListaDupEncad()
{
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

// destrutor
ListaDupEncad::~ListaDupEncad()
{
    NoDupEncad *p = primeiro;
    NoDupEncad *t;
    while (p != NULL)
    {
        t = p->ObterProximo();
        delete p;
        p = t;
    }
}

// inserção na primeira posição da lista
void ListaDupEncad::InserePrimeiro(int val)
{
    NoDupEncad *p = new NoDupEncad(val);
    if (primeiro == NULL)
    {
        primeiro = p;
        ultimo = p;
        n++;
        return;
    }
    p->AlterarProximo(primeiro);
    primeiro->AlterarAnterior(p);
    primeiro = p;
    n++;
}

// inserção de um elemento no final da lista
void ListaDupEncad::Insere(int val)
{
    NoDupEncad *p = new NoDupEncad(val);
    if (primeiro == NULL)
    {
        primeiro = p;
        ultimo = p;
        n++;
        return;
    }
    ultimo->AlterarProximo(p);
    p->AlterarAnterior(ultimo);
    ultimo = p;
    n++;
}

// impressão dos elementos da lista
void ListaDupEncad::Imprime()
{
    NoDupEncad *p = primeiro;
    std::cout << "[";
    while (p != NULL)
    {
        std::cout << p->ObterValor() << " ";
        if (p->ObterProximo() != nullptr)
        {
            std::cout << ", ";
        }
        p = p->ObterProximo();
    }
    std::cout << "]" << std::endl;
}

// impressão dos elementos da lista em ordem reversa
void ListaDupEncad::ImprimeReverso()
{
    NoDupEncad *p = ultimo;
    std::cout << "[";
    while (p != NULL)
    {
        std::cout << p->ObterValor() << " ";
        if (p->ObterAnterior() != nullptr)
        {
            std::cout << ", ";
        }
        p = p->ObterAnterior();
    }
    std::cout << "]" << std::endl;
}

// busca de um elemento na lista
NoDupEncad *ListaDupEncad::BuscaNo(int val)
{
    NoDupEncad *p = primeiro;
    while (p != NULL)
    {
        if (p->ObterValor() == val)
        {
            return p;
        }
        p = p->ObterProximo();
    }
    return nullptr;
}

// retorna o número de elementos da lista
int ListaDupEncad::Tamanho()
{
    return n;
}
