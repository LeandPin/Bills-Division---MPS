#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <tuple>
#include "Facade/ListaDeCompras.h"
#include "../headers/Telas.h"
#include "Entidades/Usuario.h"
#include "Entidades/UsuarioAdmin.h"
#include "Entidades/UsuarioNormal.h"
#include "Exceptions/UserNameException.h"
#include "Exceptions/UserNotFoundException.h"
#include "Exceptions/UserPasswordException.h"
#include "Controllers/GerenciadorDeUsuarios.h"
#include "Controllers/GerenciadorDeProdutos.h"
#include "Command/Invoker.h"
#include "Command/AddUser.h"
#include "Command/AddProductToUser.h"
#include "memento/Caretaker.h"

using namespace std;

bool existeAdmin(vector < Usuario * > usuarios);
bool compare(tuple<int, int, int> d1, tuple<int, int, int> d2);

Usuario * loginUsuario(vector < Usuario * > usuarios);
void pegarInformacoes(string &nome, string &login, string &senha, bool &privilegio, int &dia, int &mes, int &ano, bool perguntar);
Usuario * criarUsuario(bool perguntar);


void alterarDados(Usuario * user);
void obterInformacoesProduto(string &nomeProduto, int &quantidade, double &preco, int &ID);


int main() {
    GerenciadorDeUsuarios gerente_de_usuarios = GerenciadorDeUsuarios();
    GerenciadorDeProdutos gerente_de_produto = GerenciadorDeProdutos();
    ListaDeCompras* lista_de_compras = ListaDeCompras::GetInstance(&gerente_de_usuarios, &gerente_de_produto);
    Invoker *invoker = new Invoker;
    Caretaker *caretaker = new Caretaker(lista_de_compras);
    Usuario * usuario_logado = nullptr;
    Produtos* produto = nullptr;


    string _; // variável dummy
    int x = 0, n = 0; // Variáveis para o funcionamento do while, switch e for
    set < string, less < string >> treeSetUsuarios;
    set < tuple<int, int, int>, decltype(compare)*> treeSetUsuariosData(compare);

    string usuarioprincipal, senha, login;
    string usuarionormal;
    string conferesenha, conferelogin;
    int dia, mes, ano;

    string nomeProduto;
    int quantidade = 0, ID = 0;
    double preco = 0;

    while (x != 5) {
        // Verifica se exite um usuário adm, é necessário um para o programa funcionar.
        if (!existeAdmin(lista_de_compras->listaDeUsuarios())) {
            Telas::AdminFaltado();
            cin >> x;
            cin.ignore();


            if (x == 1) { // Cria o 1º Admin, que é necessário para o programa funcionar.
                try {
                    Usuario* admin = criarUsuario(false);
                    invoker->AddUser(new AddUser(*lista_de_compras, *admin));

                    treeSetUsuarios.insert(login);
                    treeSetUsuariosData.insert({dia, mes, ano});
                } catch (UserNameException & e) {
                    Telas::login_invalido();
                    continue;
                } catch (UserPasswordException & e) {
                    Telas::senha_invalida();
                    continue;
                }
            } else {
                cout << "Adeus" << endl;
                return 0;
            }
        }

        if (usuario_logado == nullptr) {
            Telas::login();
            try {
                usuario_logado = loginUsuario(lista_de_compras->listaDeUsuarios());
            } catch (UserNotFoundException & e) {
                Telas::usuario_nao_encontrado();
                continue;
            }
        }

        Telas::MenuPrincipal(usuario_logado->getLogin());

        cin >> x;
        cin.ignore();
        switch (x) {
        case 1: // Trocar usuário
            Telas::login();
            Telas::exibirlogins(lista_de_compras->listaDeUsuarios());
            try {
                usuario_logado = loginUsuario(lista_de_compras->listaDeUsuarios());
            } catch (UserNotFoundException & e) {
                Telas::usuario_nao_encontrado();
                continue;
            }
            break;

        case 2: // Ver informações do usuário logado, e possibilidade de altera-las.
            Telas::exibirProdutos(usuario_logado->getLogin(), lista_de_compras->listaDeProdutos(usuario_logado->getLogin()));
            Telas::exibirInformacoes(usuario_logado -> getNome(), usuario_logado -> getLogin(), usuario_logado -> getSenha(),
                usuario_logado -> getPrivilegios(), usuario_logado->getData());
            cin >> x;
            cin.ignore();
            if (x == 1) {
                alterarDados(usuario_logado);
            }
            break;
        case 3: // Adicionar produto ao usuario;
            caretaker->Backup();
            obterInformacoesProduto(nomeProduto, quantidade, preco, ID);
            produto = gerente_de_produto.criarProduto(nomeProduto, quantidade, preco, ID, 0);
            invoker->AddProductToUser(new AddProductToUser(*lista_de_compras, *produto, *usuario_logado));
            // lista_de_compras->adiconarProdutoAoUsuario(usuario_logado, produto);
            break;
        case 4: // Acessar área do administrador caso tenha privilegios
            if (usuario_logado -> getPrivilegios()) {
                Telas::areaAdm();

                cin >> x;
                cin.ignore();

                switch (x) {
                case 1:
                    Telas::modoExib();
                    cin >> x;
                    cin.ignore();
                    switch (x) {
                    case 1: {
                        for (auto elemento: lista_de_compras->listaDeUsuarios()) {
                            cout << elemento -> getLogin() << endl;
                        }
                        break;
                    }
                    case 2: {
                        set < string, greater < string > > ::iterator itr;
                        for (itr = treeSetUsuarios.begin(); itr != treeSetUsuarios.end(); itr++) {
                            cout << * itr << "\n";
                        }
                        cout << endl;
                        break;
                    }
                    case 3: {
                        set<std::tuple<int, int, int>>::iterator itt;
                        for ( itt=treeSetUsuariosData.begin(); itt != treeSetUsuariosData.end(); itt++){
                            auto [dia, mes, ano] = *itt;
                            for(auto elemento: lista_de_compras->listaDeUsuarios()){
                                if(elemento->getDia()==dia && elemento->getMes()==mes && elemento->getAno()==ano){
                                    cout << elemento -> getLogin() << endl;
                                    break;
                                }
                            }
                        }
                    }
                    default: {
                        break;
                    }
                    }
                    break;
                case 2: // Modifical algum usuario especifico
                    break;
                case 3: // Criar um novo usuário
                    try {
                        caretaker->Backup();
                        Usuario * usuarioNovo = criarUsuario(true);
                        invoker->AddUser(new AddUser(*lista_de_compras, *usuarioNovo));
                        //lista_de_compras->adicionarUsuarioALista(usuarioNovo);

                        treeSetUsuarios.insert(usuarioNovo -> getLogin());
                        treeSetUsuariosData.insert(usuarioNovo->getData());
                    } catch (UserNameException & e) {
                        Telas::login_invalido();
                    } catch (UserPasswordException & e) {
                        Telas::senha_invalida();
                    }
                    break;
                default:
                    break;

                }
            } else {
                Telas::semPrivilegios();
                cin >> _;
            }
            break;

        case 5:
            cout << "Obrigado Por Utilizar Nosso Programa!\n" << endl;
            return 1;
            break;
        default:
            cout << "Comando desconhecido." << endl;
            break;
        }
    }
    return 0;
}


