#ifndef REDESOCIAL_H_INCLUDED
#define REDESOCIAL_H_INCLUDED

#include <stdio.h>
#include <string.h>

typedef struct data
{
    int dia;
    int mes;
    int ano;
} TData;

typedef struct usuarios
{
    char nome[100];
    char email[200];
    char login[50];
    char senha[50];
    TData dataDeNascimento;
    int ID;

} TUsuarios;

typedef struct redeSocial
{
    TUsuarios vetor[100];
    int matriz[100][100];
    int matrizAmigosEmComum[100][100];
    int pessoasSemAmigosEmComum[2];
    int indice;

} TRedeSocial;

void Ler (TUsuarios *user);
void Imprimir (TUsuarios user);
void Iniciar (TRedeSocial *rede);
void Cadrastar(TRedeSocial *rede, TUsuarios user);
void Imprimir2(TRedeSocial rede);
int  Pesquisar(TRedeSocial rede, TUsuarios user);
void Alterar (TRedeSocial *rede, TUsuarios user, int indice);
void Excluir (int indice, TRedeSocial *rede );


#endif // REDESOCIAL_H_INCLUDED
