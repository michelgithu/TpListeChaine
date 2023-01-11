#include <stdio.h>
#include <stdlib.h>
#include "nombres.h"
#include "nombres.c"


int main()
{
    Box*liste=NULL;
    int choix,element,p;

    int ok;

  debut:


    printf("\n\n\t\t\t\t\t\t\t\t LES LISTES CHAINEES \n\n");

    printf("\n\n\t\t\tQUE VOULEZ VOUS ?\n\n\t\t\t\t");


    printf("\n\t\t\t1: CONSTRUIRE UNE LISTE CHAINER D ' ENTIERS \n\n\n\t\t\t2: AFFICHER LA LISTE CONSTRUITE \n\n\n\t\t\t3: CONNAITRE LA LONGEUR DE VOTRE LISTE \n\n");

    printf("\n\t\t\t4: AJOUTER UN ELEMENT AU DEBUT DE LA LISTE \n\n\n\t\t\t5: AJOUTER UN ELEMENT A LA FIN  DE LA LISTE \n\n\n\t\t\t6: AJOUTER UN ELEMENT A UNE POSITION DONNER  DE LA LISTE \n\n");

    printf("\n\t\t\t7: SUPPRIMER LE PREMIER ELEMENT DE LA LISTE  \n\n\n\t\t\t8: SUPPRIMER LE DERNIER  ELEMENT DE LA LISTE  \n\n\n\t\t\t9: SUPPRIMER UN ELEMENT DONNER  DE LA LISTE  \n\n");

    printf("\n\t\t\t10: CHERCHER UN NOMBRE DANS LA LISTE \n\n\n\t\t\t11: TRIER LA LISTE D'ORDRE CROISSANT\n\n\n\t\t\t12: AJOUTER UN NOMBRE UN NOMBRE DANS UNE LISTE TRIER \n\n\n\t\t\t13: ELIMINER LES DOUBLON DE LA LISTE\n\n");

    printf("\n\n\t\t\t ENTRER VOTRE CHOIX ?\n\n\t\t\t\t");

    scanf("%d",&choix);

    while(choix!=1 && choix!=2 && choix!=3 && choix!=4 && choix!=5 && choix!=6 && choix!=7 && choix!=8 && choix!=9 && choix!=10 && choix!=11 &&  choix!=12 &&  choix!=13)
    {
        printf("\n\n\t\t\t ENTRER A NOUVEAU VOTRE CHOIX ?\n\n\t\t\t\t");

        scanf("%d",&choix);

    }

    switch(choix)
    {
        case 1 :liste=plussieurListe(liste) ;afficherListe(liste) ;
                                                        break;

        case 2 : afficherListe(liste) ; break;

        case 3 :Longeurliste(liste) ; break;

        case 4 :printf("Entrer la valuer a ajouter\t");
                scanf("%d",&element);
                liste=ajoutAuDebut(liste,element) ;
                                         break;
        case 5 :
                printf("Entrer la valuer a ajouter\t");
                scanf("%d",&element);
                liste=ajoutFinListe(liste,element) ;
                                        break;
        case 6 :printf("Entrer la valuer a ajouter\t");
                scanf("%d",&element);
                printf("a quelle position voulez vous ajouter l element\t ?");
                scanf("%d",&p);
                if(p>Longeurliste2(liste)+1)
                {
                    printf("la liste contient %d elements donc reverifier vorte position");

                }
                ajoutMilieu(liste,element,p) ;
                                          break;
        case 7 :liste=suppressionDebut(liste); break;

        case 8 : liste=suppressionFin(liste) ; break;

        case 9 :
                printf("Quel element voulez vous supprimer l'element\t ?");
                scanf("%d",&p);
                liste=suppressionMlieu(liste,p) ; break;

        case 10 :printf("Entrer la valuer de l element a chercher \t");
                 scanf("%d",&element);
                 chercherelemen(liste,element) ; break;

        case 11:liste=Listetrier(liste) ; break;

        case 12 : printf("Entrer la valuer a ajouter\t");
                  scanf("%d",&element);
                  liste=ajoutBonendroi(liste, element) ; break;

        case 13 :liste=ElimiDoublon(liste) ; break;

        default  :printf("Erreur de saisie \t entere une bonne valeur ");


    }

    printf("Vous avez fini et vous voulez quitter\t 1 pour oui et 0 pour non ? ");

    scanf("%d",&ok);

  if(ok==0);
  {
   system("cls") ;
    goto debut;
  }



    return 0;
}
