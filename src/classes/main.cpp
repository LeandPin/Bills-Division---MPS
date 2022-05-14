#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <iterator>
#include <set>
#include <tuple>
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
    int dia, mes, ano;
    Telas::Cadastrar("nome");
    getline(cin, nome);

    Telas::Cadastrar("login");
    getline(cin, login);

    Telas::Cadastrar("senha");
    getline(cin, senha);

    cout << "1 para admin, 0 para normal" << endl;
    getline(cin, privilegio);

    Telas::Cadastrar("data de nascimento (DD/MM/AAAA)");
    cin >> dia;
    cin.ignore();
    cin >> mes;
    cin.ignore();
    cin >> ano;

    if (privilegio == "1") {
        Usuario * novo_usuario = adm.CriarUsuario(nome, login, senha, 1, dia, mes, ano);
        return novo_usuario;
    } else {
        Usuario * novo_usuario = adm.CriarUsuario(nome, login, senha, 0, dia, mes, ano);
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

int main() {
    UsuarioAdmin * SUPERUSER = new UsuarioAdmin();
    Usuario * usuario_logado = nullptr;
    string _ = ""; // variável dummy
    int x = 0, n = 0; // Variáveis para o funcionamento do while, switch e for
    UsuarioAdmin usuario;
    vector < Usuario * > usuarios;
    set < string, less < string >> treeSetUsuarios;
    set < tuple<int, int, int>, decltype(compare)*> treeSetUsuariosData(compare);
    string usuarioprincipal, senha, login;
    string usuarionormal;
    string conferesenha, conferelogin;
    int dia, mes, ano;

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

                Telas::Cadastrar("data de nascimento (DD/MM/AAAA)");
                std::cin >> dia;
                cin.ignore();
                std::cin >> mes;
                cin.ignore();
                std::cin >> ano;
                cin.ignore();

                try {
                    Usuario * admin = SUPERUSER -> CriarUsuario(usuarioprincipal, login, senha, 1, dia, mes, ano);
                    admin -> modificarInformacoes(usuarioprincipal, login, senha);
                    usuarios.push_back(admin);
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
                usuario_logado -> getPrivilegios(), usuario_logado->getData());
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
                        set<std::tuple<int, int, int>>::iterator itt;
                        for ( itt=treeSetUsuariosData.begin(); itt != treeSetUsuariosData.end(); itt++){
                            auto [dia, mes, ano] = *itt;
                            for(auto elemento: usuarios){
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
                case 2:
                case 3:
                    try {
                        Usuario * usuarioNovo = criar_usuario( * SUPERUSER);
                        usuarios.push_back(usuarioNovo);
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

        case 4:
            cout << "Obrigado Por Utilizar Nosso Programa!\n" << endl;
            return 1;
            break;

        }
    }
    return 0;
}