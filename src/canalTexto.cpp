#include "canalTexto.h"
#include <istream>
#include <ostream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string CanalTexto:: mudarCanal(const string name)
{
  nome=name;
  return "dEU CERTO";
}
string CanalTexto:: olharCanal()
{
  return nome;
}
string CanalTexto:: adicionarMensagem(int id, const std::string conteudo)
{
  Mensagem newMessage;
  newMessage.enviadaPor = id;
  newMessage.conteudo = conteudo;
  mensagens.push_back(newMessage);
  return "ok";
}
string CanalTexto:: lerMensagem()
{
  for(int i=0; i<mensagens.size();i++){
    cout<<mensagens[i].conteudo<<endl;
  }
  return "ok";
}