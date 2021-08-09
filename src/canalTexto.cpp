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
void CanalTexto:: adicionarMensagem(int id, const std::string conteudo)
{
  Mensagem newMessage;
  newMessage.enviadaPor = id;
  newMessage.conteudo = conteudo;
  mensagens.push_back(newMessage);
}
void CanalTexto:: lerMensagem()
{
  for(int i=0; i<mensagens.size();i++){
    cout<<mensagens[i].conteudo<<endl;
  }
}