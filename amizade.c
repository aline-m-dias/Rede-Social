#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

/*função que cadrastra a amizade entre dois usuarios*/
void CadrastarAmizade(TRedeSocial *rede, TUsuarios userA, TUsuarios userB)
{

    int i, j;
    i= Pesquisar(*rede,userA);
    j=Pesquisar(*rede, userB);

    if (i>=0 && j>=0)
    {
        rede->matriz[i][j]=1;
        rede->matriz[j][i]=1;
        printf("\n\n MSG: Amizade cadrastrada com sucesso!\n\n");
    }
    else
    {

        printf("\n\n MSG: Um dos usuários não está  cadrastrado na rede social.\n\n");
    }

}
/*função que pesquisa se dois usuários informados são amigos*/
int PesquisarAmizade(TRedeSocial rede, TUsuarios userA, TUsuarios userB)
{

    int i, j;
    i=Pesquisar(rede,userA);
    j=Pesquisar(rede, userB);

    if (i>=0 && j>=0)
    {

        if (rede.matriz[i][j]==1 && rede.matriz [j][i] == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
/*função que exclui a amizade entre dois usuarios*/
void ExcluirAmizade(TRedeSocial *rede, TUsuarios userA, TUsuarios userB)
{


    int i, j;
    i=Pesquisar(*rede, userA);
    j=Pesquisar(*rede, userB);

    if (i>=0 && j>=0)
    {
        if (rede->matriz[i][j]==1)
        {
            rede->matriz[i][j]=0;
            rede->matriz[j][i]=0;
            printf("\n\n MSG: Amizade  excluida com sucesso!\n\n");
        }

    }
}
/*função que imprime a lista de amigos de um usuario informado*/
void ImprimirListaAmigos(TRedeSocial rede, TUsuarios user)
{

    int indi;
    indi=Pesquisar(rede,user);

    if (indi>=0)
    {

        for (int linha=0; linha<rede.indice; linha++)
        {
            if (rede.matriz[indi][linha]==1)
            {

                Imprimir(rede.vetor[linha]);
            }


        }
    }



}
