#ifndef EXERCICIOS_H_INCLUDED
#define EXERCICIOS_H_INCLUDED

int MaiorNumeroAmigos(TRedeSocial rede);
int QuantidadeAmigosEmComum(TRedeSocial rede,int id1, int id2);
void CalculaMatrizAmigosEmComum(TRedeSocial *rede);
void NenhumAmigoEmComum(TRedeSocial *rede, TUsuarios userA, TUsuarios userB);
int RelacaoAmizadeIndireta(TRedeSocial rede,TUsuarios userA, TUsuarios userB);
void RelacaoAmizadeIndiretaNivel2(TRedeSocial rede, TUsuarios userA, TUsuarios userB, int *a, int *b);


#endif // EXERCICIOS_H_INCLUDED
