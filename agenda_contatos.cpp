#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;

const int TAM = 11;

typedef struct {
    string nome;
    string celular;
    string cidade;
    string email;
    bool valido;
} pessoa;

int main() {
    pessoa agenda[TAM];
    int qtde = 0; // variável para rastrear a quantidade de contatos lidos do arquivo
    int i;
    string entrada;
    int acao;

    ifstream arquivo("/home/carlos/vs code/trabalho de contatos/contatos.txt");
    if (!arquivo.is_open()) {
        cout << "erro: arquivo nao existe" << endl;
        return 1;
    }

    for (i = 0; i < TAM && arquivo >> entrada && entrada != "fim"; i++) {
        agenda[i].nome = entrada;
        arquivo >> agenda[i].celular;
        arquivo >> agenda[i].cidade;
        arquivo >> agenda[i].email;
        agenda[i].valido = true;
        qtde++; // Incrementa o contador de contatos lidos
    }

    arquivo.close(); // Fecha o arquivo depois de ler

    do {
        cout << "      MENU   " << endl;
        cout << "| [1] incluir novo contato: |" << endl;
        cout << "| [2] excluir contato:     |" << endl;
        cout << "| [3] alterar contato:     |" << endl;
        cout << "| [4] buscar contato:      |" << endl;
        cout << "| [0] sair                 |" << endl;
        cout << "  ";
        cin >> acao;

        switch (acao) {
            case 1:
                if (qtde < TAM) { // Verifica se ainda há espaço na agenda
                    cout << "escreva nome: " << endl;
                    cin >> agenda[qtde].nome;
                    cout << "escreva celular: " << endl;
                    cin >> agenda[qtde].celular;
                    cout << "escreva cidade: " << endl;
                    cin >> agenda[qtde].cidade;
                    cout << "escreva email:" << endl;
                    cin >> agenda[qtde].email;
                    qtde++; // Incrementa a quantidade de contatos
                } else {
                    cout << "Agenda cheia. Não é possível adicionar mais contatos." << endl;
                }
                break;
        }
    } while (acao != 0);

    
    
    
    
    
    
    
    
    
    
    
    
    // adiciona numeros 
    ofstream arquivoSaida("contatos.txt");
    for (int j = 0; j < qtde; j++) { // Escreve apenas os contatos lidos do arquivo
        arquivoSaida << agenda[j].nome << " " << agenda[j].celular << " " << agenda[j].cidade << " " << agenda[j].email << "\n";
    }
    arquivoSaida.close();

 return 0;
}