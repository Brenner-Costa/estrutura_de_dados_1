#include <iostream>
#include <string>
using namespace std;

#include "PilhaEncad.h"

// implemente aqui
int ValorExpressao(string posfixa)
{
    // Percorrer a string
    // Encontrou um numero? empilhar na pilha
    // Encontrou um operador? Desempilhar os 2 ultimos numeros da pilha e fazer a operacai com o operador
    // retorna o valor, empilha e usa

    PilhaEncad pilha;

    for (int i = 0; i < posfixa.length(); i++)
    {
        char valStr = posfixa[i];

        if (isdigit(valStr))
        {
            pilha.empilha(valStr - '0'); //conversao para numero
        }
        else
        {
            // Desempilhar os dois ultimos topos

            int expressao1 = pilha.desempilha();
            int expressao2 = pilha.desempilha();
            int result;

            switch (valStr)
            {
            case '+':
                result = expressao1 + expressao2;
                // cout << "Soma: " << result << endl;
                pilha.empilha(result);
                break;
            case '-':
                result = expressao1 - expressao2;
                // cout << "Subtração: " << result << endl;
                pilha.empilha(result);
                break;
            case '*':
                result = expressao1 * expressao2;
                // cout << "Multiplicação: " << result << endl;
                pilha.empilha(result);
                break;
            case '/':
                // if(expressao1 == 0 || expressao2 == 0) {
                //     cout << "Divisão por 0 não é permitido!" << endl;
                //     break;
                // }
                result = expressao1 / expressao2;
                // cout << "Divisão: " << result << endl;
                pilha.empilha(result);
                break;
            }
        }
    }

    return pilha.desempilha();
}

int main()
{

    string posfixa;
    // cout << "Entre com expressao valida: " ;
    getline(cin, posfixa);
    cout << "Valor: " << ValorExpressao(posfixa) << endl;
    return 0;
}
