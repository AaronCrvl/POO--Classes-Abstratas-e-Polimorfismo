#include <iostream>
#ifndef PESSOA_H
#define PESSOA_H
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>  
using namespace std;

class Pessoa
{
    private:
        string Nome;
        int Idade;   

    public:
        Pessoa(string stNome="Indefinido", int itIdade=0) {
            this->setNome(stNome);
            this->setIdade(itIdade);
        }

        string getNome() {
            return this->Nome;
        }
        
        int getIdade() {
            return this->Idade;
        }

        void setNome(string stNome) {
            this->Nome = stNome;
        }

        void setIdade(int itIdade) {
            this->Idade = itIdade;
        }
};

class Amigo: public Pessoa {
    private:
        string DataAniversario;
    public:
        Amigo(string stNome="Indefinido", int itIdade=0, string stDataAniversario="Indefinido"):Pessoa(stNome, itIdade) {
            this->setDataAniversario(stDataAniversario);
        }
        
        string getDataAniversario() {
            return this->DataAniversario;
        }

        void setDataAniversario(string stDataAniversario) {
            this->DataAniversario = stDataAniversario;
        }
};

class Conhecido: public Pessoa {
    private:
        string Email;
    public:
        string getEmail() {
            return this->Email;
        }

        void setEmail(string stEmail) {
            this->Email = stEmail;
        }

        Conhecido(string stNome="Indefinido", int itIdade=0, string stEmail="Indefinido"):Pessoa(stNome, itIdade) {
            this->setEmail(stEmail);
        }
};

class Agenda{
    private:
        int NumAmigos;
        int NumConhecidos;
        vector <Pessoa> Pessoas;
        vector <pair<int,string>> DetPessoas;
    public:
        Agenda(int itPessoas = 0) {
            int itNumAmigos = 0;
            int itNumConhecidos = 0;
            srand (time(NULL));
            for (int i = 0; i < itPessoas; i++) {
                int ID = rand() % 2 + 1;
                DetPessoas.push_back(make_pair(ID,""));
                if (ID==1) {
                    itNumAmigos++;
                } else {
                    itNumConhecidos++;
                }
            }
            this->setNumAmigos(itNumAmigos);
            this->setNumConhecidos(itNumConhecidos);
        }

        void addInformacoes() {
            int aux = this->getNumAmigos() + this->getNumConhecidos();
            for(int i = 0; i < aux; i++){
                int idade = 0;
                string nome = "";
                cout << endl;
                cout << "Digite o nome:" << endl;
                cin >> nome;
                cout << "Digite a idade:" << endl;
                cin >> idade;
                if (this->DetPessoas[i].first == 1) {
                    string dataaniversario;
                    cout << "Digite a data de aniversario:" << endl;
                    cin >> dataaniversario;
                    Pessoa a(nome,idade);
                    Pessoas.push_back(a);
                    DetPessoas[i].second = dataaniversario;
                } else {
                    string email = "";
                    cout << "Digite o email:" << endl;
                    cin >> email;
                    Pessoa b(nome,idade);
                    Pessoas.push_back(b);
                    DetPessoas[i].second = email;
                }
            }
        }

        void imprimeAniversarios() {
            int aux = this->getNumAmigos() + this->getNumConhecidos();
            for(int i = 0; i < aux; i++){
                if (this->DetPessoas[i].first == 1) {
                    cout << "Nome: " << Pessoas[i].getNome() << " Data Aniversario: " << this->DetPessoas[i].second << endl;
                };
            }
        }

        void imprimeEmail() {
            int aux = this->getNumAmigos() + this->getNumConhecidos();
            for(int i = 0; i < aux; i++){
                if (this->DetPessoas[i].first == 2) {
                    cout << "Nome: " << Pessoas[i].getNome() << " Email: " << this->DetPessoas[i].second << endl;
                };
            }
        }

        int getNumAmigos() {
            return this->NumAmigos;
        }

        void setNumAmigos(int itNumAmigos){
            this->NumAmigos = itNumAmigos;
        }

        int getNumConhecidos() {
            return this->NumConhecidos;
        }

        void setNumConhecidos(int itNumConhecidos){
            this->NumConhecidos = itNumConhecidos;
        }
};
#endif
//!_PESSOA !_CONHECIDO !_AMIGO !_AGENDA