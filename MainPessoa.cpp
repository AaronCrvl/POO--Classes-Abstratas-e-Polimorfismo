#include <iostream>
#include "Pessoa.hpp"

using namespace std;

int main(){
    int itPessoas = 0;
    cout << "Digite a quantidade de pessoas: " << endl;
    cin >> itPessoas;
    
    Agenda a(itPessoas);
    cout << endl;
    cout << "Número de amigos: " << a.getNumAmigos() << endl;
    cout << "Número de conhecidos: " << a.getNumConhecidos() << endl;
    a.addInformacoes();
    a.imprimeAniversarios();
    a.imprimeEmail();


    return 0;
}