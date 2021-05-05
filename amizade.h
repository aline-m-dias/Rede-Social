#ifndef AMIZADE_H_INCLUDED
#define AMIZADE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "redesocial.h"

void CadrastarAmizade (TRedeSocial *rede, TUsuarios userA, TUsuarios userB);
int PesquisarAmizade(TRedeSocial rede, TUsuarios userA, TUsuarios userB);
void ExcluirAmizade(TRedeSocial *rede, TUsuarios userA, TUsuarios userB);
void ImprimirListaAmigos(TRedeSocial rede, TUsuarios user);

#endif // AMIZADE_H_INCLUDED