void obterInformacoesProduto(string &nomeProduto, int &quantidade, double &preco, int &ID) {
    Telas::AdicionarProdutoNome();
    cin >> nomeProduto;

    Telas::AdicionarProdutoQuantidade();
    cin >> quantidade;

    Telas::AdicionarProdutoPreco();
    cin >> preco;

    Telas::AdicionarProdutoID();
    cin >> ID;
}


bool compare(tuple<int, int, int> d1, tuple<int, int, int> d2){
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


void alterarDados(Usuario * user) {
    GerenciadorDeUsuarios gerente = GerenciadorDeUsuarios();
    string nome, senha = "";
    Telas::alterarNome();
    getline(cin, nome);

    Telas::alterarSenha();
    getline(cin, senha);
    try {
        gerente.alterarDadosDoUsuario(*user, nome,"", senha, user->getPrivilegios(), user->getDia(), user->getMes(), user->getAno());
        // user -> modificarInformacoes(nome, "", senha); depreciado
    } catch (UserNameException & e) {
        Telas::login_invalido();
    } catch (UserPasswordException & e) {
        Telas::senha_invalida();
    }
}


void pegarInformacoes(string &nome, string &login, string &senha, bool &privilegio, int &dia, int &mes, int &ano, bool perguntar) {
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


Usuario * criarUsuario(bool perguntar) {
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


Usuario * loginUsuario(vector < Usuario * > usuarios) {
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


bool existeAdmin(vector < Usuario * > usuarios) {
    for (auto elemento: usuarios) {
        if (elemento -> getPrivilegios()) return true;
    }
    return false;
}