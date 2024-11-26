#include <iostream>
using namespace std;

#include "ListaCont.h"

ListaCont::ListaCont(int max)
{
    _max = max;
    _n = 0;
    _vet = new int[max];
}

ListaCont::~ListaCont()
{
    delete [] _vet;
}

void ListaCont::insere(int val)
{
    if(_n == _max)
    {
        cout << "Lista Cheia" << endl;
        return;
    }

    _vet[_n++] = val;
}


void ListaCont::insereInicio(int val)
{
    if(_n == _max)
    {
        cout << "Lista Cheia" << endl;
        return;
    }

    for(int i = _n; i > 0; i--)
        _vet[i] = _vet[i-1];

    _vet[0] = val;
    _n++;
}

int ListaCont::obter(int k)
{
    if(k<0 || k >= _n)
    {

        std::runtime_error("posicao invalida");
    }

    return _vet[k];
}

void ListaCont::altera(int k, int val)
{
    if(k<0 || k >= _n)
    {
        cout << "posicao invalida" << endl;
        return;
    }

    _vet[k] = val;
}

void ListaCont::removeUltimo()
{
    if(_n == 0)
        return;

    _n--;
    
}

void ListaCont::removePrimeiro()
{
    if(_n == 0)
        return;

    for(int i = 1; i < _n; i++)
        _vet[i-1] = _vet[i];
    _n--;

}

void ListaCont::removePosicao(int k)
{
    if(_n == 0)
        return;
    if(k<0 || k >= _n)
        return;

    for(int i = k+1; i < _n; i++)
        _vet[i-1] = _vet[i];

    _n--;

}

void ListaCont::inserePosicao(int k, int val)
{
    if(_n == _max)
    {
        cout << "Lista Cheia" << endl;
        return;
    }

    if(k<0 || k > _n)
    {
        cout << "posicao invalida" << endl;
        return;
    }

    for(int i = _n; i > k; i--)
        _vet[i] = _vet[i-1];

    _vet[k] = val;
    _n++;
}

int ListaCont::numElem()
{
    return _n;
}
