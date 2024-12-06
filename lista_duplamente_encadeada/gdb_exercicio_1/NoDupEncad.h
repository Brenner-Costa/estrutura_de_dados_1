#ifndef NODUPENCAD_H__
#define NODUPENCAD_H__

class NoDupEncad
{
    public:
        NoDupEncad(int val);   // construtor
        int  ObterValor();        // retorna o valor armazenado no nó
        void AlterarValor(int val); // altera o valor armazenado no nó
        NoDupEncad* ObterProximo(); // retorna o ponteiro para o próximo nó
        void AlterarProximo(NoDupEncad *p); // altera o ponteiro para o próximo nó
        NoDupEncad* ObterAnterior(); // retorna o ponteiro para o nó anterior
        void AlterarAnterior(NoDupEncad *p); // altera o ponteiro para o nó anterior

    private:
        int        valor;     // valor armazenado no nó
        NoDupEncad *prox;    // ponteiro para o próximo nó
        NoDupEncad *ant;    // ponteiro para o nó anterior
       
};

#endif /* NODUPENCAD_H__ */