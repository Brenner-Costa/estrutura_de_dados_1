
#include  <iostream>
#include "NoDupEncad.h"

using namespace std;

// construtor
NoDupEncad::NoDupEncad(int val)
{
    valor = val;
    prox = nullptr;
    ant = nullptr;
}

// retorna o valor armazenado no nó
int NoDupEncad::ObterValor()
{
    return valor;
}

// altera o valor armazenado no nó
void NoDupEncad::AlterarValor(int val)
{
    valor = val;
}

// retorna o ponteiro para o próximo nó
NoDupEncad* NoDupEncad::ObterProximo()
{
    return prox;
}

// altera o ponteiro para o próximo nó
void NoDupEncad::AlterarProximo(NoDupEncad *p)
{
    prox = p;
}

// retorna o ponteiro para o nó anterior
NoDupEncad* NoDupEncad::ObterAnterior()
{
    return ant;
}

// altera o ponteiro para o nó anterior
void NoDupEncad::AlterarAnterior(NoDupEncad *p)
{
    ant = p;
}
