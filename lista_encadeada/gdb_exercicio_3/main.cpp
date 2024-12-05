#include <iostream>
using namespace std;

#include "ListaSEncad.h"


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
        cout << "No " << i+1 <<": "; 
        cin >> no;
        lista.InsereOrdenado(no);
    }
    

    // Imprime a lista original
    lista.Imprime();
    

    return 0;
    
}