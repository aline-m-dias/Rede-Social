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

/*sub-menu que realiza operações de gerenciamento do usuario*/
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

/*sub-menu que realiza operações de gerenciamento de amizades*/
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
    printf ("\n\t 9-  SABER A RELAÇÃO INDIRETA DE NIVEL 1 ");
    printf ("\n\t 10-  SABER A RELAÇÃO INDIRETA DE NIVEL 2 ");
    printf ("\n\t 11-  SAIR ");

}



/*função a qual faz chamada das operações de gerenciamento do usuário*/
void SubMenuModulo1(TRedeSocial *rede, TUsuarios user)
{

    int op;
    do
    {


        system("cls");
        MensagemSubMenu(1);
        printf("\n\nDigite uma opção:\n\n");
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
            printf("\n\n MSG: Digite o nome do usuário que você deseja pesquisar.\n\n");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            i=Pesquisar(*rede,user);
            if (i>=0)
            {
                printf("\n\n MSG: usuário encontrado com sucesso!\n\n");
                Imprimir(rede->vetor[i]);
            }
            else
            {

                printf("\n\n MSG: usuário não está cadrastrado!\n\n");
            }
            printf("\n\n MSG: digite uma tecla para continuar \n\n");
            system("pause");
            break;
        case 3:
            system("cls");
            printf("\n\n Digite o nome do usuário que você deseja alterar:\n\n");
            fflush(stdin);
            fgets(user.nome,100,stdin);
            i=Pesquisar(*rede,user);

            if (i>=0)
            {
                printf("\n\n MSG: Digite os dados para alterar:\n\n");
                Ler(&user);
                Alterar(rede,user,i);
                printf("\n\n MSG: Dados do usuário alterado com sucesso!\n\n");
            }
            else
            {
                printf("\n\n MSG: usuário pesquisado não está cadrastrado.\n\n");
            }
            printf("\n\n MSG: digite uma tecla para continuar \n\n");
            system("pause");
            break;
        case 4:
            system("cls");
            printf("\n\n MSG: Digite o nome do usuário que deseja excluir:\n\n");
            fflush(stdin);
            fgets(user.nome,100,stdin);
            i=Pesquisar(*rede,user);

            if(i>=0)
            {
                Excluir(i, rede);
                printf("\n\n MSG: usuário excluido com sucesso!\n\n");
            }
            else
            {
                printf ("\n\n MSG: usuário pesquisado não estar cadrastrado\n\n");
            }
            printf("\n\n MSG: digite uma tecla para continuar \n\n");
            system("pause");
            break;

        case 5:
            system("cls");
            if(rede->indice>=0)
            {

                printf("\n\n MSG: Lista de usuários cadrastrados:\n\n");
                Imprimir2(*rede);
            }
            else
            {

                printf("\n\n MSG: não existem usuários cadrastrados.\n\n");
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
            printf ("\n\n MSG: Opção invalida! \n\n Digite uma opcao valida!\n\n");
            printf("\n\n MSG: digite uma tecla para continuar \n\n");
            system("pause");

        }

    }
    while(op!=6);

}

/*função que faz chamada as operações referente ao gerenciamento de amizade*/
void SubMenuModulo2(TRedeSocial *rede, TUsuarios user)
{

    int op;


    do
    {

        system("cls");
        MensagemSubMenu2(2);
        printf("\n\n Digite a opção que você deseja\n\n");
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

            printf("\n\n MSG: Digite o  nome do  primeiro usuário que você deseja pesquisar.\n\n");
            fflush(stdin);
            fgets(userA.nome, 100, stdin);
            printf("\n\n MSG: Digite o nome do segundo usuário que você deseja pesquisar.\n\n");
            fflush(stdin);
            fgets(userB.nome, 100, stdin);

            i= PesquisarAmizade(*rede,userA,userB);

            if (i==1)
            {
                printf("\n\n MSG: Usuários são amigos na rede social. \n\n");
            }
            else
            {
                printf("\n\n MSG: Usuários não são amigos.\n\n");

            }
            printf("\n\n MSG: digite uma tecla para continuar \n\n");
            system("pause");
            break;

        case 3:

            system("cls");
            printf("\n\n MSG: Digite o nome do primeiro usuário :\n\n");
            fflush(stdin);
            fgets(userA.nome,100,stdin);
            printf("\n\n MSG: Digite o nome do segundo usuário :\n\n");
            fflush(stdin);
            fgets(userB.nome,100,stdin);
            i=PesquisarAmizade(*rede,userA, userB);

            if(i==1)
            {
                ExcluirAmizade(rede, userA, userB);

            }
            else
            {
                printf ("\n\n MSG: usuários pesquisados não são amigos!\n\n");
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
            printf("\n\n MSG: ID do usuário com maior numero de amigos: %d\n\n", amigo);
            printf("\n\nMSG: digite uma tecla para continuar \n\n");
            system("pause");
            break;

        case 6:

            system("cls");
            int amigosComuns;
            printf("\n\n MSG: digite o  id de um usuário que deseja saber seus amigos em comum:\n");
            fflush(stdin);
            scanf("%d", &user.ID);
            printf("\n\nMSG: digite o  id de outro usuário que deseja saber seus amigos em comum:\n");
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
             printf("MSG: Id dos usuários sem amigos em comum:\n\n");
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
                printf("\n\nMSG: Relação indireta de nivel 1: Id do usuario intermediário: %d\n\n", id);
            }
            else
            {
                printf("\n\nMSG: não existe usário intermediário.\n\n");
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
            printf("\n\nMSG: Relação indireta de nivel 2:\n\n");
            if (a&&b !=-1)
            {
                printf("\n\nMSG: ID dos usuários intermédiarios: %d - %d\n\n", a,b);
            }
            else
            {
                printf("\n\nMSG: não existe usário intermediário\n\n");
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
            printf ("\n\n MSG: Opção invalida! \n\n Digite uma opcao valida!\n\n");
            printf("\n\n MSG: digite uma tecla para continuar \n\n");
            system("pause");

        }
    }
    while(op != 11);

}









