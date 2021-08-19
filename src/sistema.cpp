#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;

/* COMANDOS */
string Sistema::quit() {
  return "Saindo do concordo";
}

/*
A1.1 ok
*/
string Sistema::create_user (const string email, const string senha, const string nome) {

  //Tratamento de erros
  vector<Usuario>::iterator it;
  for ( it = usuarios.begin(); it != usuarios.end(); it++ ) {
    if(it->email == email){
      return "Email já registrado!";
    }
  }
  if( email == "" || senha == "" || nome == ""){
    return "Input invalido";
  }

  Usuario newUser;
  newUser.email = email;
  newUser.senha = senha;
  newUser.nome = nome;
  newUser.id = usuarios.size();

  usuarios.push_back(newUser);
  return "Usuario criado!";
}

/*
A1.2 ok
*/
string Sistema::login(const string email, const string senha) {
  bool sucessoLogin=false;
  string sucessoMensagem;
  vector<Usuario>::iterator it;
  for ( it = usuarios.begin(); it != usuarios.end(); it++ ) {
    if((it->email == email) && (it->senha == senha)){
      sucessoMensagem = "Conectado como " + it->email;
      usuariosLogados.insert(pair<int, pair<string,string>>(it->id,make_pair("","")));
      sucessoLogin=true;
      break;
    }
  }
  if(sucessoLogin==false){
    return "Senha ou e-mail invalidos!";
  }else{
    return "Conectado como " + it->email;
  }
  
}

/*
A2.1 ok
*/
string Sistema::disconnect(int id) {
  //map<int, pair<string, string>>::iterator it; //aqui vc pode usar auto!

  for (auto it = usuariosLogados.begin(); it != usuariosLogados.end(); it++ ) { //fica melhor assim do que declarar o iterator!
    if((it->first == id)){
      vector<Usuario>::iterator it2;
      for ( it2 = usuarios.begin(); it2 != usuarios.end(); it2++ ) {
        if(it2->id == id){
          it=usuariosLogados.erase(it);
          return "Desconectando usuario " + it2->email;
        }
      }
    }
  }
  return "Usuario nao esta conectado";
}

/*
A2.2 ok
*/
string Sistema::create_server(int id, const string nome) {
  //Tratamento de erros
  vector<Servidor>::iterator itCheck;
  for ( itCheck = servidores.begin(); itCheck != servidores.end(); itCheck++ ) {
    if(itCheck->getNome() == nome){
      return "Servidor com esse nome já existe!";
    }
  }

  if(verifyLoginStatus(id) == false){
    return "Usuario nao esta conectado";
  }

  Servidor newServer;
  newServer.setNome(nome);
  newServer.getNome();

  newServer.setUsuarioDonoId(id);
  newServer.getUsuarioDonoId();
  servidores.push_back(newServer);

  return "Servidor criado";
}

bool Sistema::verifyLoginStatus(int id)
{
  map<int, pair<string, string>>::iterator it;
  for ( it = usuariosLogados.begin(); it != usuariosLogados.end(); it++ ) {
    if((it->first == id)){
      return true;
    }
  }
  return false;
}

/*
A2.3 ok
*/
string Sistema::set_server_desc(int id, const string nome, const string descricao) {
  //Tratamento de erros
  vector<Servidor>::iterator itCheck;
  for ( itCheck = servidores.begin(); itCheck != servidores.end(); itCheck++ ) {
    if((itCheck->getNome() == nome) && (itCheck->getUsuarioDonoId() != id)){
      return "Voce nao pode alterar a descricao de um servidor que nao foi criado por voce";
    }
  }

  if(verifyLoginStatus(id) == false){
    return "Usuario nao esta conectado";
  }

  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if(it->getNome() == nome){
      it->setDescricao(descricao);
      it->getDescricao();
      return "Descricao adicionada ao servidor " + nome; 
    }
  }
  return "Servidor nao encontrado";
}

