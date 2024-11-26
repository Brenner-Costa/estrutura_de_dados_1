#include <iostream>
using namespace std;

#include "ListaCont.h"

// IMPLEMENTE AQUI
/**
 *    Une a lista com a lista l incluindo apenas os elementos
 *    distintos. A lista resultante deve conter apenas elementos distintos.
 *    O método de deve ser capaz de aumentar a capacidade da lista caso seja necessário.
 */

void ListaCont::concatena(ListaCont &l)
{
  for (int i = 0; i < l.numElem(); i++) {
        int elemento = l.obter(i);

        bool existe = false;
        for (int j = 0; j < _n; j++) {
            if (_vet[j] == elemento) {
                existe = true;
                break;
            }
        }

        if (!existe) {
            if (_n == _max) {
                int novoTamanho = _max * 2;
                int *novoVet = new int[novoTamanho];

                for (int k = 0; k < _n; k++) {
                    novoVet[k] = _vet[k];
                }

                delete[] _vet;
                _vet = novoVet;
                _max = novoTamanho;
            }

            _vet[_n] = elemento;
            _n++;
        }
    }
}

ListaCont::ListaCont(int max)
{
    _max = max;
    _n = 0;
    _vet = new int[max];
}

ListaCont::~ListaCont()
{
    delete[] _vet;
}

void ListaCont::insere(int val)
{
    if (_n == _max)
    {
        cout << "Lista Cheia" << endl;
        return;
    }

    _vet[_n++] = val;
}

void ListaCont::insere_unico(int val)
{
    if (_n == _max)
    {
        cout << "Lista Cheia !!!!!" << endl;
        return;
    }

    for (int i = 0; i < _n; i++)
        if (val == _vet[i])
            return;

    _vet[_n++] = val;
}

void ListaCont::insereInicio(int val)
{
    if (_n == _max)
    {
        cout << "Lista Cheia" << endl;
        return;
    }

    for (int i = _n; i > 0; i--)
        _vet[i] = _vet[i - 1];

    _vet[0] = val;
    _n++;
}

int ListaCont::obter(int k)
{
    if (k < 0 || k >= _n)
    {

        std::runtime_error("posicao invalida");
    }

    return _vet[k];
}

void ListaCont::altera(int k, int val)
{
    if (k < 0 || k >= _n)
    {
        cout << "posicao invalida" << endl;
        return;
    }

    _vet[k] = val;
}

void ListaCont::removeUltimo()
{
    if (_n == 0)
        return;

    _n--;
}

void ListaCont::removePrimeiro()
{
    if (_n == 0)
        return;

    for (int i = 1; i < _n; i++)
        _vet[i - 1] = _vet[i];
    _n--;
}

void ListaCont::removePosicao(int k)
{
    if (_n == 0)
        return;
    if (k < 0 || k >= _n)
        return;

    for (int i = k + 1; i < _n; i++)
        _vet[i - 1] = _vet[i];

    _n--;
}

void ListaCont::inserePosicao(int k, int val)
{
    if (_n == _max)
    {
        cout << "Lista Cheia" << endl;
        return;
    }

    if (k < 0 || k > _n)
    {
        cout << "posicao invalida" << endl;
        return;
    }

    for (int i = _n; i > k; i--)
        _vet[i] = _vet[i - 1];

    _vet[k] = val;
    _n++;
}

int ListaCont::numElem()
{
    return _n;
}
