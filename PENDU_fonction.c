#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "PENDU_fonction.h"



 void menu()
    {
    printf("\n\n");
    printf("\t***** BIENVENUE DANS LE JEU DU PENDU *****");
    printf("\n\n");
    }

///_____________________________________________________________________________________________________________________________________________________________________________



 void choixdunombre(int *ptrNombre) ///lorsque vous appelez choixdunombre, vous permettez à cette fonction de modifier la valeur de la variable qu'elle prends en compte (pointeur).
                                   /// Puis dans le main.c la variable pointeur qui est une variable de type pointeur lol va directement envoyer la valeur qu'on lui à envoyer
                                   /// (via la fonction choixdunombre) à l'adresse vers laquelle il pointe ! en aucun cas il modifie ca propre valeur puisque sa valeur est une autre adresse
                                   /// ici c'est celle de nombre ! c'est un exemple de son utilisation.. dans le cas present c'est un peu comme un relai, mais on aurait pu faire plus simple
                                   /// en demandant à la fonction dans le main.c d'envoyer la valeur directement à l'adresse de nombre comme ceci : choixdunombre(int &nombre) .
    {
     do {
        scanf("%d", ptrNombre); ///scanf lis le nombre que ptrNombre doit envoyer à la variable pris en compte dans la fonction choixdunombre ! ici il l'envoie à "pointeur" qui fait le relai hors de la
                                                 ///fonction et l'envoie à l'adresse de "nombre" ! Dans le cas de scanf, le déréférencement n'est pas nécessaire car scanf s'attend à recevoir une adresse mémoire (un pointeur),
                                                ///et ptrNombre est déjà un pointeur. C'est pourquoi vous ne mettez pas une étoile devant ptrNombre dans le contexte de scanf.
        if (*ptrNombre > 30 || *ptrNombre < 1)
           {
            printf("Veuillez selectionner un nombre entre 1 et 30 \n\n");
           }

    } while (*ptrNombre >30 || *ptrNombre <1);
   }



///_____________________________________________________________________________________________________________________________________________________________________________




char* choixdumot(int Nombre,char mot[])
    {

switch(Nombre)

{

case 1:
mot[0]='o';
mot[1]='c';
mot[2]='t';
mot[3]='o';
mot[4]='b';
mot[5]='r';
mot[6]='e';
mot[7]='\0';
mot[8]= NULL;
mot[9]= NULL;
mot[10]= NULL;
mot[11]= NULL;
break;

case 2:
strcpy (mot,"tomate");
break;

case 3:
strcpy (mot,"bijoux");
break;

case 4:
strcpy (mot,"jambon");
break;

case 5:
strcpy (mot,"nuage");
break;

case 6:
strcpy (mot,"chemise");
break;

case 7:
strcpy (mot,"baltringue");
break;

case 8:
strcpy (mot,"vulgaire");
break;

case 9:
strcpy (mot,"princesse");
break;

case 10:
strcpy (mot,"zendaya");
break;

case 11:
strcpy (mot,"belzebute");
break;

case 12:
strcpy (mot,"raviolis");
break;

case 13:
strcpy (mot,"pieuvre");
break;

case 14:
strcpy (mot,"casquette");
break;

case 15:
strcpy (mot,"elonmusk");
break;

}

}



void jeu(int tailledumot, char mot[])
 {

    printf("\n\n      A vous de jouer !\n");

    char lettrespasbonnes[10];

    char lettrestrouvees[tailledumot];

    //memset = memory seting     marche pour les tableau de char prédefinie pas pour les chaine de char..
                                 //Et encore moins pour les tableaux d'entier numéraire !

    memset(lettrespasbonnes, ' ', 10);           //On remplie toute les cases de notre tableau.
    memset(lettrestrouvees, ' ', tailledumot);  //Utilisation de sizeof pour plus tard

    lettrespasbonnes[9] = '\0';               //On initialise le caractere de fin de ligne
    lettrestrouvees[tailledumot] = '\0';     //à la derniere position du tableau



    int nombredetentative = 10;

    char lettre;

    do {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");

        printf("Choisissez une lettre : ");
        scanf(" %c", &lettre);
        printf("\n");

       // int trouve = 0;

        for (int i = 0; i < tailledumot; i++)
            {
            if (mot[i] == lettre)
             {
                lettrestrouvees[i] = lettre;
              //  trouve = 1;
            }
           }

        printf("Mot : ");

        for (int i = 0; i < tailledumot; i++)
            {
            if (lettrestrouvees[i] != ' ')
             {
             printf("%c ", lettrestrouvees[i]);
             }
             else
                 {
                 printf("_ ");
                 }
             }
             printf("\n\n");



            if (strstr(mot,lettrestrouvees) != NULL)
             {
                 printf("BIEN JOUER GROS BG TU AS TROUVE LE MOT!!!");
                 break;
             }


        if (strchr(mot,lettre)!=NULL)
         {
         printf("Bien vu ! Vous avez trouve le \"%c\" !!\n\n", lettre);
         }
         else
            {
            printf("Rate ! Le \"%c\" n'est pas dans le mot..\n\n", lettre);

            nombredetentative--;

            if (strchr(lettrespasbonnes, lettre) == NULL)
                {
                for (int i = 0; i < 10; i++)
                {
                    if (lettrespasbonnes[i] == ' ')
                     {
                        lettrespasbonnes[i] = lettre;
                        break; //break fera toujours sortir de la boucle la plus proche ! la BOUCLE !!
                    }
                }
            }

            printf("Il vous reste %d tentative(s)\n\n", nombredetentative);
        }

        printf("Lettres pas bonnes : %s\n", lettrespasbonnes);

    } while (nombredetentative > 0);

}

