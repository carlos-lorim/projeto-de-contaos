#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;

const int TAM = 100;

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
    int i, j;
    string entrada;
    int acao;
    string exc, bsc;

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
        cout << "| [3] buscar contato:     |" << endl;
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
                    agenda[i].valido = true;
                    qtde++; // Incrementa a quantidade de contatos
                } else {
                    cout << "Agenda cheia. Não é possível adicionar mais contatos." << endl;
                }
                break;


            case 2: // o nome deve ser identico ao do txt 
                cout << "qual contato deseja excluir ? ";
                cin >> exc;
                for (i = 0; i < qtde; i++) {
                    if (agenda[i].nome == exc) {
                        agenda[i].valido = false;


                        // Reorganiza os contatos válidos para evitar lacunas
                        for (j = i; j < qtde - 1; j++) {
                            agenda[j] = agenda[j + 1];
                        }
                        qtde--; // Decrementa a quantidade de contatos
                        break; // Sai do loop após encontrar o contato
                    }
                }
                if (i == qtde) {
                    cout << "Contato não encontrado." << endl;
                }
                break;


            case 3:
                cout << "qual contato deseja buscar? ";
                cin >> bsc;
                for (i = 0; i < qtde; i++) {
                    if (agenda[i].nome == bsc) { // Verifica se o nome está presente no arquivo
                        cout << "Nome: " << agenda[i].nome << endl;
                        cout << "Celular: " << agenda[i].celular << endl;
                        cout << "Cidade: " << agenda[i].cidade << endl;
                        cout << "Email: " << agenda[i].email << endl;
                        break; // Sai do loop após encontrar o contato
                    }
                }
                if (i == qtde) {
                    cout << "Contato não encontrado." << endl;
                }
                break;

            default:
                if (acao != 0) { // Verifica se a ação não é zero
                    cout << "Opção inválida. Por favor, escolha uma opção válida.\n";
                }
                break;


        }

    } while (acao != 0);



    // adiciona numeros 
    // ATENCAO  !!! os comandos so sao efetuados apos pressionar 0 
    ofstream arquivoSaida("cont.txt");
    for (int j = 0; j < qtde; j++) { // Escreve apenas os contatos lidos do arquivo
        arquivoSaida << agenda[j].nome << " " << agenda[j].celular << " " << agenda[j].cidade << " " << agenda[j].email << endl;
    }
    arquivoSaida.close();

    return 0;
}