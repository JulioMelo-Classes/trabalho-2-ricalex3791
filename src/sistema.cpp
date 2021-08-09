#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

/* COMANDOS */
string Sistema::quit() {
  return "Saindo do concordo";
}

string Sistema::create_user (const string email, const string senha, const string nome) {

  //Tratamento de erros
  vector<Usuario>::iterator it;
  for ( it = usuarios.begin(); it != usuarios.end(); it++ ) {
    if(it->email == email){
      return "Email já registrado!";
    }
  }

  Usuario newUser;
  newUser.email = email;
  newUser.senha = senha;
  newUser.nome = nome;
  newUser.id = usuarios.size();

  usuarios.push_back(newUser);
  return "Usuario criado!";
}

string Sistema::login(const string email, const string senha) {
  bool sucessoLogin=false;
  string sucessoMensagem;
  vector<Usuario>::iterator it;
  for ( it = usuarios.begin(); it != usuarios.end(); it++ ) {
    if((it->email == email) && (it->senha == senha)){
      //cout<<"Logado com ID "<< it->id<<endl;
      sucessoMensagem = "Conectado como " + it->email;
      usuariosLogados.insert(pair<int, pair<string,string>>(it->id,make_pair("","")));
      cout<<usuariosLogados.size()<<endl;
      sucessoLogin=true;
      break;
    }
  }
  if(sucessoLogin==false){
    return "Senha ou e-mail inválidos!";
  }else{
    return "Conectado como " + it->email;
  }
  
}

string Sistema::disconnect(int id) {
  map<int, pair<string, string>>::iterator it;
  cout<<usuariosLogados.size()<<endl;
  for ( it = usuariosLogados.begin(); it != usuariosLogados.end(); it++ ) {
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

string Sistema::create_server(int id, const string nome) {
  //Tratamento de erros
  vector<Servidor>::iterator itCheck;
  for ( itCheck = servidores.begin(); itCheck != servidores.end(); itCheck++ ) {
    if(itCheck->getNome() == nome){
      return "Servidor com esse nome já existe!";
    }
  }
  Servidor newServer;
  newServer.setNome(nome);
  newServer.getNome();

  newServer.setUsuarioDonoId(id);
  newServer.getUsuarioDonoId();
  servidores.push_back(newServer);

  return "Servidor criado";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
  //Tratamento de erros
  vector<Servidor>::iterator itCheck;
  for ( itCheck = servidores.begin(); itCheck != servidores.end(); itCheck++ ) {
    if(itCheck->getUsuarioDonoId() != id){
      return "Voce nao pode alterar a descricao de um servidor que nao foi criado por voce";
    }
  }

  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if(it->getNome() == nome){
      it->setDescricao(descricao);
      it->getDescricao();
      return "Descricao adicionada ao servidor " + descricao; 
    }else{
      return "Servidor nao encontrado";
    }
  }
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
  //Tratamento de erros
  vector<Servidor>::iterator itCheck;
  for ( itCheck = servidores.begin(); itCheck != servidores.end(); itCheck++ ) {
    if(itCheck->getUsuarioDonoId() != id){
      return "Voce nao pode alterar o codigo de convite de um servidor que nao foi criado por voce";
    }
  }

  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if(it->getNome() == nome){
      if(codigo == ""){
        it->setCodigoConvite(codigo);
        it->getCodigoConvite();
        return "Codigo de convite do servidor " + nome + " removido!";
      }else{
        it->setCodigoConvite(codigo);
        it->getCodigoConvite();
        return "Codigo de convite do servidor " + nome + " modificado!";
      }
      
    }
  }
  return "Servidor nao encontrado";
}

string Sistema::list_servers(int id) {
  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    cout<<it->getNome()<<endl;
  }
  return "";
}

