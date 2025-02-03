#ifndef ARVBINALT_H
#define ARVBINALT_H

class ArvBinAlt {
private:
    struct Node {
        int valor;
        int altura;
        ArvBinAlt* esq;
        ArvBinAlt* dir;
        Node(int v, ArvBinAlt* e = nullptr, ArvBinAlt* d = nullptr);
    };

    Node* raiz;

    int calcularAltura(Node* no);

public:
    ArvBinAlt();
    ArvBinAlt(int val, ArvBinAlt* sae = nullptr, ArvBinAlt* sad = nullptr);
    void cria(int val, ArvBinAlt* sae, ArvBinAlt* sad);
    void imprime(); // Para testes
};

#endif