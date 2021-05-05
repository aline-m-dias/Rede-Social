#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "exercicios.h"

/*menu principal*/
void MensagemMenu()
{

    system("cls");
    printf("\n\n\t**************************  MENU *****************************\n\n");
    printf("\n\t 1- MODULO 1: GERENCIAMENTO USUARIOS");
    printf("\n\t 2- MODULO 2: GERENCIAMENTO AMIZADES");
    printf("\n\t 3- SAIR \n\n");
}

/*sub-menu que realiza opera��es de gerenciamento do usuario*/
void MensagemSubMenu(int numeroModulo)
{

    system("cls");
    printf("\n\n\t************************MODULO %d: ****************************\n\n", numeroModulo);
    printf ("\n\t 1- CADRASTRAR");
    printf ("\n\t 2- PESQUISAR");
    printf ("\n\t 3- ALTERAR");
    printf ("\n\t 4- EXCLUIR");
    printf ("\n\t 5- IMPRIMIR");
    printf ("\n\t 6- SAIR");

}

/*sub-menu que realiza opera��es de gerenciamento de amizades*/
void MensagemSubMenu2(int numeroModulo)
{


    system("cls");
    printf("\n\n\t************************MODULO %d: ****************************\n\n", numeroModulo);
    printf ("\n\t 1- CADRASTRAR AMIZADE");
    printf ("\n\t 2- PESQUISAR AMIZADE");
    printf ("\n\t 3- EXCLUIR AMIZADE");
    printf ("\n\t 4- IMPRIMIR LISTA DE AMIGOS");
    printf ("\n\t 5-  CALCULAR O MAIOR NUMERO DE AMIGOS");
    printf ("\n\t 6-  CALCULAR A QUANTIDADE DE AMIGOS EM COMUM");
    printf ("\n\t 7-  PREENCHER A MATRIZ DE AMIGOS EM  COMUM");
    printf ("\n\t 8-  ENCONTRAR USUARIOS QUE NAO POSSUI AMIGOS EM COMUNS");
    printf ("\n\t 9-  SABER A RELA��O INDIRETA DE NIVEL 1 ");
    printf ("\n\t 10-  SABER A RELA��O INDIRETA DE NIVEL 2 ");
    printf ("\n\t 11-  SAIR ");

}



/*fun��o a qual faz chamada das opera��es de gerenciamento do usu�rio*/
void SubMenuModulo1(TRedeSocial *rede, TUsuarios user)
{

    int op;
    do
    {


        system("cls");
        MensagemSubMenu(1);
        printf("\n\nDigite uma op��o:\n\n");
        fflush(stdin);
        scanf("%d", &op);

        int i;
        switch (op)
        {
        case 1:
            system("cls");
            printf("\n\n MSG: digite os dados do usuario: \n\n");
            Ler(&user);
            Cadrastar(rede, user);
            printf("\n\n MSG: digite uma tecla para continuar \n\n");
            system("pause");
            break;
        case 2:
            system("cls");
            printf("\n\n MSG: Digite o nome do usu�rio que voc� deseja pesquisar.\n\n");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            i=Pesquisar(*rede,user);
            if (i>=0)
            {
                printf("\n\n MSG: usu�rio encontrado com sucesso!\n\n");
                Imprimir(rede->vetor[i]);
            }
            else
            {

                printf("\n\n MSG: usu�rio n�o est� cadrastrado!\n\n");
            }
            printf("\n\n MSG: digite uma tecla para continuar \n\n");
            system("pause");
            break;
        case 3:
            system("cls");
            printf("\n\n Digite o nome do usu�rio que voc� deseja alterar:\n\n");
            fflush(stdin);
            fgets(user.nome,100,stdin);
            i=Pesquisar(*rede,user);

            if (i>=0)
            {
                printf("\n\n MSG: Digite os dados para alterar:\n\n");
                Ler(&user);
                Alterar(rede,user,i);
                printf("\n\n MSG: Dados do usu�rio alterado com sucesso!\n\n");
            }
            else
            {
                printf("\n\n MSG: usu�rio pesquisado n�o est� cadrastrado.\n\n");
            }
            printf("\n\n MSG: digite uma tecla para continuar \n\n");
            system("pause");
            break;
        case 4:
            system("cls");
            printf("\n\n MSG: Digite o nome do usu�rio que deseja excluir:\n\n");
            fflush(stdin);
            fgets(user.nome,100,stdin);
            i=Pesquisar(*rede,user);

            if(i>=0)
            {
                Excluir(i, rede);
                printf("\n\n MSG: usu�rio excluido com sucesso!\n\n");
            }
            else
            {
                printf ("\n\n MSG: usu�rio pesquisado n�o estar cadrastrado\n\n");
            }
            printf("\n\n MSG: digite uma tecla para continuar \n\n");
            system("pause");
            break;

        case 5:
            system("cls");
            if(rede->indice>=0)
            {

                printf("\n\n MSG: Lista de usu�rios cadrastrados:\n\n");
                Imprimir2(*rede);
            }
            else
            {

                printf("\n\n MSG: n�o existem usu�rios cadrastrados.\n\n");
            }
            printf("\n\nMSG: digite uma tecla para continuar \n\n");
            system("pause");

            break;
        case 6:
            system("cls");
            printf("\n\n************** SAINDO DO MODULO!!! *************\n\n");
            printf("\n\n MSG: digite uma tecla para continuar \n\n");
            system("pause");
            break;
        default:
            system("cls");
            printf ("\n\n MSG: Op��o invalida! \n\n Digite uma opcao valida!\n\n");
            printf("\n\n MSG: digite uma tecla para continuar \n\n");
            system("pause");

        }

    }
    while(op!=6);

}

