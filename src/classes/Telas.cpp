//
// Created by Gabriel on 19/04/2022.
//

#include "../headers/Telas.h"
#include "../headers/Data.h"
#include <tuple>

/*
Função Que Exibe Um menuPrincipal De Funcionalidades e Opções do Programa.
*/
void Telas::menuPrincipal(string login){
    cout<< "\n--------------------------------------------------------------\n" << endl;
    cout << "Este eh o Bill Division, feito Para descomplicar suas comandas!\n" << endl;
    cout << "Ola, " << login << endl;
    cout << "\n--------------menuPrincipal De Opcoes-------------------\n" << endl;
    cout << "   Digite 1 Para Trocar de Usuario" << endl;
    cout << "   Digite 2 Para Ver Informacoes do Usuario" << endl;
    cout << "   Digite 3 Para adicionar um produto" << endl;
    cout << "   Digite 4 Para Acessar Area do Administrador" << endl;
    cout << "   Digite 5 Para Encerrar O Programa" << endl;
    cout<< "\n-------------------------------------------------------------\n" << endl;
    cout <<"Insira Sua Opcao:" << endl;
}


void Telas::adminFaltado() {
    cout << "\n--------------------------------------------------------------\n" << endl;
    cout << "Nao ha um administrador cadastrado. Deseja cadastrar um?" << endl;
    cout << "1) Sim." << endl;
    cout << "2) Nao." << endl;
    cout << "\n--------------------------------------------------------------\n" << endl;
}


void Telas::cadastrar(string x) {
    cout << "\n--------------------------------------------------------------\n" << endl;
    cout << "Digite " << x << endl;
}


void Telas::login() {
    cout << "\n--------------------------------------------------------------\n" << endl;
    cout << "Digite o login, pressione enter, e depois digite a senha." << endl;
}


void Telas::exibirInformacoes(string nome, string login, string senha, bool p, std::tuple<int, int, int> dataNascimento) {
    cout<< "\n--------------------------------------------------------------\n" << endl;
    cout << "O nome registrado eh: " << nome << endl;
    cout << "O login eh: " << login << endl;
    cout << "A senha eh: " << senha << endl;
    auto [dia, mes, ano] = dataNascimento;
    cout << "A data de nascimento eh: " << dia << "/" << mes << "/" << ano << endl;
    if (p) {
        cout << "Este usuario e um administrador\n" << endl;
    }
    cout << "Digite:" << endl;
    cout << "1) Para alterar alguma informacao." << endl;
    cout << "2) Para Voltar." << endl;
    cout<< "\n--------------------------------------------------------------\n" << endl;
}


void Telas::alterarNome() {
    cout<< "\n--------------------------------------------------------------\n" << endl;
    cout << "Digite o novo nome" << endl;
}

void Telas::alterarSenha() {
    cout<< "\n--------------------------------------------------------------\n" << endl;
    cout << "Digite a nova senha" << endl;
}


void Telas::semPrivilegios() {
    cout<< "\n--------------------------------------------------------------\n" << endl;
    cout << "Voce nao tem os privilegios necessarios para acessar esta area." << endl;
    cout << "Digite qualquer coisa pra voltar";
    cout<< "\n--------------------------------------------------------------\n" << endl;
}


void Telas::areaAdm() {
    cout<< "\n--------------------------------------------------------------\n" << endl;
    cout << "Esta e a area para usuarios administradores. Escolha uma das opcoes:" << endl;
    cout << "1) Exibir todos os usuarios cadastrados" << endl;
    cout << "2) modificar algum usuario (nao implementado)" << endl;
    cout << "3) Criar novo usuario" << endl;
    cout << "4) voltar." << endl;
    cout<< "\n--------------------------------------------------------------\n" << endl;
}


void Telas::loginInvalido() {
    cout<< "\n--------------------------------------------------------------\n" << endl;
    cout << "O login digitado eh invalido. Verifique se ele segue os seguintes parametros:" << endl;
    cout << "- Maximo 12 caracteres\n";
    cout << "- Nao pode ser vazio.\n";
    cout << "- Nao pode ter numeros.\n";
    cout<< "\n--------------------------------------------------------------\n" << endl;
}


void Telas::senhaInvalida() {
    cout<< "\n--------------------------------------------------------------\n" << endl;
    cout << "A senha digitada eh invalida. Verifique se ela segue os seguintes parametros:" << endl;
    cout << "- Maximo 20 caracteres\n";
    cout << "- Minimo de 8 caracteres.\n";
    cout << "- deve possuir letras e no minimo 2 numeros.\n";
    cout<< "\n--------------------------------------------------------------\n" << endl;
}


void Telas::usuarioNaoEncontrado() {
    cout<< "\n--------------------------------------------------------------\n" << endl;
    cout << "O usuario Digitado nao foi encontrado." << endl;
    cout<< "\n--------------------------------------------------------------\n" << endl;
}


void Telas::modoExib() {
    cout<< "\n--------------------------------------------------------------\n" << endl;
    cout << "Selecione o modo de exibicao de usuarios:" << endl;
    cout << "1) Exibir por ordem de criacao" << endl;
    cout << "2) Exibir por ordem alfabetica crescente de login" << endl;
    cout << "3) Exibir por ordem decrescente de data de nascimento" << endl;
    cout<< "\n--------------------------------------------------------------\n" << endl;
}

void Telas::adicionarProdutoNome() {
    cout << "\n--------------------------------------------------------------\n" << endl;
    cout << "Digite o Nome do produto:" << endl;
}

void Telas::adicionarProdutoQuantidade() {
    cout << "\n--------------------------------------------------------------\n" << endl;
    cout << "Digite a quantidade do produto:" << endl;
}

void Telas::adicionarProdutoPreco() {
    cout << "\n--------------------------------------------------------------\n" << endl;
    cout << "Digite o preco do produto:" << endl;
}

void Telas::adicionarProdutoId() {
    cout << "\n--------------------------------------------------------------\n" << endl;
    cout << "Digite o número de identificacao (ID) do produto:" << endl;
}

void Telas::exibirlogins(vector<Usuario*> usuarios) {
    cout << "\n--------------------------------------------------------------" << endl;
    cout << "Usuarios Cadastrados: " << endl;
    for (auto usuario : usuarios) {
        cout << "   " << usuario->getLogin() << endl;
    }
    cout << "\n--------------------------------------------------------------\n" << endl;
}

void Telas::exibirProdutos(string login, vector<Produtos *> produtos) {
    cout << "\n--------------------------------------------------------------" << endl;
    cout << "Produtos do Usuario: " << login << endl;
    for (auto produto : produtos) {
        cout << "   nome: " << produto->getnomeProduto() << endl;
        cout << "   Quantidade: " << produto->getQuantidade() << endl;
        cout << "   Preco por unidade: " << produto->getPreco() << endl;
        cout << "   Preço total: " << produto->getPreco() * produto->getQuantidade() << "\n" << endl;
    }
    cout << "\n--------------------------------------------------------------" << endl;
}
