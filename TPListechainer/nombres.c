#include "nombres.h"


//afficher la liste chainner
  void afficherListe(Box* debut)
   {
       Box * temp;
       temp=debut;
       if (debut==NULL)
         printf("La liste est vide");
       else{

             while(temp!=NULL)
           {
                 printf("(%d)->",temp->data);
                 temp=temp->next;
           }
          printf("\n");
       }

   }




 Box* plussieurListe(Box*debut)
 {
     int nelem;
     printf(" Entrer le nombre d elements : \t");

     scanf("%d",&nelem);

     int i=0,n;
     for(i=0;i<nelem;i++)
     {
         printf(" Entrer la %d ieme donnée de la liste \t",i+1);

         scanf("%d",&n);
         debut=ajoutFinListe(debut,n);

     }

     return debut;

 }
   //longueur de la liste

 void Longeurliste(Box *debut)
   { int numbers=0;
       Box * temp;
       temp=debut;

         while(temp!=NULL)
       {
         numbers++;
         temp=temp->next;
       }

      if(numbers==0)
        printf("La liste est vide\n");
      else
        printf("La liste est constituee de %.2d elements",numbers);
   }




 int Longeurliste2(Box *debut)
   { int numbers=0;
       Box * temp;
       temp=debut;

         while(temp!=NULL)
       {
         numbers++;
         temp=temp->next;
       }

     return numbers;
   }




//ajout debut de liste

  Box* ajoutAuDebut(Box *debut,int elem)
         { Box *b;
           b=(Box*)malloc(sizeof(Box));
           b->data=elem;
           b->next=debut;
           debut=b;

           return debut;
         }

//ajout fin de liste


  Box*  ajoutFinListe(Box*debut,int elem)
        { Box*b,*temp;

         b=(Box*)malloc(sizeof(Box));
         b->data=elem;
         b->next=NULL;
         if(debut==NULL)
         {
             debut=b;
         }
         else
         { temp=debut;
             while(temp->next!=NULL)
             {
                 temp=temp->next;
             }
            temp->next=b;

         }

           return debut;
        }

//ajout milieu de liste


 Box * ajoutMilieu(Box* debut,int elem,int p)
        {
         Box*b,*temp;
        if (debut==NULL)
        {
            printf("La liste est vide ");
           debut=ajoutAuDebut(debut,elem);
        }
        else
        { b=(Box*)malloc(sizeof(Box));
         temp=debut;
         b->data=elem;
         int cpt=1;
           while(temp!=NULL)
           {
               cpt++;
               if(cpt==p)
                   {

                       b->next=temp->next;
                       temp->next=b;
                   }
               temp=temp->next;
           }

      /*     if( temp!=NULL && cpt)

           {
               b->next=temp->next;
               temp->next=b;
           }
           else
           {
                printf("La valeur %d n'existe pas dans la liste",p);
              return 0;
           }*/

        }
        return debut;
      }

//suppression dans la liste


//SUPPRESSION AU DEBUT DUN LISTE CHAINER
Box * suppressionDebut(Box *debut)
        {Box*p;
         if(debut!=NULL)
            {p=debut;
            debut=debut->next;
            free(p);
            }
          return debut;
        }

//SUPPRESSION A LA FIN DE LISTE CHAINER
 Box *suppressionFin(Box* debut)
   {   Box* temp;
       if(debut!=NULL)
       {
           if(debut->next==NULL)
            {
                free(debut);
                debut=NULL;
            }
            else
            {temp=debut;
             while(temp->next->next!=NULL)
               {
                temp=temp->next;
               }
             free(temp->next);
             temp->next=NULL;

            }
       }
       return debut;
   }
