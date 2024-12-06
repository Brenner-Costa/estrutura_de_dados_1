
#include <iostream>
#include "ListaDupEncad.h"

using namespace std;

// IMPLEMENTE AQUI

// remoção de um elemento da lista
void ListaDupEncad::Remove(int val)
{
    // Remove o valor presente na lista
    //  E se o valor nao estiver na lista?

    NoDupEncad *atual = primeiro;

    while (atual != nullptr)
    {

        if (atual->ObterValor() == val)
        {
            /*

            LÓGICA

                VER COMO FICA A QUESTAO DO PRIMEIRO NO DA LISTA 

                1 - O proximo do NoAnterior vai pegar o proximo do no que sera removido
                2 - O proximo do no que sera removido vai para nullptr
                3 - O ant do atual vai pegar o ant do no que sera removido (Assim ele vai apontar para o NoAnterior do que sera removido)
                4 - 0 ant do no que sera removido vai receber nullptr
                5 - dar um delete e setar para null -> CUIDADO

                FAZER O ATUAL APONTAR PARA O PROXIMO
                TMP PEGA O ANTIGO ATUAL E DELETA
                ANTERIOR FICA PRA ATUALIZAR OS PONTEIROS DO ANTERIOR DO ANTIGO ATUAL
            */

            NoDupEncad *tmp = atual;
            atual = atual->ObterProximo();
            // cout << "Valor - TMP: " << tmp->ObterValor() << endl;
            // cout << "Próximo - TMP: " << tmp->ObterProximo() << endl;
            // cout << "Anterior - TMP: " << tmp->ObterAnterior() << endl;
            // cout << "Valor - ATUAL: " << atual->ObterValor() << endl;
            // cout << "Próximo - ATUAL: " << atual->ObterProximo() << endl;
            // cout << "Anterior - ATUAL: " << atual->ObterAnterior() << endl;

            NoDupEncad *anterior = tmp->ObterAnterior();
            // cout << "Valor - ANTERIOR: " << anterior->ObterValor() << endl;
            // cout << "Próximo - ANTERIOR: " << anterior->ObterProximo() << endl;
            // cout << "Anterior - ANTERIOR: " << anterior->ObterAnterior() << endl;

            anterior->AlterarProximo(tmp->ObterProximo());
            tmp->AlterarProximo(nullptr);
            atual->AlterarAnterior(tmp->ObterAnterior());
            tmp->AlterarAnterior(nullptr);

            delete tmp;
            tmp = nullptr;
        }
        else
        {
            atual = atual->ObterProximo();
        }
    }
}

// remoção de um elemento em uma posição específica
void ListaDupEncad::RemovePos(int pos)
{
    /*
        LÓGICA

        Se for o primeiro que vai ser removido, apontar o primeiro para o novo no

        1 - Cria um contador para verificar em qual posicao o laço de repetição está
        2 - Criar verificação para ver se a acumuladora esta igual a pos
        3 - Se estiver -> Cria a mesma lógica para manipular os ponteiros (No caso a lógica da REMOVE)
        4 - Se não estiver -> Exibe uma mensagem e retorna nada

    */

    NoDupEncad *atual = primeiro;

    int contador = 0;
    if (pos > n || pos < 0)
    {
        cout << "Posição inválida!" << endl;
        return;
    }

    while (atual != nullptr)
    {
        if (contador == pos)
        {
            NoDupEncad *tmp = atual;
            atual = atual->ObterProximo();
            NoDupEncad *anterior = tmp->ObterAnterior();

            anterior->AlterarProximo(tmp->ObterProximo());
            tmp->AlterarProximo(nullptr);
            atual->AlterarAnterior(tmp->ObterAnterior());
            tmp->AlterarAnterior(nullptr);

            delete tmp;
            tmp = nullptr;
        }
        else
        {
            atual = atual->ObterProximo();
        }
        contador++;
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
NoDupEncad *ListaDupEncad::Busca(int val)
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
