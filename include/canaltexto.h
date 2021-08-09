#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include "mensagem.h"
#include <vector>

class CanalTexto{
	/*
		TODO implementação dos atributos e métodos
	*/
	private:
		std::string nome;
		std::vector<Mensagem> mensagens;
	public:
		std::string mudarCanal(const std::string name);
		std::string olharCanal();
		std::string adicionarMensagem(int id, const std::string conteudo);
		std::string lerMensagem();
};

#endif
