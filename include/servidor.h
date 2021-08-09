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
		
	public:
		std::string nome;
		std::string descricao;
		std::string codigoConvite;
		std::vector<CanalTexto> canaisTexto;
		std::vector<int> participantesIDs;
		void setUsuarioDonoId(int i);
		int getUsuarioDonoId();


		
};

#endif
