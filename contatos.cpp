// projeto de agenda de contatos 

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

/*
 * 
 */
const int TAM = 11;

typedef struct {
    string nome;
    string celular;
    string cidade;
    string email;
} pessoa; // declara tipo 

int main() {
    pessoa agenda[TAM];
    int qtde = 0;
    int i;
    string entrada;
    
    ifstream arquivo("contatos.txt");
    if (!arquivo.is_open()) {
        std::cout << "erro: arquivo nao existe" << std::endl;
        return 1;
    }
   
    arquivo >> entrada;

   
    for (i = 0; entrada != "fim" && i < TAM; i++) {
        agenda[i].nome = entrada;
        arquivo >> agenda[i].celular;
        arquivo >> agenda[i].cidade;
        arquivo >> agenda[i].email;
        
        arquivo >> entrada;
    }
  
    cout << agenda[2];











    return 0;
}
