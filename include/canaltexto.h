#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include "mensagem.h"
#include <vector>

/*
Cp2 ok
*/
class CanalTexto{
	/*
		TODO implementação dos atributos e métodos
	*/
	private:
		std::string nome; //<! o nome do canal de texto
		std::vector<Mensagem> mensagens; //<! um vetor com as mensagens enviadas no canal de texto
	public:
		/*! Altera o nome do canal de texto
				@param name o nome a ser utilizado
		*/
		void mudarCanalNome(const std::string name);

		/*! Adiciciona uma mensagem ao canal de texto.
				@param id o ID do usuario escrevendo a mensagem
				@param conteudo a mensagem escrita
				@param datahora a data e hora em que a mensagem foi escrita
		*/
		void adicionarMensagem(int id, const std::string conteudo, const std::string datahora);

		/*! Exibe as mensagens escritas no canal de texto.
		*/
		void lerMensagem();

		/*! Verifica o nome do canal de texto.
				@return uma string com o nome do canal de texto
		*/
		std::string olharCanal();
};

#endif
