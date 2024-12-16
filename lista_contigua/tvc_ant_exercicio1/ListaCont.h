#ifndef LISTACONT_H
#define LISTACONT_H

class ListaCont {
private:
    int *vet;      // Vetor que armazena os elementos
    int max;       // Capacidade máxima da lista
    int n;         // Quantidade atual de elementos

public:
    // Construtor e Destrutor
    ListaCont(int capacidade);
    ~ListaCont();

    // Métodos da lista contígua
    void insereFinal(int valor);
    void exibir();
    ListaCont* copiar(int valor);
};

#endif // LISTACONT_H
