#ifndef LISTACONT_H
#define LISTACONT_H

class ListaCont {
private:
  int *vet;
  int quantNos;
  int maxTam;
public:
    // Construtor
    ListaCont(int capacidadeMax);

    // Destrutor
    ~ListaCont();

    // Adiciona um elemento ao final da lista
    bool adiciona(int valor);

    // Troca dois elementos na lista
    bool troca(int posicao1, int posicao2);

    // Exibe os elementos da lista
    void imprime() const;
};

#endif
