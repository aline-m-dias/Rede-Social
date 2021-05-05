#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "redesocial.h"

void  MensagemMenu();
void  MensagemSubmenu(int numModulo);
void SubMenuModulo1(TRedeSocial *rede,TUsuarios user);
void SubMenuModulo2(TRedeSocial *rede,TUsuarios user);
void SubMenuModulo3(TRedeSocial *rede,TUsuarios user);
#endif // INTERFACE_H_INCLUDED
