#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <iterator>
#include <set>
#include "../headers/Telas.h"
#include "../headers/Usuario.h"
#include "../headers/UsuarioAdmin.h"
#include "../headers/UsuarioNormal.h"
#include "../headers/UserNameException.h"
#include "../headers/UserNotFoundException.h"
#include "../headers/UserPasswordException.h"
using namespace std;

bool existeAdmin(vector < Usuario * > usuarios) {
    for (auto elemento: usuarios) {
        if (elemento -> getPrivilegios()) return true;
    }
    return false;
}

Usuario * LoginUsuario(vector < Usuario * > usuarios) {
    string login, senha = "";
    Telas::Cadastrar("login");
    getline(cin, login);

    Telas::Cadastrar("senha");
    getline(cin, senha);

    for (auto elemento: usuarios) {
        if (elemento -> compararLogin(login) && elemento -> compararSenha(senha)) {
            return elemento;
        }
    }
    throw UserNotFoundException();
}

Usuario * criar_usuario(UsuarioAdmin & adm) {
    string nome, login, senha, privilegio = "";
    Telas::Cadastrar("nome");
    getline(cin, nome);

    Telas::Cadastrar("login");
    getline(cin, login);

    Telas::Cadastrar("senha");
    getline(cin, senha);

    cout << "1 para admin, 0 para normal" << endl;
    getline(cin, privilegio);

    if (privilegio == "1") {
        Usuario * novo_usuario = adm.CriarUsuario(nome, login, senha, 1);
        return novo_usuario;
    } else {
        Usuario * novo_usuario = adm.CriarUsuario(nome, login, senha, 0);
        return novo_usuario;
    }
}

void alterar_dados(Usuario * user) {
    string nome, senha = "";
    Telas::alterarNome();
    getline(cin, nome);

    Telas::alterarSenha();
    getline(cin, senha);
    try {
        user -> modificarInformacoes(nome, "", senha);
    } catch (UserNameException & e) {
        Telas::login_invalido();
    } catch (UserPasswordException & e) {
        Telas::senha_invalida();
    }
}

int main() {
    UsuarioAdmin * SUPERUSER = new UsuarioAdmin();
    Usuario * usuario_logado = nullptr;
    string _ = ""; // variável dummy
    int x = 0, n = 0; // Variáveis para o funcionamento do while, switch e for
    UsuarioAdmin usuario;
    vector < Usuario * > usuarios;
    set < string, less < string >> treeSetUsuarios;
    string usuarioprincipal, senha, login;
    string usuarionormal;
    string conferesenha, conferelogin;

    while (x != 5) {
        if (!existeAdmin(usuarios)) {
            Telas::AdminFaltado();
            cin >> x;
            cin.ignore();

            if (x == 1) {
                Telas::Cadastrar("nome");
                getline(cin, usuarioprincipal);

                Telas::Cadastrar("login");
                getline(cin, login);

                Telas::Cadastrar("senha");
                getline(cin, senha);

                try {
                    Usuario * admin = SUPERUSER -> CriarUsuario(usuarioprincipal, login, senha, 1);
                    admin -> modificarInformacoes(usuarioprincipal, login, senha);
                    usuarios.push_back(admin);
                    treeSetUsuarios.insert(login);
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
                usuario_logado = LoginUsuario(usuarios);
            } catch (UserNotFoundException & e) {
                Telas::usuario_nao_encontrado();
                continue;
            }
        }

        Telas::MenuPrincipal();
        cin >> x;
        cin.ignore();
        switch (x) {
        case 1: // Trocar usuário
            Telas::login();
            try {
                usuario_logado = LoginUsuario(usuarios);
            } catch (UserNotFoundException & e) {
                Telas::usuario_nao_encontrado();
                continue;
            }
            break;

        case 2: // Ver informações do usuário logado, e possibilidade de altera-las.
            Telas::exibirInformacoes(usuario_logado -> getNome(), usuario_logado -> getLogin(), usuario_logado -> getSenha(),
                usuario_logado -> getPrivilegios());
            cin >> x;
            cin.ignore();
            if (x == 1) {
                alterar_dados(usuario_logado);
            }
            break;

        case 3: // Acessar área do administrador caso tenha privilegios
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
                        for (auto elemento: usuarios) {
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
                        //TODO ordenar por nascimento
                        break;
                    }
                    default: {
                        break;
                    }
                    }
                    break;
                case 2:
                case 3:
                    try {
                        Usuario * usuarioNovo = criar_usuario( * SUPERUSER);
                        usuarios.push_back(usuarioNovo);
                        treeSetUsuarios.insert(usuarioNovo -> getLogin());
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

        case 4:
            cout << "Obrigado Por Utilizar Nosso Programa!\n" << endl;
            return 1;
            break;

        }
    }
    return 0;
}