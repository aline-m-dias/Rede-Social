#include <stdio.h>
#include <stdlib.h>

#include "redesocial.h"
#include "interface.h"
#include "amizade.h"
#include "exercicios.h"
#include <locale.h>

int main()
{

    setlocale (LC_ALL, "Portuguese");

    TUsuarios user;
    TRedeSocial rede;

    Iniciar(&rede);

    /*chamada do menu principal e sub-menus*/
    int op;
    do
    {
        system("clean");
        MensagemMenu();
        printf ("\n\n Digite a opção que você deseja:\n\n");
        fflush(stdin);
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            SubMenuModulo1(&rede,user);
            break;
        case 2:
            system("cls");
            SubMenuModulo2(&rede, user);
            break;
        case 3:
            system("cls");
            printf("\n\n ***************MSG: ENCERRANDO O PROGRAMA! **************\n\n");
            break;
        default:
            system("cls");
            printf("\n\n MSG: Digite uma opção válida.\n\n");
            system("pause");
        }

    }
    while (op !=3);


    return 0;
}
