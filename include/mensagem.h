#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

class Mensagem{
	public:
        std::string dataHora; //<! data e hora em que a mensagem foi escrita
        int enviadaPor; //<! ID do usuario que escreveu a mensagem
		std::string conteudo; //<! a mensagem
};

#endif
