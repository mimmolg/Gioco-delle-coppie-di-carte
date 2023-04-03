#include "header.h"
#include "functions.c"
int main()
{
    bool exit=false;/*Flag di uscita for*/
    int k;
    Carta mazzo[40]= /*Dichiarazione del mazzo di carte*/
    {{1,denari,0},{2,denari,0},{3,denari,0},{4,denari,0},{5,denari,0},
    {6,denari,0},{7,denari,0},{8,denari,0},{9,denari,0},{10,denari,0},
    {1,coppe,0},{2,coppe,0},{3,coppe,0},{4,coppe,0},{5,coppe,0},
    {6,coppe,0},{7,coppe,0},{8,coppe,0},{9,coppe,0},{10,coppe,0},
    {1,bastoni,0},{2,bastoni,0},{3,bastoni,0},{4,bastoni,0},{5,bastoni,0},
    {6,bastoni,0},{7,bastoni,0},{8,bastoni,0},{9,bastoni,0},{10,bastoni,0},
    {1,spade,0},{2,spade,0},{3,spade,0},{4,spade,0},{5,spade,0},
    {6,spade,0},{7,spade,0},{8,spade,0},{9,spade,0},{10,spade,0}};

    char giocatore_uno[20],giocatore_due[20];/*array dove vengono salvati i nomi dei due giocatori*/
    const int n_carte=40;
    Carta *pcarta;
    pcarta=&mazzo[0];
    int n_mix=0,rand_start_play=0,i=0,j=0,pnt_primo=0,pnt_sec=0; //i posizione prima carta;j posizione seconda carta;rand_start_play chi inizia per prima il gioco;
    srand( time(NULL) );
    printf("inserire nome del primo giocatore :\n");
    gets(giocatore_uno);
    printf("inserire nome del secondo giocatore :\n");
    gets(giocatore_due);
    rand_start_play=1+rand()%2; //genera un numero casuale tra 1 e 2 per decidere chi inizia il gioco
    if(rand_start_play==1){
        printf("Il primo giocatore sara':\n%s",giocatore_uno);
        printf("\n%s Quante volte vuoi mischiare il mazzo?\n",giocatore_uno);
        scanf("%d",&n_mix);
    }
    else{
        printf("il primo giocatore sara':\n%s",giocatore_due);
        printf("\n%s Quante volte vuoi mischiare il mazzo?\n",giocatore_due);
        scanf("%d",&n_mix);
    }
    mix_cards(mazzo,n_carte,n_mix); //Mischia il mazzo di carte
    do{
            vismixdeck(mazzo,pcarta); //Visualizziamo ogni volta l'elenco delle carte
            if(rand_start_play==1){//cioe' inizia il giocatore uno
            printf("%s scegli la posizione della prima Carta Da Scoprire :\n",giocatore_uno);/*Scelta carta per il giocatore 1*/
            scelta_carta(mazzo,&i);
            printf("%s scegli la posizione della seconda Carta Da Scoprire :\n",giocatore_uno);
            scelta_carta(mazzo,&j);
            }else{//altrimenti inizia il giocatore 2
            printf("%s scegli la posizione della prima Carta Da Scoprire :\n",giocatore_due);/*Scelta carta per il giocatore 2*/
            scelta_carta(mazzo,&i);
            printf("%s scegli la posizione della seconda Carta Da Scoprire :\n",giocatore_due);
            scelta_carta(mazzo,&j);
            }
        if(mazzo[i].valore==mazzo[j].valore){ //Confrontiamo il valore delle due carte
            printf("GIUSTO LE DUE CARTE SONO UGUALI RICEVI UN PUNTO !!!!\n");
            if(rand_start_play==1){
                printf("COMPLIMENTI %s RICEVI UN PUNTO\n",giocatore_uno);
                pnt_primo++;
            }else{
                printf("COMPLIMENTI %s RICEVI UN PUNTO\n",giocatore_due);
                pnt_sec++;
        }
        }else{
                printf("LE DUE CARTE NON SONO UGUALI IL TUO TURNO E' FINITO!!!\n");
                if(rand_start_play==1){
                    rand_start_play=0;
                }
                else{
                    rand_start_play=1;
                }
        }
            for(k=0;k<n_carte;k++){      /*CONTROLLO SE TUTTE LE CARTE SONO STATE SCOPERTE*/
                if(mazzo[k].coperta==1){
                    exit=true;
                }
                else{
                    exit=false;
                    break;
                }
            }
    }while(exit==false);//Usciamo dal while se tutte le carte sono state scoperte.
            if(pnt_primo>pnt_sec){
                printf("COMPLIMENTI %s HAI VINTO !!!!",giocatore_uno);
            }else if(pnt_primo<pnt_sec){
                printf("COMPLIMENTI %s HAI VINTO !!!!",giocatore_due);
                }else if(pnt_primo==pnt_sec)
                printf("LA PARTITA E' TERMINATA CON UN PAREGGIO!!!");
}
