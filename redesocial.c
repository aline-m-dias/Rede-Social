#include <stdio.h>
#include <Stdlib.h>

#include "redesocial.h"
#include <string.h>

/*fun��o que faz a leitura dos dados de um usu�rio*/
void Ler (TUsuarios *user)
{
    printf ("\nDigite o seu nome: \n\n");
    fflush(stdin);
    fgets(user->nome, 100, stdin);

    printf ("\nDigite o seu email: \n\n");
    fflush (stdin);
    fgets(user->email, 200, stdin);

    printf("\nDigite o  seu login: \n\n");
    fflush (stdin);
    fgets(user->login, 50, stdin);

    printf("\nDigite a  sua senha: \n\n");
    fflush(stdin);
    fgets(user->senha, 50, stdin);

    printf ("\nDigite o dia de nascimento: \n\n");
    fflush(stdin);
    scanf("%d", &user->dataDeNascimento.dia);

    printf ("\nDigite o mes  de nascimento: \n\n");
    fflush(stdin);
    scanf("%d", &user->dataDeNascimento.mes);

    printf ("\nDigite o ano de nascimento: \n\n");
    fflush(stdin);
    scanf("%d", &user->dataDeNascimento.ano);
}
//fun��o que imprime todos os dados de um usu�rio
void Imprimir (TUsuarios user)
{

    printf ("\n\n Dados Usuarios: \n\n");
    printf("Nome: %s \n", user.nome );
    printf("Email: %s \n", user.email);
    printf ("Login: %s \n", user.login);
    printf ("Senha: %s \n", user.senha);
    printf ("Data de nascimento:\n\n");
    printf ("Dia : %d \n", user.dataDeNascimento.dia);
    printf ("Mes : %d \n", user.dataDeNascimento.mes);
    printf ("Ano: %d \n\n", user.dataDeNascimento.ano);
    printf ("Id: %d \n", user.ID);
}

/*fun��o que inicializa o campo indice da rede e a matriz relacionamento*/
void Iniciar(TRedeSocial *rede)
{
    rede->indice=0;

    for (int i=0; i<100; i++)
    {
        for (int j=0; j<100; j++)
        {
            rede->matriz[i][j]=0;
        }

    }


}
/*fun��o que cadrastra um usu�rio na rede social*/
void Cadrastar(TRedeSocial *rede, TUsuarios user)
{

    if (rede->indice <100)
    {
        user.ID= rede-> indice;
        rede->vetor[rede->indice]=user;
        rede->indice++;
        printf("\n\nMSG: Dados cadrastrados com sucesso!\n \n");

    }

}
/*imprime os dados de todos os usuarios no vetor da rede social*/
void Imprimir2 (TRedeSocial rede)
{

    for (int i=0; i<rede.indice; i++)
    {

        if (rede.vetor[i].ID != -1)
        {
            Imprimir(rede.vetor[i]);
        }

    }


}
/*fun��o que pesquisa um usuario na rede social e retorna o seu indice*/
int  Pesquisar(TRedeSocial rede, TUsuarios user)
{

    for(int i=0; i<rede.indice; i++)
    {
        if (strcmp(rede.vetor[i].nome, user.nome)==0)
        {

            return i;
        }

    }
    return -1;


}
/*fun��o que altera um usuario da rede social*/
void Alterar (TRedeSocial *rede, TUsuarios user, int indice)
{

    rede->vetor[indice]=user;

}
/*fun��o que exclui um usuario da rede social*/
void Excluir (int indice, TRedeSocial *rede )
{

    rede->vetor[indice].ID=-1;

    int coluna;

    for (coluna=0; coluna<rede->indice; coluna++)
    {
        if (rede->matriz[indice][coluna]==1)
        {
            rede->matriz[indice][coluna]=0;
            rede->matriz[coluna][indice]=0;
        }
    }

}


