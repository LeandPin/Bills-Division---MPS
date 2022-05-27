//
// Created by Gabriel on 21/05/2022.
//

#ifndef MPS___MASTER_LISTADECOMPRAS_H
#define MPS___MASTER_LISTADECOMPRAS_H

// Nome temporario
#include <vector>
#include <unordered_map>
#include "Entidades/Usuario.h"
#include "Entidades/Produtos.h"
#include "Controllers/GerenciadorDeProdutos.h"
#include "Controllers/GerenciadorDeUsuarios.h"
#include "Exceptions/UserNotFoundException.h"


/*
 * Essa classe deve ser uma ListaDeCompras singleton
 *
 * O que deve ter nessa classe?
 * metodos de adição de produtos a usuarios
 * calculo do total para um usuario
 * calculo do total para toda a conta
 *
 * lista de usuarios com os produtos
 */
class ListaDeCompras {
protected:
    ListaDeCompras(GerenciadorDeUsuarios* gerenciadorDeUsuarios = nullptr, GerenciadorDeProdutos* gerenciadorDeProdutos = nullptr);

    unordered_map<Usuario*, vector<Produtos*>> listaDeCompras;
    GerenciadorDeUsuarios *gerenteUsuarios_;
    GerenciadorDeProdutos *gerenteProdutos_;

    static ListaDeCompras* fachada_;

public:
    ~ListaDeCompras();
    ListaDeCompras(ListaDeCompras &other) = delete;
    void operator=(const ListaDeCompras &) = delete;
    static ListaDeCompras *GetInstance(GerenciadorDeUsuarios* gerenciadorDeUsuarios = nullptr, GerenciadorDeProdutos* gerenciadorDeProdutos = nullptr);
    void adicionarUsuarioALista(Usuario* usuario);
    void adiconarProdutoAoUsuario(Usuario* usuario, Produtos* produto);
    vector<Produtos*> listaDeProdutos(string login);
    vector<Usuario*> listaDeUsuarios();
};


#endif //MPS___MASTER_LISTADECOMPRAS_H
