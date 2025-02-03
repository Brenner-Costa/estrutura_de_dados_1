#include <iostream>
#include "ABB.h"

int main() {
    ABB arvore;
    
    // Inserção de valores de teste
    arvore.insere(10);
    arvore.insere(5);
    arvore.insere(15);
    arvore.insere(3);
    arvore.insere(7);
    arvore.insere(20);
    
    // Teste da função
    int resultado = arvore.maiorDiferenca(3, 15, 10);
    std::cout << "Maior diferença: " << resultado << std::endl;
    
    return 0;
}