string Sistema::remove_server(int id, const string nome) {
  //Tratamento de erros
  vector<Servidor>::iterator itCheck;
  for ( itCheck = servidores.begin(); itCheck != servidores.end(); itCheck++ ) {
    if(itCheck->getUsuarioDonoId() != id){
      return "Voce nao pode remover um servidor que nao foi criado por voce";
    }
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
      return "Servidor " + nome + "removido!";
    }
  }
  return "Servidor nao encontrado";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if((it->getNome() == nome) && (it->getCodigoConvite() == codigo)){
      
      it->participantesIDs.push_back(id);
      usuariosLogados.at(id).first = nome;

      cout<<"Entrou no servidor com sucesso!"<<endl;
      break;
    }else{
      cout<<"descricao ERRO!"<<endl;
    }
  }
  return "enter_server NÃO IMPLEMENTADO";
}

string Sistema::leave_server(int id, const string nome) {
  usuariosLogados.at(id).first = "";
  return "leave_server NÃO IMPLEMENTADO";
}

string Sistema::list_participants(int id) {
  string serverToSearch = usuariosLogados.at(id).first;
  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if(it->getNome() == serverToSearch){
      
      for(int i=0; i<it->participantesIDs.size(); i++){
        cout<<it->participantesIDs[i]<<endl;
      }

      cout<<"Entrou no servidor com sucesso!"<<endl;
      break;
    }else{
      cout<<"descricao ERRO!"<<endl;
    }
  }


  return "list_participants NÃO IMPLEMENTADO";
}

string Sistema::list_channels(int id) {
  string serverToSearch = usuariosLogados.at(id).first;
  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if(it->getNome() == serverToSearch){

      //cout<<it->canaisTexto[0].olharCanal()<<endl;
      it->listCanaisTexto();

      cout<<"Entrou no servidor com sucesso!"<<endl;
      break;
    }else{
      cout<<"descricao ERRO!"<<endl;
    }
  }
  return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(int id, const string nome) {
  string serverToSearch = usuariosLogados.at(id).first;
  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if(it->getNome() == serverToSearch){
      

      it->addCanalTexto(nome);
      //it->canaisTexto[it->canaisTexto.size()].mudarCanal(nome);

      cout<<"Entrou no servidor com sucesso!"<<endl;
      break;
    }else{
      cout<<"descricao ERRO!"<<endl;
    }
  }

  return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(int id, const string nome) {
  string serverToSearch = usuariosLogados.at(id).first;
  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if(it->getNome() == serverToSearch){
      for(int i=0; i<it->olharCanaisTextoTamanho();i++){
        if(it->accessCanalTextoNome(i) == nome){
          usuariosLogados.at(id).second = nome;
          cout<<"Entrou no canal com sucesso!"<<endl;
        }else{
          cout<<"NAO Entrou no CANAL com sucesso!"<<endl;
        }
      }
      
      break;
    }else{
      cout<<"descricao ERRO!"<<endl;
    }
  }
  return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel(int id) {
  usuariosLogados.at(id).second = "";
  
  return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(int id, const string mensagem) {
  string serverToSearch = usuariosLogados.at(id).first;
  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if(it->getNome() == serverToSearch){
      for(int i=0; i<it->olharCanaisTextoTamanho();i++){
        if(it->accessCanalTextoNome(i) == usuariosLogados.at(id).second){
          //it->canaisTexto[i].adicionarMensagem(id, mensagem);
          it->escreverMessagem(i, id, mensagem);
          cout<<"Enviou a mensagem com sucesso"<<endl;
        }else{
          cout<<"NAO enviou a mensagem com sucesso!"<<endl;
        }
      }
      
      break;
    }else{
      cout<<"descricao ERRO!"<<endl;
    }
  }
  return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages(int id) {
  string serverToSearch = usuariosLogados.at(id).first;
  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if(it->getNome() == serverToSearch){
      for(int i=0; i<it->olharCanaisTextoTamanho();i++){
        if(it->accessCanalTextoNome(i) == usuariosLogados.at(id).second){
          it->accessMessages(i);
          cout<<"Enviou a mensagem com sucesso"<<endl;
        }else{
          cout<<"NAO enviou a mensagem com sucesso!"<<endl;
        }
      }
      
      break;
    }else{
      cout<<"descricao ERRO!"<<endl;
    }
  }
  return "list_messages NÃO IMPLEMENTADO";
}




/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
