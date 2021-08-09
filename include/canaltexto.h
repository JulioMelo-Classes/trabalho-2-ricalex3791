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
		void mudarCanalNome(const std::string name);
		void adicionarMensagem(int id, const std::string conteudo);
		void lerMensagem();
		std::string olharCanal();
};

#endif
