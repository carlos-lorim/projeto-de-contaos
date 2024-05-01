# 1 Agenda de Amigos em C/C++

Este é um projeto em C/C++ desenvolvido para gerenciar uma agenda de amigos. Cada amigo na agenda possui os seguintes campos:

- Nome
- Celular
- Cidade
- Email
- Flag de Validação (indicando se o registro é válido ou não)

## Funcionamento do Projeto

O projeto é inicializado lendo um arquivo de dados que contém os registros dos amigos. Em seguida, o usuário pode realizar as seguintes operações:

- **Busca pelo nome do amigo:** Permite ao usuário pesquisar um amigo na agenda pelo nome.
- **Exclusão de um amigo:** Permite ao usuário excluir um amigo da agenda. Isso é feito atribuindo o valor "Falso" ao campo de flag que indica a validade do registro.
- **Inserção de um novo amigo:** Permite ao usuário adicionar um novo amigo à agenda.

Ao final das operações, o programa reescreve o arquivo inicial com as alterações feitas na agenda.

## Compilação e Execução

Para compilar e executar o projeto, siga os seguintes passos:

1. Certifique-se de ter um compilador C/C++ instalado em seu sistema.
2. Baixe os arquivos do projeto em seu computador.
3. Abra um terminal na pasta onde os arquivos do projeto estão localizados.
4. Compile o código-fonte usando o comando de compilação apropriado para seu sistema. Por exemplo, no Linux, você pode usar o comando `g++ -o agenda agenda.cpp`.
5. Após compilar com sucesso, execute o programa digitando o nome do executável gerado. Por exemplo, no Linux, você pode executar o programa digitando `./agenda`.

## Contribuições

Contribuições são bem-vindas! Se você identificar algum problema ou tiver sugestões para melhorias, sinta-se à vontade para abrir uma issue ou enviar um pull request neste repositório.

## Autor

Este projeto foi desenvolvido por [Seu Nome/Aplicativo](https://github.com/seu-usuario).


