#include <iostream>
#include <cstdlib>
#include "PilhaEncad.h"

using namespace std;

void PilhaEncad::empilha(int val)
{
    No *p = new No();
    p->setInfo(val);
    p->setProx(topo);
    topo = p;
}

int PilhaEncad::desempilha()
{
    if(topo != nullptr)
    {
        No *p = topo;
        topo = p->getProx();
        int val = p->getInfo();
        delete p;
        return val;
    }
    cout << "ERRO: Pilha vazia!" << endl;
    exit (1);
}

int PilhaEncad::getTopo()
{
    if(topo != nullptr)
        return topo->getInfo();
    cout << "ERRO: Pilha vazia!" << endl;
    exit (1);
}

bool PilhaEncad::vazia()
{
    return topo == nullptr;
}
