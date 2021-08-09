#include "canalTexto.h"
#include <istream>
#include <ostream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void CanalTexto:: mudarCanalNome(const string name)
{
  nome=name;
}
string CanalTexto:: olharCanal()
{
  return nome;
}
void CanalTexto:: adicionarMensagem(int id, const std::string conteudo, const std::string data)
{
  Mensagem newMessage;
  newMessage.enviadaPor = id;
  newMessage.conteudo = conteudo;
  newMessage.dataHora = data;
  mensagens.push_back(newMessage);
}
void CanalTexto:: lerMensagem()
{
  for(unsigned int i=0; i<mensagens.size();i++){
    cout<<mensagens[i].dataHora<<":"<<mensagens[i].conteudo<<endl;
  }
}