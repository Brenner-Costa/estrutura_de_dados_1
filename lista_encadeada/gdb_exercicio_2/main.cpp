#include <iostream>
#include "ListaSEncad.h"

using namespace std;

int main()
{

    ListaSEncad lista;
    
    int n_nodes;
    int no;
    // le numero de nós para inserção
    cout << "Entre com numero de nos: " ;
    cin >> n_nodes;
    
    for(int i = 0; i < n_nodes; i++)
    {
        // cout << "No " << i+1 <<": "; 
        cin >> no;
        lista.Insere(no);
    }
    
    // le node e sucessor
    cout << "Entre o com valor a ser removido: ";
    cin >> no;
    
    // Imprime a lista original
    lista.Imprime();
    
    // insere o sucessor de um nó 
    lista.RemoveTodos(no);
    
    // imprime a lista apos insercao
    lista.Imprime();
    
    return 0;
    
}
