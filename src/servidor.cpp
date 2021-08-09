#include "servidor.h"
#include <istream>
#include <ostream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void Servidor:: setUsuarioDonoId(int i)
{
    usuarioDonoId=i;
}
int Servidor:: getUsuarioDonoId()
{
    return usuarioDonoId;
}