#ifndef NOENCAD_H
#define NOENCAD_H

class No {
public:
    No();               // Construtor
    ~No();              // Destrutor
    int getInfo();      // Retorna o valor armazenado no nó
    No* getProx();      // Retorna o ponteiro para o próximo nó
    void setInfo(int val); // Define o valor armazenado no nó
    void setProx(No* p);   // Define o ponteiro para o próximo nó

private:
    int info;   // Informação armazenada no nó
    No* prox;   // Ponteiro para o próximo nó
};

#endif
