#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stddef.h>

#include "PENDU_fonction.h"
#include "PENDU_fonction.c"



int main(int argc, char *argv[])
 {

menu();

printf("\n\n");



char rejouer[2]; //alloue toujours de l'espace memoire stv modifier la chaine plus tard avec * c'est un pointeur sur la premiere case bordel !!

do
{
printf("Veuillez selectionner un nombre entre 1 et 15");

printf("\n\n");
int nombre;

choixdunombre(&nombre);

printf("\n\n");
                           //si tu veux remplacer par : char* mot; ca marche aussi mais c'est dangereux.. alloue tjrs un espace
                           //mémoire dédier à ton mot.. ca evite que le programme occupe l'espace mémoire par autre chose !

char mot[11];
                            /// char* mot = choixdumot(nombre); AVEC UTILISATION DE : return mot; DANS LA FONCTION NE MARCHE PAS
                           /*Retourner l'adresse d'une variable locale (mot dans choixdumot) à partir d'une fonction
                             et l'utiliser en dehors de cette fonction peut entrainner un comportement indéfini,
                             car cette zone de mémoire peut être utilisée après la sortie de la fonction.
                             Ainsi, bien que le code puisse compiler, il ne fonctionnera pas comme prévu. */
choixdumot(nombre,mot);


printf("\n\n");



int tailledumot = strlen(mot);

printf("Votre mot est en %d lettres !\n\n",tailledumot);

printf("mot : ");

for (int i =0; i<tailledumot; i++)
{

    printf("_ ");
}



jeu(tailledumot,mot);   //regarde bien compte ce que prenne en compte tes fonctions putain !!!

printf("\n\n\n\nVOULEZ VOUS REJOUER UNE PARTIE ???\n\n\n\n");

scanf(" %s", &rejouer);
}

while (strcmp(rejouer,"no")!=0);
















printf("\n\n");

printf("\n\n");








///regle aprises :

//PAS DE RETURN DANS UN SWITCH NI DINITIALISATION DE VARIABLE! CA NE RENVOIE RIEN

//SI TU VEUX QUE TA VARIABLE CONSERVE SA VALEUR EN DEHORS DES ACOLODES
//DE TA FONCTION, ALORS UTILISE CONST !!

//UNE FONCTION SA PEUT PRENDRE PLEIN DE VARIABLE EN COMPTE ! UTILISE TANT
//POUR FAIRE TRANSITER LES VALEURS VIA POINTEURS !!

//LE RETURN PEUT RENVOYER CE QUE TU VEUX (A SPECIFIER DANS LA FONCTION),
//MAIS IL RENVERRA QU'UNE SEULE VALEUR !

//Le break a un effet de sortie immédiate de la boucle la plus proche dans laquelle il est contenu,
//quel que soit le nombre de niveaux d'imbrication d'instructions if.










    return 0;
}