/*
A2.4 ok
*/
string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
  //Tratamento de erros
  vector<Servidor>::iterator itCheck;
  for ( itCheck = servidores.begin(); itCheck != servidores.end(); itCheck++ ) {
    if((itCheck->getNome() == nome) && (itCheck->getUsuarioDonoId() != id)){
      return "Voce nao pode alterar o codigo de convite de um servidor que nao foi criado por voce";
    }
  }

  if(verifyLoginStatus(id) == false){
    return "Usuario nao esta conectado";
  }

  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if(it->getNome() == nome){
      if(codigo == ""){
        it->setCodigoConvite(codigo);
        it->getCodigoConvite();
        return "Codigo de convite do servidor '" + nome + "' removido!";
      }else{
        it->setCodigoConvite(codigo);
        it->getCodigoConvite();
        return "Codigo de convite do servidor '" + nome + "' modificado!";
      }
      
    }
  }
  return "Servidor nao encontrado";
}

/*
A2.5 ok!
*/
string Sistema::list_servers(int id) {
  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    cout<<it->getNome()<<endl;
  }
  return "";
}

/*
A2.6 ok
*/
string Sistema::remove_server(int id, const string nome) {
  //Tratamento de erros
  vector<Servidor>::iterator itCheck;
  for ( itCheck = servidores.begin(); itCheck != servidores.end(); itCheck++ ) {
    if((itCheck->getNome() == nome) && (itCheck->getUsuarioDonoId() != id)){
      return "Voce nao pode remover um servidor que nao foi criado por voce";
    }
  }

  if(verifyLoginStatus(id) == false){
    return "Usuario nao esta conectado";
  }

  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if(it->getNome() == nome){

      map<int, pair<string, string>>::iterator it2;
      for ( it2 = usuariosLogados.begin(); it2 != usuariosLogados.end(); it2++ ) {
        if((it2->second.first == nome)){
          it2->second.first = "";
          it2->second.second = "";
        }
      }

      servidores.erase(it);
      return "Servidor '" + nome + "' removido!";
    }
  }
  return "Servidor nao encontrado";
}


/*
A2.7 0,6
- Quando um usuário chama enter-server duas vezes ele acaba ficando duplicado no servidor! 20% a menos
- Quando o dono do servidor tenta entrar nele, não é necessário senha! 20% a menos
*/
string Sistema::enter_server(int id, const string nome, const string codigo) {

  if(verifyLoginStatus(id) == false){
    return "Usuario nao esta conectado";
  }

  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if(it->getNome() == nome){
      if(it->getCodigoConvite() != "" && (codigo == "")){
        return "Servidor requer codigo de convite";
      }
      if(it->getCodigoConvite() != codigo){
        return "Codigo de convite incorreto";
      }else{
        it->addID(id);
        usuariosLogados.at(id).first = nome;
        return "Entrou no servidor com sucesso!";
      }
    }
  }
  return "Servidor nao encontrado";
}

/*
A2.8 0,8
- Quando um usuário sai de um servidor, além de atualizar a tabela de usuários logados (se for o servidor que está sendo visualizado) o
usuário deve ser removido da lista de participantes! -20%
*/
string Sistema::leave_server(int id, const string nome) {

  if(verifyLoginStatus(id) == false){
    return "Usuario nao esta conectado";
  }

  map<int, pair<string, string>>::iterator it;
  for ( it = usuariosLogados.begin(); it != usuariosLogados.end(); it++ ) {
    if((it->first == id)){
      if(it->second.first != nome){
        return "Usuario nao esta no servidor";
      }else{
        it->second.first = "";
        it->second.second = "";
        return "Saindo do servidor " + nome;
      }
    }
  }
  return "Usuario nao encontrado";
}

/*
A2.9 0,5
- Vou considerar 50% uma vez que os nomes não são exibidos!
*/
string Sistema::list_participants(int id) {

  if(verifyLoginStatus(id) == false){
    return "Usuario nao esta conectado";
  }

  string serverToSearch = usuariosLogados.at(id).first;

  if(usuariosLogados.at(id).first == ""){
    return "Usuario nao esta em nenhum servidor";
  }

  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if(it->getNome() == serverToSearch){
      
      for(int i=0; i<it->checkIDSize(); i++){
        cout<<it->checkID(i)<<endl;
      }

      return "";
    }
  }

  return "Servidor nao encontrado";
}

