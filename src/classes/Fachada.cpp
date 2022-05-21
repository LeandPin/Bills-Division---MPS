//
// Created by Gabriel on 21/05/2022.
//

#include "Fachada.h"

Fachada::Fachada(GerenciadorDeUsuarios *gerenciadorDeUsuarios, GerenciadorDeProdutos *gerenciadorDeProdutos) {

}

Fachada *
Fachada::GetInstance(GerenciadorDeUsuarios *gerenciadorDeUsuarios, GerenciadorDeProdutos *gerenciadorDeProdutos) {
    if (fachada_ == nullptr) {
        fachada_ = new Fachada(gerenciadorDeUsuarios, gerenciadorDeProdutos);
    }
    return fachada_;
}
