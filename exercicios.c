#include<stdio.h>
#include<stdlib.h>
#include "redesocial.h"
#include "interface.h"

/*função que o id do usuário com maior numero de amigos*/
int MaiorNumeroAmigos(TRedeSocial rede)
{

    int cont=0;
    int maiorNumero=0;
    int indice=-1;
    for (int linha =0; linha<=rede.indice; linha++)
    {
        for(int coluna=0; coluna<=rede.indice; coluna++)
        {
            if (rede.matriz[linha][coluna]==1)
            {
                cont++;
            }
        }

        if (cont>maiorNumero)
        {
            maiorNumero=cont;
            indice=linha;
        }

        cont=0;

    }

    return indice;


}

/*função que calcula a quantidade de amigos em comum entre dois usuarios que não são amigos*/
int QuantidadeAmigosEmComum(TRedeSocial rede, int id1, int id2)
{

    int amigosComuns=0;
    for (int coluna=0; coluna<=rede.indice; coluna ++)
    {

        if (rede.matriz[coluna][id1] == 1 && rede.matriz[coluna][id2]==1)
        {

            amigosComuns++;
        }
    }

    return amigosComuns;

}
/*função que calcula a  matriz de amigos em comum*/
void CalculaMatrizAmigosEmComum(TRedeSocial *rede)
{

    for (int linha=0; linha<=rede->indice-1; linha++)
    {

        for(int coluna=0; coluna<=rede->indice-1; coluna++)
        {

            rede->matrizAmigosEmComum[linha][coluna]= QuantidadeAmigosEmComum(*rede, linha,coluna);
        }

    }

}

/* função que encontra dois usuários da rede social que não tenham nenhum amigo em comum
e registre-os no módulo da rede social.*/
void NenhumAmigoEmComum(TRedeSocial *rede, TUsuarios userA, TUsuarios userB )
{
    int i,j;
    int cont=-1;
    i=Pesquisar(*rede, userA);
    j=Pesquisar(*rede,userB);

    if(i>=0 && j>=0){

        cont=QuantidadeAmigosEmComum(*rede,i, j );
        if(cont==0)
        {
            rede->pessoasSemAmigosEmComum[0]=rede->vetor[i].ID;
            rede->pessoasSemAmigosEmComum[1]=rede->vetor[j].ID;

        }
        else
        {
            printf("\n\nMSG: usuarios possuem amigos em comum.\n\n");
        }

    }


}
/*função que calcula a relação de amizade indireta de nivel 1*/
int RelacaoAmizadeIndireta(TRedeSocial rede, TUsuarios userA, TUsuarios userB)
{

     int i, j;
     i=Pesquisar(rede, userA);
     j=Pesquisar(rede, userB);
     int cont=-1;

     if (i>=0 && j>=0){

       cont=PesquisarAmizade(rede,userA,userB);

       if (cont == 0){

            if (QuantidadeAmigosEmComum(rede, userA.ID, userB.ID) !=0){

                for(int coluna=0; coluna<rede.indice; coluna++){


                    if ( rede.matriz[userA.ID][coluna]==1 && rede.matriz[userB.ID][coluna]==1){
                        return coluna;
                    }


                }

            }
       }
     }



    return -1;

}
/*função que calcula a relação de amizade indireta de nivel 2*/
void RelacaoAmizadeIndiretaNivel2(TRedeSocial rede, TUsuarios userA, TUsuarios userB, int *a, int *b)
{

    int i, j;
    i=Pesquisar(rede,userA);
    j=Pesquisar(rede, userB);

    if (i>=0 && j>=0 ){

        int amigo= PesquisarAmizade(rede,userA,userB);

        if (amigo==0){


                for(int coluna=0; coluna<rede.indice; coluna++){

                    if(rede.matriz[userA.ID][coluna] == 1){
                        *a=coluna;

                    }
                    if(rede.matriz[userB.ID][coluna]==1){
                        *b=coluna;
                    }

                }


        }


    }


}
