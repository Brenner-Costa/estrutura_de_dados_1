#ifndef NOABB_H
#define NOABB_H

// Implemenaca do no da arvore binaria de busca
class ABB;
class NoABB {
    friend class ABB;
    public:
        NoABB(int chave);
        ~NoABB();
        int getChave();
        NoABB *getEsq();
        NoABB *getDir();
        void setChave(int chave);
        void setEsq(NoABB *esq);
        void setDir(NoABB *dir);

    private:
        int chave;
        NoABB *esq;
        NoABB *dir;

};

#endif
