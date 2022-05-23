//
// Created by Gabriel on 21/05/2022.
//

#ifndef MPS___MASTER_FACHADA_H
#define MPS___MASTER_FACHADA_H

// Nome temporario
#include <vector>
#include "Usuario.h"
#include "Produtos.h"
#include "GerenciadorDeProdutos.h"
#include "GerenciadorDeUsuarios.h"
#include "UserNotFoundException.h"

struct elemento {
    Usuario* usuario;
    vector<Produtos*> produtos;
};


/*
 * Essa classe deve ser uma Fachada singleton
 *
 * O que deve ter nessa classe?
 * metodos de adição de produtos a usuarios
 * calculo do total para um usuario
 * calculo do total para toda a conta
 *
 * lista de usuarios com os produtos
 */
class Fachada {
protected:
    Fachada(GerenciadorDeUsuarios* gerenciadorDeUsuarios = nullptr, GerenciadorDeProdutos* gerenciadorDeProdutos = nullptr);
    vector<elemento> listaDeCompras;
    GerenciadorDeUsuarios *gerenteUsuarios_;
    GerenciadorDeProdutos *gerenteProdutos_;

    static Fachada* fachada_;

public:
    ~Fachada();
    Fachada(Fachada &other) = delete;
    void operator=(const Fachada &) = delete;
    static Fachada *GetInstance(GerenciadorDeUsuarios* gerenciadorDeUsuarios = nullptr, GerenciadorDeProdutos* gerenciadorDeProdutos = nullptr);
    void adicionarUsuarioALista(Usuario* usuario);
    void adiconarProdutoAoUsuario(Usuario* usuario, Produtos* produto);
    vector<Produtos*> listaDeProdutos(string login);
    vector<Usuario*> listaDeUsuarios();
};


#endif //MPS___MASTER_FACHADA_H
