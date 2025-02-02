#include "ArvBin.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Construtor e destrutor
ArvBin::ArvBin() : raiz(nullptr) {}
ArvBin::~ArvBin() {}

NoArvBin *ArvBin::getRaiz()
{
    return raiz;
}

void ArvBin::setRaiz(NoArvBin *raiz)
{
    if (this->raiz == nullptr)
    {
        this->raiz = raiz;
        return;
    }
    cout << "A raiz da arvore ja foi definida" << endl;
}

int ArvBin::contar()
{
    int acumulador = 0;
    return contarNos(raiz, acumulador);
}

int ArvBin::contarNos(NoArvBin *no, int acumulador)
{

    if (no == nullptr)
    {
        return 0;
    }

    int noEsq = contarNos(no->getEsq(), acumulador);
    int noDir = contarNos(no->getDir(), acumulador);

    acumulador++;

    return acumulador = acumulador + noEsq + noDir;
}

// Função pública
int ArvBin::impares()
{
    return contarImpares(raiz); // Chama a função auxiliar com a raiz
}

// Função auxiliar recursiva para contar nós ímpares
int ArvBin::contarImpares(NoArvBin *no)
{
    if (no == nullptr)
    {
        // Caso base: nó nulo não contribui para a contagem
        return 0;
    }

    // Faz o percurso pós-ordem:
    // 1. Visita a subárvore esquerda
    int imparesEsq = contarImpares(no->getEsq());

    // 2. Visita a subárvore direita
    int imparesDir = contarImpares(no->getDir());

    // 3. Processa o nó atual:
    //    Verifica se o valor armazenado é ímpar
    int valorAtual = (no->getChave() % 2 != 0) ? 1 : 0;

    // Soma os resultados
    return imparesEsq + imparesDir + valorAtual;
}

int ArvBin::soma()
{
    int acumulador = 0;
    return somaValoresNo(raiz, acumulador);
}

int ArvBin::somaValoresNo(NoArvBin *no, int acumulador)
{
    if (no == nullptr)
    {
        acumulador = acumulador + 0;
        return 0;
    }

    int acumuladorEsquerdo = somaValoresNo(no->getEsq(), acumulador);
    int acumuladorDireito = somaValoresNo(no->getDir(), acumulador);

    acumulador = acumuladorEsquerdo + acumuladorDireito + no->getChave();

    return acumulador;
}

float ArvBin::media(int somaNos)
{
    int acumulador = 0;
    return mediaNos(raiz, somaNos, acumulador);
}

float ArvBin::mediaNos(NoArvBin *no, int soma, int acumulador)
{
    // Só contar a quantidade de nós e dividir pelo somatório dos nós que veio como parÂmetro.

    int quantNos = contar();

    return static_cast<float>(soma) / quantNos;
    // retornar a média
}

int ArvBin::pares()
{
    return contarPares(raiz);
}

int ArvBin::contarPares(NoArvBin *no)
{
    if (no == nullptr)
    {
        return 0;
    }

    int esq = contarPares(no->getEsq());
    int dir = contarPares(no->getDir());

    int valorAtual = (no->getChave() % 2 != 0) ? 0 : 1;

    return esq + dir + valorAtual;
}

float ArvBin::mediaPares(int somaNos)
{
    return mediaNosPares(raiz, somaNos);
}

float ArvBin::mediaNosPares(NoArvBin *no, int soma)
{
    if (no == nullptr)
    {
        return 0;
    }

    int nosPares = pares();

    return static_cast<float>(soma) / nosPares;
}

int ArvBin::maior()
{
    int aux = 0;
    return maiorNo(raiz, aux);
}

int ArvBin::maiorNo(NoArvBin *no, int auxVal)
{
    if (no == nullptr)
    {
        return 0;
    }

    int esq = maiorNo(no->getEsq(), auxVal);
    int dir = maiorNo(no->getDir(), auxVal);

    // comparar e ver qual é maior -> esq ou dir
    //  dependendo de quem for, vou comparar com o atual e retonar

    int filhoMaior = (esq > dir) ? esq : dir;

    int noMaior = (filhoMaior >= no->getChave()) ? auxVal = filhoMaior : auxVal = no->getChave();

    return noMaior;
}

int ArvBin::menor()
{
    if (raiz == nullptr)
    {
        throw std::runtime_error("Árvore vazia!"); // Evita acessar null
    }
    return menorNo(raiz, raiz->getChave());
}

int ArvBin::menorNo(NoArvBin *no, int auxVal)
{
    if (no == nullptr)
    {
        return auxVal;
    }

    int esq = menorNo(no->getEsq(), no->getChave()); // Passa o valor do nó atual
    int dir = menorNo(no->getDir(), no->getChave());

    return std::min({auxVal, esq, dir}); // Retorna o menor valor encontrado

    /*

    LÓGICA ORIGINAL -> PRECISEI DE AJUDA PARA CONSEGUIR TRATAR O CASO DO ZERO.

    - O algoritmo estava correto, porém foi necessário usar uma biblioteca para lidar com essa excessão.

    if(no == nullptr) {
        return 0;
    }

    int esq = menorNo(no->getEsq(), auxVal);
    int dir = menorNo(no->getDir(), auxVal);

    int filhoMenor = (esq < dir) ? esq : dir;

    int noMenor = (filhoMenor < no->getChave()) ? auxVal = filhoMenor : auxVal = no->getChave();

    return noMenor;

    */
}

int ArvBin::maiores(int val)
{
    return maioresQueVal(raiz, val);
}

int ArvBin::maioresQueVal(NoArvBin *no, int val)
{

    // Acumulador não está a
    if (no == nullptr)
    {
        return 0;
    }

    int esq = maioresQueVal(no->getEsq(), val);
    int dir = maioresQueVal(no->getDir(), val);

    return (no->getChave() > val ? 1 : 0) + esq + dir;
}

void ArvBin::contaElegante(NoArvBin *raiz, int contPares, int contFolhas)
{
}

void ArvBin::conta()
{
}
