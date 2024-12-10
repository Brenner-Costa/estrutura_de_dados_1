
#include <iostream>
#include "ListaDupEncad.h"

using namespace std;
// IMPLEMENTE AQUI
ListaDupEncad *ListaDupEncad::ExtraiSublista(int start, int end)
{

    /*
       Tirar os elementos da lista e colocar em outra lista

       Percorrer a lista normalmente com o ponteiro atual ate encontrar o start
       Cria um ponteiro para apontar para o start
       Remove o start da antiga lista e ele sera o primeiro da nova lista
       o ponteiro atual precisa andar ate o and para ir adicionando na nova lista (Listadupencad)

       Fazer o anterior ao start apontar para o proximo de end
       o *ant de end apontar para o anterior do start

       Os elementos que estão entre start e and vao manter as mesmas ligacoes entre os ponteiros.

       Retornar a lista nova!!!!!!

    */

    NoDupEncad *atual = primeiro;

    ListaDupEncad *novaLista;
    NoDupEncad *pont_start = nullptr;
    NoDupEncad *pont_end = nullptr;
    NoDupEncad *aux = nullptr;

    int contador = 0;
    while(atual != nullptr) {
        cout << "contador: " << contador << endl;
        if(contador == start) {
            pont_start = atual;
            cout << "Ponteiro Start iniciado!" << endl;
        } else if (contador == end) {
            pont_end = atual;
            cout << pont_end->ObterValor() << endl;
            cout << "Ponteiro end iniciado!" << endl;
            aux = pont_start->ObterAnterior();
            aux->AlterarProximo(pont_end->ObterProximo()); //O nó anterior ao start receber o proximo de end

            aux = pont_end->ObterProximo();
            aux->AlterarAnterior(pont_start->ObterAnterior());
            pont_start->AlterarAnterior(nullptr); //Desconecta start da lista original
            pont_end->AlterarProximo(nullptr); // desconectar o end da lista original
            cout << "Nós Desconectados da lista original!" << endl;
            
        } else {
            atual = atual->ObterProximo();
        }
        contador++;
    } 

    while (pont_start!= nullptr)
    {
        cout << "Cheguei: " << pont_start->ObterValor();
        novaLista->Insere(pont_start->ObterValor());
        
        pont_start = pont_start->ObterProximo();
    }
    
    return novaLista;

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
