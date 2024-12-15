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

    // aumenta a capacidade da lista
    bool aumentaCapacidade(int novoMax);

    // Exibe os elementos da lista
    void imprime() const;
};

#endif
