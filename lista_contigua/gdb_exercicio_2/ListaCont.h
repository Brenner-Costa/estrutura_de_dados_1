#ifndef LISTACONT_H__
#define LISTACONT_H__

#include <iostream>
using namespace std;

/**
 * @brief Implementação de uma lista de inteiros com alocação contígua.
 * 
 */
class ListaCont
{
    public:
        /**
         * @brief Construtor da classe ListaCont.
         * 
         * @param max  Tamanho máximo da lista.
         */
        ListaCont(int max);

        /**
         * @brief Destrutor da classe ListaCont.
         * 
         */
        ~ListaCont();

        /**
         * @brief Insere um elemento no final da lista.
         * 
         * @return 
         */
        void insere(int val);
        
        /**
         * @brief Insere um elemento no final da lista. 
         *        Se houver algum elemento na lista com o mesmo valor,
         *        o elemento de entrada não eh inserido.
         * 
         * @return 
         */
        void insere_unico(int val);

        /**
         * @brief Insere um elemento no início da lista.
         * 
         * @param val  Valor a ser inserido.
         */
        void insereInicio(int val);

        /**
         * @brief Insere um elemento na posição k da lista.
         * 
         * @param val  Valor a ser inserido.
         */
        void inserePosicao(int k, int val);

        /**
         * @brief Obtem o valor armazenado na posição k da lista.
         * 
         * @return int 
         */
        int  obter(int k);

        /**
         * @brief Altera o valor armazenado na posição k da lista.
         * 
         * @param k    Posição do elemento a ser alterado.
         * @param val  Novo valor a ser armazenado.
         */
        void altera(int k, int val);

        /**
         * @brief Retorna o número de elementos na lista.
         * 
         * @return int 
         */
        void removeUltimo();

        /**
         * @brief Remove o primeiro elemento da lista.
         * 
         */
        void removePrimeiro();

        /**
         * @brief Remove o elemento na posição k da lista.
         * 
         * @param k  Posição do elemento a ser removido.
         */
        void removePosicao(int k);

        /**
         * @brief Retorna o número de elementos na lista.
         * 
         * @return int 
         */
        int  numElem();

        /* 
          DICA:
            Em C++, é possível sobrecarregar o operador de inserção (<<) para permitir 
            que objetos de uma classe sejam impressos diretamente usando o std::cout. 
            Em uma implementação de lista, essa técnica é útil para facilitar a exibição 
            dos elementos da lista de forma intuitiva e elegante. Ao sobrecarregar esse operador, 
            você define como a lista será exibida quando chamada pelo cout, sem precisar criar uma 
            função específica de exibição sempre que quiser visualizar o conteúdo.
          A baixo está a sinatxe da sobrecarga do operador cout:
        */
        friend ostream& operator<<(ostream& os, const ListaCont& lista) {
        os << "[";
        for (int i = 0; i < lista._n; i++) {
            os << lista._vet[i];
            if (i < lista._n - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }
    
    /**
     *    Une a lista com a lista l incluindo apenas os elementos 
     *    distintos. A lista resultante deve conter apenas elementos distintos.
     *    O método de deve ser capaz de aumentar a capacidade da lista caso seja necessário.
     */
    void concatena(ListaCont &l);

    private:
        int  _max;   // tamanho máximo da lista
        int  _n;     // número de elementos na lista
        int *_vet;   // vetor que armazena os elementos

};


#endif /* LISTACONT_H__ */