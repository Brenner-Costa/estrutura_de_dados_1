#include "ArvBinAlt.h"
#include <iostream>

using namespace std;

int main() {
    // Cria folhas
    ArvBinAlt* folha1 = new ArvBinAlt(5);
    ArvBinAlt* folha2 = new ArvBinAlt(15);
    
    // Cria subárvores
    ArvBinAlt* sae = new ArvBinAlt(10, folha1, nullptr);
    ArvBinAlt* sad = new ArvBinAlt(20, nullptr, folha2);
    
    // Cria árvore principal
    ArvBinAlt arvore;
    arvore.cria(30, sae, sad);
    
    // Teste de impressão
    cout << "Árvore resultante:" << endl;
    arvore.imprime();

    return 0;
}