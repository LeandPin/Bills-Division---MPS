#include <string>
#include <iostream>
#include <vector>

#include "Entidades/Usuario.h"
#include "Controllers/GerenciadorDeUsuarios.h"
#include "Entidades/Produtos.h"
#include "Controllers/GerenciadorDeProdutos.h"


class TemplateMethod {
	private:
		string NomeUsuario;
		struct ListaProdutos;
		
	public:
		void extrairInformacoesUsuario();
		virtual void Parse() const {}
		virtual void Export() const {}
	
};