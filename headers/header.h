#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
typedef enum seme{denari=1,coppe,bastoni,spade}Semi_nap;
struct carta{
int valore;
Semi_nap seme;
bool coperta; //0
};
typedef struct carta Carta;
void swap_cards(Carta [40],int ,int );
void mix_cards(Carta [40],int ,int);
void vismixdeck(Carta [40],Carta*);
void scelta_carta(Carta [40],int*);
#endif //
