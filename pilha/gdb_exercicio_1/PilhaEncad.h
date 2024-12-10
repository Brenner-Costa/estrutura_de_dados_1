#ifndef PILHAENCAD_H_
#define PILHAENCAD_H_

// No da Pilha
class No
{
  public:
    No()                  { };
    ~No()                 { };
    void setInfo(int val) { info = val; };
    void setProx(No* p)   { prox = p; };
    int getInfo()         { return info; };
    No* getProx()         { return prox; };
  private:
    int info;
    No *prox;
};


// Pilha Encadeada
class PilhaEncad
{
  public:
    PilhaEncad() { topo = nullptr; };
    int getTopo();
    void empilha(int val);
    int desempilha();
    bool vazia();
  private:
    No *topo;
};

#endif // PILHAENCAD_H