/*
B1.1 0,9
- Quando um servidor não tem canais, nada é informado! -10%
*/
string Sistema::list_channels(int id) {

  if(verifyLoginStatus(id) == false){
    return "Usuario nao esta conectado";
  }

  string serverToSearch = usuariosLogados.at(id).first;

  if(serverToSearch == ""){
    return "Usuario nao esta em nenhum servidor";
  }

  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if(it->getNome() == serverToSearch){

      it->listCanaisTexto();

      return "";
    }
  }
  return "Servidor nao encontrado";
}

/*
B1.2 0,8
- Quando um a função é chamada com um canal com o mesmo nome ele acaba ficando duplicado na lista de canais. -20%
*/
string Sistema::create_channel(int id, const string nome) {

  if(verifyLoginStatus(id) == false){
    return "Usuario nao esta conectado";
  }

  string serverToSearch = usuariosLogados.at(id).first;

  if(serverToSearch == ""){
    return "Usuario nao esta em nenhum servidor";
  }

  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if(it->getNome() == serverToSearch){
      it->addCanalTexto(nome);
      return "Canal de texto '" + nome + "' criado!";
    }
  }

  return "Servidor nao encontrado";
}

/*
B1.3 ok
*/
string Sistema::enter_channel(int id, const string nome) {

  if(verifyLoginStatus(id) == false){
    return "Usuario nao esta conectado";
  }

  string serverToSearch = usuariosLogados.at(id).first;

  if(serverToSearch == ""){
    return "Usuario nao esta em nenhum servidor";
  }

  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if(it->getNome() == serverToSearch){
      for(int i=0; i<it->olharCanaisTextoTamanho();i++){
        if(it->accessCanalTextoNome(i) == nome){
          usuariosLogados.at(id).second = nome;
          return "Entrou no canal '" + nome + "'";
        }
      }
      return "Canal '" + nome + "' nao existe";
      break;
    }
  }

  return "Servidor nao encontrado";
}

/*
B1.4 ok
*/
string Sistema::leave_channel(int id) {

  if(verifyLoginStatus(id) == false){
    return "Usuario nao esta conectado";
  }

  usuariosLogados.at(id).second = "";
  
  return "Saindo do canal";
}

/*
B2.1 ok
*/
string Sistema::send_message(int id, const string mensagem) {

  if(verifyLoginStatus(id) == false){
    return "Usuario nao esta conectado";
  }

  string serverToSearch = usuariosLogados.at(id).first;
  if(usuariosLogados.at(id).first == ""){
    return "Usuario nao esta em nenhum servidor";
  }
  if(usuariosLogados.at(id).second == ""){
    return "Usuario nao esta em nenhum canal";
  }
  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if(it->getNome() == serverToSearch){
      for(int i=0; i<it->olharCanaisTextoTamanho();i++){
        if(it->accessCanalTextoNome(i) == usuariosLogados.at(id).second){

          /*
          time_t rawtime;
          struct tm timeinfo;
          time(&rawtime);
          ::localtime_s(&timeinfo, &rawtime);

          */
          //coloquei uma versão mais c++ pra evitar problemas de portabilidade de localtime_s
          time_t dataHora;
          struct tm * timeinfo;
          char buffer[80];
          time (&dataHora);
          timeinfo = localtime(&dataHora);
          strftime(buffer, 80, "<%d/%m/%Y - %H:%M>", timeinfo);
          string dataFormatada(buffer);

          ostringstream oss;
          oss << usuarios[id].nome << " " << dataFormatada;
          string str = oss.str();

          it->escreverMessagem(i, id, mensagem, str);
          return "Mensagem enviada por " + usuarios[id].nome;
        }
      }
    }
  }
  return "Servidor nao encontrado";
}

/*
B2.2 0,9
-Quando um canal está vazio nada é exibido! -10%
*/
string Sistema::list_messages(int id) {

  if(verifyLoginStatus(id) == false){
    return "Usuario nao esta conectado";
  }

  string serverToSearch = usuariosLogados.at(id).first;
  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if(it->getNome() == serverToSearch){
      for(int i=0; i<it->olharCanaisTextoTamanho();i++){
        if(it->accessCanalTextoNome(i) == usuariosLogados.at(id).second){
          it->accessMessages(i);
          return "";
        }
      }
    }
  }
  return "Servidor nao encontrado";
}

/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
