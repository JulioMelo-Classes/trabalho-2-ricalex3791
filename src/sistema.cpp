#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

/* COMANDOS */
string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_user (const string email, const string senha, const string nome) {
  Usuario newUser;
  newUser.email = email;
  newUser.senha = senha;
  newUser.nome = nome;
  newUser.id = usuarios.size();

  usuarios.push_back(newUser);
  return "create_user IMPLEMENTADO";
}

string Sistema::login(const string email, const string senha) {
  vector<Usuario>::iterator it;
  for ( it = usuarios.begin(); it != usuarios.end(); it++ ) {
        if((it->email == email) && (it->senha == senha)){
          cout<<"Logado com ID "<< it->id<<endl;
          usuariosLogados.insert(pair<int, pair<string,string>>(it->id,make_pair("","")));
          cout<<usuariosLogados.size()<<endl;
          break;
        }else{
          cout<<"Falha no login."<<endl;
        }
  }
  return "login NÃO IMPLEMENTADO";
}

string Sistema::disconnect(int id) {
  map<int, pair<string, string>>::iterator it;
  cout<<usuariosLogados.size()<<endl;
  for ( it = usuariosLogados.begin(); it != usuariosLogados.end(); it++ ) {
    cout<<"Rodou uma vez";
    if((it->first == id)){
      cout<<"Deslogando ID "<< it->first<<endl;
      it=usuariosLogados.erase(it);
      break;
    }else{
      it++;
    }
  }
  return "disconnect NÃO IMPLEMENTADO";
}

string Sistema::create_server(int id, const string nome) {
  Servidor newServer;
  newServer.nome = nome;
  //newServer.usuarioDonoId=id;
  newServer.setUsuarioDonoId(id);
  newServer.getUsuarioDonoId();
  servidores.push_back(newServer);

  return "create_server NÃO IMPLEMENTADO";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if((it->getUsuarioDonoId() == id) && (it->nome == nome)){
      it->descricao=descricao;
      cout<<"Descricao adicionada!"<<endl;
      break;
    }else{
      cout<<"descricao ERRO!"<<endl;
    }
  }
  return "set_server_desc NÃO IMPLEMENTADO";
}

string Sistema::print() {
  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    cout<<it->getUsuarioDonoId()<<" tem servidor "<<it->nome<<" com desc "<<it->descricao<<endl;
  }
  return "set_server_invite_code NÃO IMPLEMENTADO";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if((it->getUsuarioDonoId() == id) && (it->nome == nome)){
      it->codigoConvite=codigo;
      cout<<"Código de convite do servidor "<< nome << "modificado!"<<endl;
      break;
    }else{
      cout<<"ERRO!"<<endl;
    }
  }
  return "set_server_invite_code NÃO IMPLEMENTADO";
}

string Sistema::list_servers(int id) {
  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    cout<<it->nome<<endl;
  }
  return "list_servers NÃO IMPLEMENTADO";
}

string Sistema::remove_server(int id, const string nome) {
  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if((it->getUsuarioDonoId() == id) && (it->nome == nome)){
      servidores.erase(it);
      cout<<"Servidor removido!"<<endl;
      break;
    }else{
      cout<<"descricao ERRO!"<<endl;
    }
  }
  return "remove_server NÃO IMPLEMENTADO";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
  vector<Servidor>::iterator it;
  for(it = servidores.begin(); it != servidores.end(); it++){
    if((it->nome == nome) && (it->codigoConvite == codigo)){
      
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
    if(it->nome == serverToSearch){
      
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
    if(it->nome == serverToSearch){

      cout<<it->canaisTexto[0].olharCanal()<<endl;

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
    if(it->nome == serverToSearch){
      
      CanalTexto newCanal;
      newCanal.mudarCanal(nome);
      it->canaisTexto.push_back(newCanal);
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
    if(it->nome == serverToSearch){
      for(int i=0; i<it->canaisTexto.size();i++){
        if(it->canaisTexto[i].olharCanal() == nome){
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
    if(it->nome == serverToSearch){
      for(int i=0; i<it->canaisTexto.size();i++){
        if(it->canaisTexto[i].olharCanal() == usuariosLogados.at(id).second){
          it->canaisTexto[i].adicionarMensagem(id, mensagem);
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
    if(it->nome == serverToSearch){
      for(int i=0; i<it->canaisTexto.size();i++){
        if(it->canaisTexto[i].olharCanal() == usuariosLogados.at(id).second){
          it->canaisTexto[i].lerMensagem();
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
