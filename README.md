# trabalho-2-ricalex3791

## Para compilar com CMake no Windows PowerShell

O arquivo CMakeList.txt já está configurado, então pode seguir os seguintes passos para compilar o projeto pelo powershell.
Após abrir o PowerShell e ir para o diretório onde os arquivos estão, execute os comandos

```console
mkdir build
cd build
cmake ..
cmake --build .
```

Isso irá criar uma pasta **Debug** e criar um executavel **"concordo.exe"** dentro dela.

## Executando o programa e utilizando os testes

Ainda no prompt de comando, execute um "cd .." para voltar para o diretório padrão do projeto. Daqui você pode executar os seguintes comandos para rodar o sistema e digitar os inputs manualmente.
```console
./build/Debug/concordo.exe
```

No entanto, se você quiser utilizar um arquivo de texto com uma lista de comandos, ele pode ser executado da seguinte forma:

```console
./build/Debug/concordo.exe ./data/[arquivo de texto]
```
... substituindo o [arquivo de texto] pelo nome de alguns dos arquivos na pasta /data.
O aquivo script_correto.txt possui uma lista de comandos sem nenhum erro, assim tudo será executado sem o programa impedir nenhuma ação.
O arquivo script_erros.txt comete vários erros, mas continua tentando até o fim.

## Limitações
Na função que mostra os usuarios participantes em um servidor, este programa mostra apenas o ID dos usuarios, e não o seu nome.