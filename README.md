# Aplicação de divisão de comandas - Bill Division

Este é um projeto referente a disciplina Métodos de Projetos de Software, ofertada pela Universidade Federal da Paraíba.



## Objetivo
Têm-se como objetivo principal a criação de uma aplicação de divisão de comanda, denominada Bill Division. 

Quando múltiplos clientes dividem uma mesa de algum estabelecimento nem todos consomem as mesmas coisas, e na hora de dividir cálculos precisam ser feitos para atribuir um valor a ser pago por cada um na conta. Sendo assim, o Bill Division veio para descomplicar esse inconveniente, atribuindo diretamente o valor a ser pago por cada um da mesa, sem precisar com que os clientes façam quaisquer cálculos de divisão.

## Descrição
### Tipos de usuário
* Principal/Administrador;
* Básico;

O programa permitirá o cadastro de usuários principais, que terão privilégios de adicionar outros participantes (usuários básicos), itens, remover usuário, editar usuários básicos e itens, verificar total da conta e o total para cada usuário à parte. O usuário básico terá o privilégio de pagar sua parte e retirar-se da conta que será registrada em um histórico.

Ao entrar pela primeira vez no programa (caso não exista usuário cadastrado anteriormente), será exibida uma mensagem para cadastrar um usuário principal, e permitirá o cadastro do mesmo. Após isso, será solicitado um login e senha do usuário principal (cadastrado anteriormente) para uso da aplicação.

#### Restrições de cadastro:
* Senha: 
  Máximo de 20 caracteres e mínimo de 8, deve possuir letras e números e ao menos 2 números.
* Login:
  Máximo de 12 caracteres, não pode ser vazio e não pode conter números.

#### Feito a validação de administrador será exibido o menu principal de opções, com os seguintes campos:
* Trocar de Usuário:
  Troca de usuário principal.
* Ver Informações de Usuário:
  Exibe as informações do usuário principal.
* Acessar Área do administrador:
  Acessa uma área de menu restrita ao administrador.
* Encerrar o Programa;

#### Menu de Administrador, seguintes campos:
* Exibir todos os usuários cadastrados:
  Exibe todos os usuários, incluindo principais e básicos.
* Modificar algum usuário (função nao implementada):
  Permite alteração nos dados de algum usuário.
* Criar novo usuário:
  Permite a criação de um usuário básico.
* Voltar:
  Retorna ao menu principal.
  
 #### OBS:
 O programa está em construção, então não foi atingido o objetivo final por momento. As partes implementadas atentam-se ao cadastro de usuários.
 
 ## Telas
 
 ### Tela Quando não há usuários cadastrados
  <img src="https://github.com/LeandPin/Bills-Division---MPS/blob/main/Tela0Usuarios.jpeg" alt="Tela0" style="width:600px;"/>
 
 ### Tela de Cadastro 1º Administrador
  <img src="https://github.com/LeandPin/Bills-Division---MPS/blob/main/TelaDeCadastroAdmin.jpeg" alt="CadastrofirstAdmin" width="600"/>
 
 ### Tela de Login Primeiro Administrador e Menu Principal
   <img src="https://github.com/LeandPin/Bills-Division---MPS/blob/main/Teladelogin.jpeg" alt="LoginfirstAdmin" width="600"/>
   
 ### Tela de informação do usuário
  <img src="https://github.com/LeandPin/Bills-Division---MPS/blob/main/TelaInforma%C3%A7%C3%A3oUsuario.jpeg" alt="informaçãoUsuario" width="600"/>

### Tela de Alteração dos dados
  <img src="https://github.com/LeandPin/Bills-Division---MPS/blob/main/TelaAltera%C3%A7%C3%A3oDados.jpeg" alt="alteraçãodosdados" width="600"/>

### Tela de Administrador
   <img src="https://github.com/LeandPin/Bills-Division---MPS/blob/main/%C3%81reaDoAdministrador.jpeg" alt="telaAdmin" width="600"/>

### Tela de adicionar novo usuário
 <img src="https://github.com/LeandPin/Bills-Division---MPS/blob/main/AdicionandoNovoUsuario.jpeg" alt="NewUser" width="600"/>
 
 ### Tela de Cadastro/Login Inválido
 <img src="https://github.com/LeandPin/Bills-Division---MPS/blob/main/ExibindoErroLogin.jpeg" alt="LoginInvalido" width="600"/>
 
 ### Tela de listar todos os usuários
 <img src="https://github.com/LeandPin/Bills-Division---MPS/blob/main/ListandoTodosUsu%C3%A1rios.jpeg" alt="ListarUsuarios" width="600"/>
 
 ### Tela de trocar Usuário
 <img src="https://github.com/LeandPin/Bills-Division---MPS/blob/main/TrocandoDeUsuario.jpeg" alt="TrocarUsuario" width="600"/>
 
 
 





