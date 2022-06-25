//
// Created by Gabriel on 25/06/2022.
//

#include "Utilitario.h"


void Utilitario::obterInformacoesProduto(string &nomeProduto, int &quantidade, double &preco, int &ID) {
    Telas::AdicionarProdutoNome();
    cin >> nomeProduto;

    Telas::AdicionarProdutoQuantidade();
    cin >> quantidade;

    Telas::AdicionarProdutoPreco();
    cin >> preco;

    Telas::AdicionarProdutoID();
    cin >> ID;
}


bool Utilitario::compare(tuple<int, int, int> d1, tuple<int, int, int> d2){
    auto [diaD1, mesD1, anoD1] = d1;
    auto [diaD2, mesD2, anoD2] = d2;
    if (anoD1 > anoD2){
        return true;
    }
    if (anoD1 == anoD2 && mesD1 > mesD2){
        return true;
    }
    if (anoD1 == anoD2 && mesD1 == mesD2 && diaD1 > diaD2){
        return true;
    }
    return false;
}


void Utilitario::alterarDados(Usuario * user, GerenciadorDeUsuarios gerente) {
    string nome, senha = "";
    Telas::alterarNome();
    getline(cin, nome);

    Telas::alterarSenha();
    getline(cin, senha);
    try {
        gerente.alterarDadosDoUsuario(*user, nome,"", senha, user->getPrivilegios(), user->getDia(), user->getMes(), user->getAno());
    } catch (UserNameException & e) {
        Telas::login_invalido();
    } catch (UserPasswordException & e) {
        Telas::senha_invalida();
    }
}


void Utilitario::pegarInformacoes(string &nome, string &login, string &senha, bool &privilegio, int &dia, int &mes, int &ano, bool perguntar) {
    Telas::Cadastrar("nome");
    cin >> nome;

    Telas::Cadastrar("login");
    cin >> login;

    Telas::Cadastrar("senha");
    cin >> senha;

    if (perguntar) {
        cout << "1 para admin, 0 para normal" << endl;
        cin >> privilegio;
    }

    Telas::Cadastrar("data de nascimento (DD/MM/AAAA)");
    cin >> dia;
    cin.ignore();
    cin >> mes;
    cin.ignore();
    cin >> ano;
    cin.ignore();
}


Usuario* Utilitario::criarUsuario(bool perguntar) {
    /*
     * Privilégio padrão é 1
     */
    string nome, login, senha;
    bool privilegio = true;
    int dia, mes, ano;
    Usuario* novo_usuario;

    pegarInformacoes(nome, login, senha, privilegio, dia, mes, ano, perguntar);

    if (privilegio) {
        novo_usuario = GerenciadorDeUsuarios::CriarUsuario(AdminUserCreator(), nome, login, senha, dia, mes, ano);
    } else {
        novo_usuario = GerenciadorDeUsuarios::CriarUsuario(NormalUserCreator(), nome, login, senha, dia, mes, ano);
    }
    return novo_usuario;
}


Usuario* Utilitario::loginUsuario(vector <Usuario *> usuarios) {
    string login, senha = "";
    Telas::Cadastrar("login");
    getline(cin, login);

    Telas::Cadastrar("senha");
    getline(cin, senha);

    for (auto elemento: usuarios) {
        // bool res1 = elemento->compararLogin(login);
        // bool res2 = elemento->compararSenha(senha);
        if (GerenciadorDeUsuarios::compararLogin(elemento->getLogin(), login) &&
            GerenciadorDeUsuarios::compararSenha(elemento->getSenha(), senha)) {
            return elemento;
        }
    }
    throw UserNotFoundException();
}


bool Utilitario::existeAdmin(vector < Usuario * > usuarios) {
    for (auto elemento: usuarios) {
        if (elemento->getPrivilegios()) return true;
    }
    return false;
}