#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <vector>
#include <iostream>
#include "canaltexto.h"

class Servidor{
	/*
		TODO implementação dos atributos e métodos
	*/
	private:
		int usuarioDonoId;
		std::string nome;
		std::string descricao;
		std::string codigoConvite;
		std::vector<CanalTexto> canaisTexto;
		
	public:
		
		
		std::vector<int> participantesIDs;

		void addCanalTexto(const std::string nome);
		void listCanaisTexto();
		int olharCanaisTextoTamanho();
		std::string accessCanalTextoNome(int n);
		void escreverMessagem(int n, int id, const std::string mensagem);
		void accessMessages(int n);

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
