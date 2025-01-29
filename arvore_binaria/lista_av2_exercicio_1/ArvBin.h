#ifndef ARVBIN_H__
#define ARVBIN_H__

#include <iostream>
using namespace std;

class Arvbin;

class NoArvBin
{
    friend class ArvBin;

public:
    // Construtores
    // Construtor padrao
    NoArvBin(int chave) : chave(chave), esq(nullptr), dir(nullptr) {}

    // Cria um no com chave e ponteiros para os filhos
    NoArvBin(int chave, NoArvBin *esq, NoArvBin *dir) : chave(chave), esq(esq), dir(dir) {};

    // Metodos
    // Retorna a chave do no
    int getChave() { return chave; };

    // Retorna o filho esquerdo
    NoArvBin *getEsq() { return esq; };

    // Retorna o filho direito
    NoArvBin *getDir() { return dir; };

    // Altera a chave do no
    void setChave(int chave) { this->chave = chave; };

    // Altera o filho esquerdo
    void setEsq(NoArvBin *esq) { this->esq = esq; };

    // Altera o filho direito
    void setDir(NoArvBin *dir) { this->dir = dir; };

    // Destrutor
    ~NoArvBin() {
    };

private:
    int chave;
    NoArvBin *esq;
    NoArvBin *dir;
};

/**
 * @brief TAD: Arvore Bin
 *
 */
class ArvBin
{
private:
    NoArvBin *raiz; // Ponteiro para a raiz da árvore
                    // Retorna a raiz da arvore

    int contarImpares(NoArvBin *no); // Função auxiliar recursiva

    int contarPares(NoArvBin *no);

    int somaValoresNo(NoArvBin *no, int acumulador); 

    float mediaNos(NoArvBin *no, int soma, int acumulador);

    int contarNos(NoArvBin *no, int acumulador);

    float mediaNosPares(NoArvBin *no, int soma);

    int maiorNo(NoArvBin *no, int auxVal);

    int menorNo(NoArvBin *no, int auxVal);

    int maioresQueVal(NoArvBin *no, int val);

public:
    ArvBin();
    ~ArvBin();

    NoArvBin *getRaiz();

    // Modifica a raiz da arvore
    void setRaiz(NoArvBin *raiz);

    int impares(); // Função pública

    int pares();

    int soma();

    float media(int somaNos);

    int contar();

    float mediaPares(int somaNos);

    int maior();

    int menor();

    int maiores(int val);
};

#endif /* ARVBIN_H__ */