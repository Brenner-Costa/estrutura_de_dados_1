#include <iostream>
using namespace std;

#include "ListaSEncad.h"


int main()
{
    
    ListaSEncad lista;
    
    int n_nodes;
    int no, sucessor;
    // le numero de nós para inserção
    cout << "Entre com numero de nos: " ;
    cin >> n_nodes;
    
    for(int i = 0; i < n_nodes; i++)
    {
        cout << "No " << i+1 <<": "; 
        cin >> no;
        lista.Insere(no);
    }
    
    // le node e sucessor
    cout << "Entre o com no e o valor a ser inserido: ";
    cin >> no >> sucessor;
    
    cout << endl;
    // Imprime a lista original
    cout << "lista original: " << endl;
    lista.Imprime();
    cout << endl;
    // insere o sucessor de um nó 
    lista.InsereApos(no,sucessor, n_nodes);
    
    // imprime a lista apos insercao
    cout << "lista após insercao: " << endl;
    lista.Imprime();
    
    return 0;
    
}