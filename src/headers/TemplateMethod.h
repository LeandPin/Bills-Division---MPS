#include <string>
#include <iostream>
#include <vector>

#include "Usuario.h"
#include "GerenciadorDeUsuarios.h"
#include "Produtos.h"
#include "GerenciadorDeProdutos.h"


class TemplateMethod {
	private:
		string NomeUsuario;
		struct ListaProdutos;
		
	public:
		void extrairInformacoesUsuario();
		virtual void Parse() const {}
		virtual void Export() const {}
	
};