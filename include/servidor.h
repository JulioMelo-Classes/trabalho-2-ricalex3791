#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <vector>
#include <iostream>
#include "canaltexto.h"

/*Cp2 e Cp1 ok*/
class Servidor{
	/*
		TODO implementação dos atributos e métodos
	*/
	private:
		int usuarioDonoId; //<! o ID do dono do servidor
		std::string nome; //<! o nome do servidor
		std::string descricao; //<! a descrição do servidor
		std::string codigoConvite; //<! o codigo de convite do servidor
		std::vector<CanalTexto> canaisTexto; //<! um vetor com todos os canais do servidor
		std::vector<int> participantesIDs; //<! um vetor com os IDs dos usuarios conectados ao servidor
		
	public:

		/*! Adiciona um novo canal de texto ao servidor.
				@param nome o nome do canal criado
		*/
		void addCanalTexto(const std::string nome);

		/*! Imprime o nome de todos os canais de texto no servidor.
		*/
		void listCanaisTexto();

		/*! Verifica quantos canais de texto existem no servidor.
				@return uma int contendo a quantidade de canais de texto
		*/
		int olharCanaisTextoTamanho();

		/*! Acessa o nome de um canal de texto
				@param n o index do canal de texto a ser acessado
				@return uma string com o nome do canal
		*/
		std::string accessCanalTextoNome(int n);

		/*! Escreve uma mensagem em um canal de texto
				@param n o index do canal de texto a ser acessado
				@param id o ID do usuario escrevendo a mensagem
				@param mensagem a mensagem escrita
				@param datahora a data e hora em que a mensagem foi escrita
		*/
		void escreverMessagem(int n, int id, const std::string mensagem, const std::string datahora);

		/*! Exibe as mensagens escritas em um canal de texto
				@param n o index do canal de texto a ser acessado
		*/
		void accessMessages(int n);

		/*! Adiciona o ID de um usuario a lista de participantes do servidor
				@param n o ID do usuario a ser adicionado
		*/
		void addID(int n);

		/*! Verifica quantos usuarios estão conectados ao servidor
				@return uma int contendo a quantidade de usuarios
		*/
		int checkIDSize();

		/*! Acessa o ID de usuarios na lista de participantes
				@return uma int contendo o ID do usuario
		*/
		int checkID(int n);

		/*! Get e Set para as variaveis privadas da classe
		*/
		void setUsuarioDonoId(int i);
		int getUsuarioDonoId();

		void setNome(const std::string n);
		std::string getNome();

		void setDescricao(const std::string d);
		std::string getDescricao();

		void setCodigoConvite(const std::string c);
		std::string getCodigoConvite();


		
};

#endif