/*fun��o que faz chamada as opera��es referente ao gerenciamento de amizade*/
void SubMenuModulo2(TRedeSocial *rede, TUsuarios user)
{

    int op;


    do
    {

        system("cls");
        MensagemSubMenu2(2);
        printf("\n\n Digite a op��o que voc� deseja\n\n");
        fflush(stdin);
        scanf("%d", &op);

        int i;
        TUsuarios user2;
        int a, b;
        TUsuarios userA, userB;
        switch(op)
        {
        case 1:
            system("cls");
            printf ("\n\n MSG: digite o nome de um usuario:\n\n");
            fflush(stdin);
            fgets(user.nome,100, stdin);
            int nome1=Pesquisar(*rede, user);


            printf ("\n\n MSG: digite o nome de um usuario:\n\n");
            fflush(stdin);
            fgets(user.nome,100, stdin);

            int nome2=Pesquisar(*rede, user);


            CadrastarAmizade(rede,rede->vetor[nome1], rede->vetor[nome2]);

            printf("\n\n MSG: digite uma tecla para continuar \n\n");
            system("pause");
            break;

        case 2:
            system("cls");

            printf("\n\n MSG: Digite o  nome do  primeiro usu�rio que voc� deseja pesquisar.\n\n");
            fflush(stdin);
            fgets(userA.nome, 100, stdin);
            printf("\n\n MSG: Digite o nome do segundo usu�rio que voc� deseja pesquisar.\n\n");
            fflush(stdin);
            fgets(userB.nome, 100, stdin);

            i= PesquisarAmizade(*rede,userA,userB);

            if (i==1)
            {
                printf("\n\n MSG: Usu�rios s�o amigos na rede social. \n\n");
            }
            else
            {
                printf("\n\n MSG: Usu�rios n�o s�o amigos.\n\n");

            }
            printf("\n\n MSG: digite uma tecla para continuar \n\n");
            system("pause");
            break;

        case 3:

            system("cls");
            printf("\n\n MSG: Digite o nome do primeiro usu�rio :\n\n");
            fflush(stdin);
            fgets(userA.nome,100,stdin);
            printf("\n\n MSG: Digite o nome do segundo usu�rio :\n\n");
            fflush(stdin);
            fgets(userB.nome,100,stdin);
            i=PesquisarAmizade(*rede,userA, userB);

            if(i==1)
            {
                ExcluirAmizade(rede, userA, userB);

            }
            else
            {
                printf ("\n\n MSG: usu�rios pesquisados n�o s�o amigos!\n\n");
            }
            printf("\n\n MSG: digite uma tecla para continuar \n\n");
            system("pause");
            break;

        case 4:

            system("cls");
            printf("\n\nDigite o nome do usuario que deseja imprimir a lista de amigos:\n\n");
            fflush(stdin);
            fgets(user.nome,100,stdin);
            printf("\n\n MSG: Lista de amigos: \n\n");
            ImprimirListaAmigos(*rede, user);
            printf("\n\nMSG: digite uma tecla para continuar \n\n");
            system("pause");
            break;

        case 5:

            system("cls");
            int amigo;
            amigo= MaiorNumeroAmigos(*rede);
            printf("\n\n MSG: ID do usu�rio com maior numero de amigos: %d\n\n", amigo);
            printf("\n\nMSG: digite uma tecla para continuar \n\n");
            system("pause");
            break;

        case 6:

            system("cls");
            int amigosComuns;
            printf("\n\n MSG: digite o  id de um usu�rio que deseja saber seus amigos em comum:\n");
            fflush(stdin);
            scanf("%d", &user.ID);
            printf("\n\nMSG: digite o  id de outro usu�rio que deseja saber seus amigos em comum:\n");
            fflush(stdin);
            scanf("%d", &user2.ID);
            amigosComuns=QuantidadeAmigosEmComum(*rede, user.ID, user2.ID);
            printf("\n\n MSG: Quantidade de amigos em comum  com os usuarios digitados: %d\n\n", amigosComuns);
            printf("\n\nMSG: digite uma tecla para continuar \n\n");
            system("pause");
            break;

        case 7:
            system("cls");
            CalculaMatrizAmigosEmComum(rede);
            printf("\n\n MSG: matriz de amigos em comuns preenchida!\n\n");
            printf("\n\nMSG: digite uma tecla para continuar \n\n");
            system("pause");
            break;

        case 8:
            system("cls");
            printf("\n\nMSG: digite o nome do primeiro usuario.\n\n");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            printf("\n\nMSG: digite o nome do segundo usuario.\n\n");
            fflush(stdin);
            fgets(user2.nome, 100, stdin);
            NenhumAmigoEmComum(rede,user, user2 );
             printf("MSG: Id dos usu�rios sem amigos em comum:\n\n");
            for(int i=0; i<2; i++)
            {
                printf("%d -",rede->pessoasSemAmigosEmComum[i]);
            }
            printf("\n\nMSG: digite uma tecla para continuar \n\n");
            system("pause");
            break;

        case  9:
            system("cls");
            printf("\n\nMSG: digite o id do primeiro usuario.\n\n");
            fflush(stdin);
            scanf("%d", &a);
            printf("\n\nMSG: digite o id do segundo usuario.\n\n");
            fflush(stdin);
            scanf("%d", &b);
            int id=RelacaoAmizadeIndireta(*rede,rede->vetor[a],rede->vetor[b] );
            if (id>=0)
            {
                printf("\n\nMSG: Rela��o indireta de nivel 1: Id do usuario intermedi�rio: %d\n\n", id);
            }
            else
            {
                printf("\n\nMSG: n�o existe us�rio intermedi�rio.\n\n");
            }
            system("pause");
            break;
        case 10:
            system("cls");
            printf("\n\nMSG: digite o id do primeiro usuario.\n\n");
            fflush(stdin);
            scanf("%d", &a);
            printf("\n\nMSG: digite o id do segundo usuario.\n\n");
            fflush(stdin);
            scanf("%d", &b);
            RelacaoAmizadeIndiretaNivel2(*rede, rede->vetor[a], rede->vetor[b],&a,&b);
            printf("\n\nMSG: Rela��o indireta de nivel 2:\n\n");
            if (a&&b !=-1)
            {
                printf("\n\nMSG: ID dos usu�rios interm�diarios: %d - %d\n\n", a,b);
            }
            else
            {
                printf("\n\nMSG: n�o existe us�rio intermedi�rio\n\n");
            }
            system("pause");
            break;

        case 11:

            system("cls");
            printf("\n\n************** SAINDO DO MODULO!!! *************\n\n");
            printf("\n\n MSG: digite uma tecla para continuar \n\n");
            system("pause");
            break;

        default:
            system("cls");
            printf ("\n\n MSG: Op��o invalida! \n\n Digite uma opcao valida!\n\n");
            printf("\n\n MSG: digite uma tecla para continuar \n\n");
            system("pause");

        }
    }
    while(op != 11);

}









