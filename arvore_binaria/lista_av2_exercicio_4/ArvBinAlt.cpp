#include "ArvBinAlt.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Implementação do Node
ArvBinAlt::Node::Node(int v, ArvBinAlt* e, ArvBinAlt* d) 
    : valor(v), esq(e), dir(d) {
    altura = 1 + max(
        (e ? e->raiz->altura : 0),
        (d ? d->raiz->altura : 0)
    );
}

// Construtor padrão
ArvBinAlt::ArvBinAlt() : raiz(nullptr) {}

// Construtor completo
ArvBinAlt::ArvBinAlt(int val, ArvBinAlt* sae, ArvBinAlt* sad) {
    cria(val, sae, sad);
}

// Função principal de criação
void ArvBinAlt::cria(int val, ArvBinAlt* sae, ArvBinAlt* sad) {
    raiz = new Node(val, sae, sad);
}

// Função auxiliar para cálculo de altura
int ArvBinAlt::calcularAltura(Node* no) {
    if(!no) return 0;
    return 1 + max(
        (no->esq ? no->esq->raiz->altura : 0),
        (no->dir ? no->dir->raiz->altura : 0)
    );
}

// Função para impressão (testes)
void ArvBinAlt::imprime() {
    if(raiz) {
        cout << "Valor: " << raiz->valor 
             << " Altura: " << raiz->altura << endl;
        if(raiz->esq) raiz->esq->imprime();
        if(raiz->dir) raiz->dir->imprime();
    }
}