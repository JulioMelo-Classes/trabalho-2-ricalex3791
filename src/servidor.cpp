#include "servidor.h"
#include <istream>
#include <ostream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void Servidor:: addCanalTexto(const std::string nome)
{
    CanalTexto newCanal;
    newCanal.mudarCanalNome(nome);
    canaisTexto.push_back(newCanal);
}
void Servidor:: listCanaisTexto()
{
    for(int i = 0;i<canaisTexto.size();i++){
        cout<<canaisTexto[i].olharCanal()<<endl;
    }
}
int Servidor:: olharCanaisTextoTamanho()
{
    int size=0;
    for(int i=0; i<canaisTexto.size();i++){
        size++;
    }
    return size;
}
string Servidor:: accessCanalTextoNome(int n)
{
    return canaisTexto[n].olharCanal();
}
void Servidor:: escreverMessagem(int n, int id, const std::string mensagem, const std::string datahora)
{
    canaisTexto[n].adicionarMensagem(id, mensagem, datahora);
}
void Servidor:: accessMessages(int n)
{
    canaisTexto[n].lerMensagem();
}

void Servidor:: addID(int n)
{
    participantesIDs.push_back(n);
}

int Servidor:: checkIDSize()
{
    int size=0;
    for(int i=0; i<participantesIDs.size(); i++){
        size++;
    }
    return size;
}

int Servidor:: checkID(int n)
{
    return participantesIDs[n];
}

void Servidor:: setUsuarioDonoId(int i)
{
    usuarioDonoId=i;
}
int Servidor:: getUsuarioDonoId()
{
    return usuarioDonoId;
}

void Servidor:: setNome(const std::string n)
{
    nome=n;
}
string Servidor:: getNome()
{
    return nome;
}

void Servidor:: setDescricao(const std::string d)
{
    descricao=d;
}
string Servidor:: getDescricao()
{
    return descricao;
}

void Servidor:: setCodigoConvite(const std::string c)
{
    codigoConvite=c;
}
string Servidor:: getCodigoConvite()
{
    return codigoConvite;
}