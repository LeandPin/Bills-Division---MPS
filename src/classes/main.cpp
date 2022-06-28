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
#include "Utilitario.h"
#include "TemplateMethod/SaveAsTxt.h"
#include "TemplateMethod/SaveAsHtml.h"

using namespace std;


int main() {
    GerenciadorDeUsuarios gerente_de_usuarios = GerenciadorDeUsuarios();
    GerenciadorDeProdutos gerente_de_produto = GerenciadorDeProdutos();
    ListaDeCompras* lista_de_compras = ListaDeCompras::getInstance(&gerente_de_usuarios, &gerente_de_produto);
    Invoker *invoker = new Invoker;
    Caretaker *caretaker = new Caretaker(lista_de_compras);
    Usuario * usuario_logado = nullptr;
    Produtos* produto = nullptr;


    string _; // variável dummy
    int x = 0, n = 0; // Variáveis para o funcionamento do while, switch e for
    set < string, less < string >> treeSetUsuarios;
    set < tuple<int, int, int>, decltype(Utilitario::compare)*> treeSetUsuariosData(Utilitario::compare);

    string usuarioprincipal, senha, login;
    string usuarionormal;
    string conferesenha, conferelogin;
    int dia, mes, ano;

    string nomeProduto;
    int quantidade = 0, ID = 0;
    double preco = 0;

    while (x != 5) {
        // Verifica se exite um usuário adm, é necessário um para o programa funcionar.
        if (!Utilitario::existeAdmin(lista_de_compras->listaDeUsuarios())) {
            Telas::adminFaltado();
            cin >> x;
            cin.ignore();


            if (x == 1) { // Cria o 1º Admin, que é necessário para o programa funcionar.
                try {
                    Usuario* admin = Utilitario::criarUsuario(false);
                    invoker->AddUser(new AddUser(*lista_de_compras, *admin));
                    invoker->Do();
                    treeSetUsuarios.insert(login);
                    treeSetUsuariosData.insert({dia, mes, ano});
                } catch (UserNameException & e) {
                    Telas::loginInvalido();
                    continue;
                } catch (UserPasswordException & e) {
                    Telas::senhaInvalida();
                    continue;
                }
            } else {
                cout << "Adeus" << endl;
                return 0;
            }
        }
        for (auto el:lista_de_compras->listaDeUsuarios()) {
            cout << el->getLogin() << endl;
            cout << "acabou";
        }

        if (usuario_logado == nullptr) {
            Telas::login();
            try {
                usuario_logado = Utilitario::loginUsuario(lista_de_compras->listaDeUsuarios());
            } catch (UserNotFoundException & e) {
                Telas::usuarioNaoEncontrado();
                continue;
            }
        }

        Telas::menuPrincipal(usuario_logado->getLogin());

        cin >> x;
        cin.ignore();
        switch (x) {
            case 1: // Trocar usuário
                Telas::login();
                Telas::exibirlogins(lista_de_compras->listaDeUsuarios());
                try {
                    usuario_logado = Utilitario::loginUsuario(lista_de_compras->listaDeUsuarios());
                } catch (UserNotFoundException & e) {
                    Telas::usuarioNaoEncontrado();
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
                    Utilitario::alterarDados(usuario_logado, gerente_de_usuarios);
                }
                break;
            case 3: // Adicionar produto ao usuario;
                caretaker->backup();
                Utilitario::obterInformacoesProduto(nomeProduto, quantidade, preco, ID);
                produto = gerente_de_produto.criarProduto(nomeProduto, quantidade, preco, ID, 0);
                invoker->AddProductToUser(new AddProductToUser(*lista_de_compras, *produto, *usuario_logado));
                invoker->Do();
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
                                caretaker->backup();
                                Usuario * usuarioNovo = Utilitario::criarUsuario(true);
                                invoker->AddUser(new AddUser(*lista_de_compras, *usuarioNovo));
                                invoker->Do();

                                treeSetUsuarios.insert(usuarioNovo -> getLogin());
                                treeSetUsuariosData.insert(usuarioNovo->getData());
                            } catch (UserNameException & e) {
                                Telas::loginInvalido();
                            } catch (UserPasswordException & e) {
                                Telas::senhaInvalida();
                            }
                            break;
                        case 4:
                            Telas::salvar();
                            cin >> x;
                            cin.ignore();

                            if (x == 1) {
                                auto save = new SaveAsTxt(lista_de_compras, ".");
                                save->executar();
                                delete save;
                            }
                            else if (x == 2) {
                                auto save = new SaveAsHtml(lista_de_compras, ".");
                                save->executar();
                                delete save;
                            }
                            else break;
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
