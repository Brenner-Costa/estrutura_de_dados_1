#include "ABB.h"

ABB::ABB() : raiz(nullptr) {}

ABB::~ABB()
{
    destruir(raiz);
}

void ABB::destruir(NoABB *no)
{
    if (no)
    {
        destruir(no->getEsq());
        destruir(no->getDir());
        delete no;
    }
}

int ABB::kMaior(int k)
{
    int contador = 0;
    int resultado = 0;
    percursoInvertido(raiz, k, contador, resultado);

    return resultado;
}

void ABB::percursoInvertido(NoABB *no, int k, int &contador, int &resultado)
{
    if (no == nullptr)
    {
        return;
    }

    // direita -> raiz -> esquerda (PERCURSO INVERSO)

    percursoInvertido(no->getDir(), k, contador, resultado);

    no->getChave();
    contador++;

    if (contador == k)
    {
        resultado = no->getChave();
        return;
    }

    percursoInvertido(no->getEsq(), k, contador, resultado);
}

void ABB::insere(int chave)
{
    if (raiz == nullptr)
    {
        raiz = new NoABB(chave);
        return;
    }
    NoABB *atual = raiz;
    NoABB *anterior = nullptr;
    while (atual != nullptr)
    {
        anterior = atual;
        if (chave < atual->getChave())
        {
            atual = atual->getEsq();
        }
        else
        {
            atual = atual->getDir();
        }
    }
    if (chave < anterior->getChave())
    {
        anterior->setEsq(new NoABB(chave));
    }
    else
    {
        anterior->setDir(new NoABB(chave));
    }
}