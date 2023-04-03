#include "header.h"
/*QUESTA FUNCTION SCAMBIA GLI INDICI DELL'ARRAY MAZZO,CIOE' NEL
  NOSTRO PROGRAMMA SCAMBIA LE CARTE DEL MAZZO,LA UTILIZZEREMO
  SUCCESSIVAMENTE PER L'IMPLEMENTAZIONE DELLA FUNCTION
  MISCHIARE LE CARTE DEL MAZZO.*/
void swap_cards(Carta mazzo[40],int i,int j){
Carta temp;
temp=mazzo[i];
mazzo[i]=mazzo[j];
mazzo[j]=temp;
}
/*QUESTA FUNCTION PRENDE IN INPUT L'ARRAY MAZZO IL NUMERO DELLE CARTE E IL NUMERO DI SCAMBI DA FARE,CIOE'
QUANTI SCAMBI SI DEVONO EFFETTUARE,E UTILIZZANDO LA FUNCTION swap_cards SCAMBIA A COPPIE LE CARTE DEL
MAZZO.*/
void mix_cards(Carta mazzo[40],int n_carte,int n_scambi){
int i=0,j=0,k;
for(k=0;k<n_carte*n_scambi;k++){
    i=rand()%n_carte;
    j=rand()%n_carte;
    swap_cards(mazzo,i,j);
}
}
/*QUESTA FUNCTION SERVE A VISUALIZZARE L'ELENCO DELLE CARTE*/
void vismixdeck(Carta mazzo[40],Carta *pcarta){
int i;
printf("ELENCO CARTE\n 1=CARTA SCOPERTA\n 0=CARTA COPERTA\n");
for(i=0;i<40;i++){
printf("carta n. %2d : valore = %d seme = %d la carta e' : %d \n\n",i+1,(pcarta+i)->valore,(pcarta+i)->seme,(pcarta+i)->coperta);
}
}
/*LA FUNCTION SCELTA_CARTA PERMETTE AL GIOCATORE DI SCEGLIERE UNA CARTA,LA CARTA SCELTA
  VIENE MEMORIZZATA NELLA VARIABILE I. */
void scelta_carta(Carta mazzo[40],int* i){
    scanf("%d",i); //CI SALVIAMO IL VALORE DELLA CARTA SCELTA
    while(mazzo[*i].coperta==1){ /*FINO A QUANDO LA CARTA HA COME VALORE COPERTO 1 CHIEDIAMO AL GIOCATORE DI SCEGLIERE UN'ALTRA CARTA*/
    printf("LA CARTA SELEZIONATA E' GIA' STATA SCELTA \n");
    printf("SELEZIONA UN 'ALTRA CARTA : \n");
    scanf("%d",i);
    }
    printf("La carta scelta e' valore = %d, seme = %d:\n\n",mazzo[*i].valore,mazzo[*i].seme);/*SE IL VALORE COPERTA E' DIVERSO DA UNO VISUALIZZIAMO LA CARTA E IMPOSTIAMO IL VALORE DI COPERTA UGUALE A 1*/
    mazzo[*i].coperta=1;
}
