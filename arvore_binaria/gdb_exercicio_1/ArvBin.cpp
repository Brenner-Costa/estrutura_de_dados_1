#include "ArvBin.h"

// Busca uma chave na árvore
NoArvBin *ArvBin::buscar(int chave)
{
    return buscar(raiz, chave);
}

// Função auxiliar para buscar uma chave na árvore
// IMPLEMENTE AQUI
NoArvBin *ArvBin::buscar(NoArvBin *no, int chave)
{
    /*
        - Percorrer a subárvore esquerda e depois a direita, partindo da raiz.
        - Semelhante ao código recursivo para encontrar a quantidade de nós folha.

        - Se a chave do nó atual for igual ao nó que estou buscando, retornar o nó encontrado.
        - Se a chave do nó for null -> Retornar o próprio no null

    */

    if (no == nullptr)
    {
        return nullptr;
    }

    if(no->getChave() == chave) {
        return no;
    }

    NoArvBin *esq = buscar(no->getEsq(), chave);

    //Basicamente, iremos ir subindo os valores. O null vai subindo e se algum valor for diferente de null, VAI SER O NO DESEJADO.
    //Observe o caso base, existem 2 retornos -> Ou null ou a chave
    //Em baixo apenas iremos fazer a verificação de qual retorno foi usado -> o null ou a chave (ISSO NA SUBARVORE ESQUERDA, NA DIREITA ISSO NÃO VAI SER NECESSÁRIO)
    //O valor que será retornado para main é o que foi subindo até chegar no 76 e esse valor será retornado para a MAIN.
    
    if(esq != nullptr) {
        return esq;
    }

    return buscar(no->getDir(), chave);

}

// Retorna a altura da árvore
int ArvBin::altura()
{
    return altura(raiz);
}

// Função auxiliar para calcular a altura da árvore
// IMPLEMENTE AQUI
int ArvBin::altura(NoArvBin *no)
{
    /*
        - O caso base serve para quando encontrarmos um nó vazio, ou seja, com um NULL. (Nós que ficam após as folhas ou nós com 1 filho só)
        - A recursão sempre se inicia pela esquerda, empilhando diversas chamadas recursivas até que exista um retorno para que chamou.
        - Após o nó a esquerda, vamos para a direita e o percurso será o mesmo.

        - No final, retornaremos para quem chamou o nó pai (dos anteriores nós da esquerda e direita) um somátorio.
        - Nesse somatório iremos escolher entre o valor do nó a direita ou o nó a esquerda.
        - Escolhido o nó com o maior valor, iremos somar 1 e retornar para quem chamou.
    */

    if (no == nullptr)
    {
        return -1;
    }

    int alturaRetornoEsq = altura(no->getEsq());
    int alturaRetornoDir = altura(no->getDir());

    return (alturaRetornoEsq > alturaRetornoDir ? alturaRetornoEsq : alturaRetornoDir) + 1;
}

// Construtor
ArvBin::ArvBin()
{
    raiz = nullptr;
}

// Destrutor
ArvBin::~ArvBin()
{
    destruir(raiz);
}

// Função que destrói a árvore enraizada em um nó
void ArvBin::destruir(NoArvBin *no)
{
    if (no != nullptr)
    {
        destruir(no->getEsq());
        destruir(no->getDir());
        delete no;
        no = nullptr;
    }
}

// Retorna a raiz da árvore
NoArvBin *ArvBin::getRaiz()
{
    return raiz;
}

// Modifica a raiz da arvore somente se a raiz atual for nula
void ArvBin::setRaiz(NoArvBin *raiz)
{
    if (this->raiz == nullptr)
    {
        this->raiz = raiz;
        return;
    }
    cout << "A raiz da arvore ja foi definida" << endl;
}

void ArvBin::imprimePreOrdem(NoArvBin *no)
{
    if (no != nullptr)
    {
        cout << no->getChave() << " ";
        imprimePreOrdem(no->getEsq());
        imprimePreOrdem(no->getDir());
    }
}

void ArvBin::imprimePreOrdem()
{
    imprimePreOrdem(raiz);
    cout << endl;
}

void ArvBin::imprimeArvore(NoArvBin *no, string prefixo, bool esquerda)
{
    if (no != nullptr)
    {
        cout << prefixo;
        cout << (esquerda ? "├──" : "└──");
        cout << no->getChave() << endl;
        imprimeArvore(no->getEsq(), prefixo + (esquerda ? "│   " : "    "), true);
        imprimeArvore(no->getDir(), prefixo + (esquerda ? "│   " : "    "), false);
    }
    else
    {
        cout << prefixo;
        cout << (esquerda ? "├──" : "└──");
        cout << "[-]" << endl;
    }
}

void ArvBin::imprimeArvore()
{
    imprimeArvore(raiz, "", false);
}
