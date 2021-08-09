#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include "sistema.h"
#include "executor.h"
#include <filesystem>

using namespace std;

int main(int argc, char *argv[]) {
  // inicialização do sistema
  Sistema sistema;
  Executor executor(sistema);

  
  if(argc == 1){
    cout<<argc<<endl;
    // o executor recebe o cin e o cout. Ele os utilizará para ler as linhas
    // de comando, executar o método correto em "sistema" e exibir as mensagens
    executor.iniciar(cin, cout);
    return 0;
  }

  fstream file;
  string filename = argv[1];
  file.open(filename, ios::in);
  if(!file){
    cout<<"Erro ao abrir arquivo";
    return 0;
  }else{
    cout<<">>> Lendo arquivos de inputs "<< filename << ". Por favor aguarde." << endl;
    cout<<"------------------------------------------------------------"<< endl;

    // o executor recebe o file e o cout. Ele os utilizará para ler as linhas
    // de comando, executar o método correto em "sistema" e exibir as mensagens
    executor.iniciar(file, cout);
  }  

  return 0;
}
