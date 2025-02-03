#ifndef ARVBIN_H__
#define ARVBIN_H__

#include <iostream>
using namespace std;

class Arvbin;

class NoArvBin {
    friend class ArvBin;

    public:
        // Construtores
        // Construtor padrao
        NoArvBin(int chave): chave(chave), esq(nullptr), dir(nullptr) {}

        // Cria um no com chave e ponteiros para os filhos
        NoArvBin(int chave, NoArvBin *esq, NoArvBin *dir): chave(chave), esq(esq), dir(dir) {};

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
        void setEsq(NoArvBin *esq){ this->esq = esq; };

        // Altera o filho direito
        void setDir(NoArvBin *dir) { this->dir = dir; };

        // Destrutor
        ~NoArvBin(){
        };

    private:
        int     chave;  
        NoArvBin *esq;
        NoArvBin *dir;

};

/**
 * @brief TAD: Arvore Bin
 * 
 */
class ArvBin {

    public:
        // Construtor
        ArvBin();

        // Destrutor
        ~ArvBin();

        // Retorna a raiz da arvore
        NoArvBin *getRaiz();

        // Modifica a raiz da arvore
        void setRaiz(NoArvBin *raiz);

        // Imprime a arvore em pre-ordem
        void imprimePreOrdem();

        // Imprime a arvore
        void imprimeArvore();

        void conta(int val);

    private:

        // Atributos privados
        NoArvBin *raiz;


        // Metodos privados auxiliares

        // Destroi a arvore
        void destruir(NoArvBin *raiz);

        // Imprime a arvore em pre-ordem
        void imprimePreOrdem(NoArvBin *raiz);

        // Imprime a arvore
        void imprimeArvore(NoArvBin *raiz, string prefixo, bool esquerda);

        void contagens(NoArvBin *no, int val, int &contPares, int &contNaoNegativos);

};

#endif /* ARVBIN_H__ */
