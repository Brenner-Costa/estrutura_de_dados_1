#include <iostream>
using namespace std;
#include "PilhaEncad.h"


// Implemente aqui
int FatorialIterativo(int n)
{
    //Se eu entrar com um valor 10, vou precisar empilhar os outros 9 números anteriores a ele
    //Lembrando que uma pilha insere e remove através do topo.
    //Então vai precisar começar a inserção a partir do 1 -> Criar um laço para ir adicionando valores na pilha até o valor
    // multiplicar o valor que foi adicionado na pilha com a variável acumuladora.

    PilhaEncad pilha = PilhaEncad();
     
    int acumuladora = 1;
    for (int i = 1; i <= n; i++)
    {
        //Empilhar de i até n
        pilha.empilha(i);
        acumuladora = acumuladora*pilha.getTopo();
    }
    
    return acumuladora;
}


int FatorialRecursivo(int n)
{
    if( n < 0 )
        return -1;
    if(n == 0)
        return 1;
    else
        return n*FatorialRecursivo(n-1);
}
 
int main()
{
    int n;
    cout << "Entre com o valor de N: "; 
    cin >> n;

    cout << endl;
    cout << "Valor Obtido: "   << FatorialIterativo(n) << endl;
    cout << "Valor Esperado: " << FatorialRecursivo(n) << endl;
    return 0;
    
}
 