//SUPPRESSIONAU MILIEU DE LISTE
 Box * suppressionMlieu(Box *debut,int p1)
       {
           Box *temp,*p;
           if(debut!=NULL)
           {
               if(debut->data==p1)
               {
                   p=debut;
                   debut=debut->next;
                   free(p);
               }
               else
               {
                   temp=debut;
                   while(temp->next!=NULL && temp->next->data!=p1)
                   {
                    temp=temp->next;

                   }
                   if(temp->next!=NULL)
                   {
                       p=temp->next;
                       temp->next=temp->next->next;
                       free(p);
                   }
                   else
                   {
                       printf("L'element que vous voulez supprimer n'existe meme pas dans la liste");
                   }

               }
              return debut;
           }
       }

//chercher un element dans une liste

 void chercherelemen(Box *debut,int elem)
 {
     Box*temp;
     if(debut==NULL)
         {
            printf("La liste est vide pas d elements dans la liste ");
         }
      else
        {  int position=0;
           temp=debut;
           while(temp!=NULL && temp->data!=elem)
           {
               temp=temp->next;
               position++;
           }

           if(temp!=NULL )
           {
               printf("L'element se trouve dans la liste et est le %d ieme de la liste",position+1);
           }

           else
              printf("L'element ne se  trouve pas dans la liste ");


        }

 }

 //position d un element
 int position(Box*debut,int elem)
 {

     Box*temp;
     int position=0;
     if(debut==NULL)
         {
             return 0;
         }
      else
        {
           temp=debut;
           while(temp!=NULL && temp->data!=elem)
           {
               temp=temp->next;
               position++;
           }


        }
     return position+1;
 }



 //Trier la liste de nombre croissant

  Box *Listetrier(Box*debut)
  {
      Box *temp,*ntemp;
      temp=debut;
      if (debut==NULL)
        printf("La liste est vide impossible de trier");
      else if (temp->next==NULL)
        printf("La liste contient qu 'un seul element  impossible de trier ");


      else
      {   int first;

            for(temp=debut;temp->next!=NULL;temp=temp->next)
             {
              for(ntemp=temp->next;ntemp!=NULL;ntemp=ntemp->next)
                {
                  if(ntemp->data<temp->data)
                     {
                         first=temp->data;
                         temp->data=ntemp->data;
                         ntemp->data=first;
                     }

                }


             }



      }

     return debut;

  }



 // ajouter dans une liste trier

 Box * ajoutBonendroi(Box* debut,int elem)
 {
     Box *temp;

     debut=Listetrier(debut);
     temp=debut;
     if(debut!=NULL && debut!=0){
        while(temp->next!=NULL)
           {
               if(temp->data<=elem && temp->next->data>=elem)
               {
                   debut=ajoutMilieu(debut,elem,position(debut,temp->next->data));

                   return debut;
               }

              temp=temp->next;

           }
      }
 }

//elimination de doublon

 Box * ElimiDoublon(Box* debut)
 {
     Box *temp,*ntemp;
     int first;

     temp=debut;

     if(temp!=NULL && temp->next!=NULL)
     {

            for(temp=debut;temp->next!=NULL;temp=temp->next)
               {
                  for(ntemp=temp->next;ntemp!=NULL;ntemp=ntemp->next)
                  {
                    if(temp->data==ntemp->data)
                      {

                        debut=suppressionMlieu(debut,ntemp->data);
                        temp=debut;
                        ntemp=temp;

                        break;

                      }

                 }

              }/*
                if(temp!=NULL && temp->next!=NULL)
           {
                temp=debut;
                ntemp=temp->next;
                int cpt=0;
           while(temp->next!=NULL)
               {
                  while(ntemp!=NULL)
                  {
                    if(temp->data==ntemp->data)
                      {

                        debut=suppressionMlieu(debut,ntemp->data);

                        cpt++;


                      }
                      if(cpt!=0)
                      {
                           temp=debut;
                           ntemp=temp->next;
                           cpt=0;
                      }

                         else
                         ntemp=ntemp->next;
                 }

                   temp=temp->next;
              }


        return debut;

     }
*/}
     else
     {
        printf("Il semble que la liste est vide ");

        return 0;

     }
return debut;

 }





