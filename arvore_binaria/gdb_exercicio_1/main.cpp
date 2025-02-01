#include <iostream>
using namespace std;

#include "ArvBin.h"

// Para Teste 1
void CriaArvore(ArvBin &arv){
    // Cria os nós da árvore e suas relações conforme a figura

    NoArvBin *no7 = new NoArvBin(7, nullptr, nullptr);
    NoArvBin *no99 = new NoArvBin(99, nullptr, nullptr);
    NoArvBin *no5 = new NoArvBin(5, nullptr, nullptr);
    NoArvBin *no14 = new NoArvBin(14, no5, nullptr);
    NoArvBin *no13 = new NoArvBin(13, nullptr, nullptr);
    NoArvBin *no88 = new NoArvBin(88, nullptr, nullptr);

    NoArvBin *no11 = new NoArvBin(11, no7, no99);
    NoArvBin *no2 = new NoArvBin(2, nullptr, no14);
    NoArvBin *no15 = new NoArvBin(15, nullptr, nullptr);
    NoArvBin *no20 = new NoArvBin(20, no13, no88);
    NoArvBin *no90 = new NoArvBin(90, no11, no2);
    NoArvBin *no27 = new NoArvBin(27, no15, no20);

    NoArvBin *raiz = new NoArvBin(76, no90, no27);

    arv.setRaiz(raiz);
    // Chame a função para modificar a raiz da árvore
    // NoArvBin *raiz = new NoArvBin(/* chave e filhos */);
    // arv.setRaiz(raiz);
}

void CalculaNumeroFolhas(NoArvBin *no, int &num_folhas){
    // Implemente aqui a calculo do número de nos folhas!

    // Se o nó não possui filhos, ou seja, esq = null e dir = null -> ELE É UMA FOLHA
    // Vai fazendo recursão até encontrar o NÓ QUE TEM CHAVE NULL -> Depois de encontrado, ele vai retornar para quem chamou e vai para a direita.
    if(no == nullptr) {
        return;
    }
    //Fazer a verificação do no null para retornar para o pai

    if(no->getDir() == nullptr && no->getEsq() == nullptr) {
        num_folhas++;
        //cout << "Folha -> " << no->getChave() << " encontrado!" << endl;
    } else {
        CalculaNumeroFolhas(no->getEsq(), num_folhas); //somente depois do retorno para quem chamou que vai para o nó da direita.
        CalculaNumeroFolhas(no->getDir(), num_folhas);
    }
}


void Teste1(ArvBin &arv){
    
    cout <<"--------------------------------------------" << endl;
    cout << "Teste 1: Criação da árvore" << endl;
    cout <<"--------------------------------------------" << endl;

    CriaArvore(arv);
    cout <<"Pre-ordem: " << endl;
    arv.imprimePreOrdem();
    cout << endl;
    cout << "Arvore: " << endl;
    arv.imprimeArvore();

    // Atenção: não é necessário liberar a memória dos nós, 
    //          pois a árvore é responsável por isso

}

void Teste2(ArvBin &arv){

    cout << endl;
    cout <<"--------------------------------------------" << endl;
    cout << "Teste 2: Busca de elementos" << endl;
    cout <<"--------------------------------------------" << endl;
    // Busque os elementos 5 e 10 na árvore
    NoArvBin *no_busca = arv.buscar(5);
    if(no_busca != nullptr){
         cout << "No encontrado: " << no_busca->getChave() << endl;
    }
    else{
         cout << "Chave 5 não encontrado" << endl;
    }

    no_busca = arv.buscar(11);
    if(no_busca != nullptr){
         cout << "No encontrado: " << no_busca->getChave() << endl;
    }
    else{
         cout << "Chave 10 não encontrado" << endl;
    }
}

void Teste3(ArvBin &arv){

    cout << endl;
    cout <<"--------------------------------------------" << endl;
    cout << "Teste 3: Calculo da altura da árvore" << endl;
    cout <<"--------------------------------------------" << endl;
    // Calcule a altura da árvore
    cout << "Altura da árvore: " << arv.altura() << endl;
}

void Teste4(ArvBin &arv){
    // calcule o número de folhas da árvore
    cout << endl;
    cout <<"--------------------------------------------" << endl;
    cout << "Teste 4: Calculo número de folhas " << endl;
    cout <<"--------------------------------------------" << endl;
    int num_folhas = 0;
    CalculaNumeroFolhas(arv.getRaiz(), num_folhas);
    cout << "Numero de folhas: " << num_folhas << endl;
}


int main()
{
    // Cria uma árvore binária
    ArvBin arv;

    // Executa os testes
    Teste1(arv);
    Teste2(arv);
    Teste3(arv);
    Teste4(arv);

    return 0;
}