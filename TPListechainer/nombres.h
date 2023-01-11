#ifndef NOMBRES_H_INCLUDED
#define NOMBRES_H_INCLUDED
//definition de la listes chainer
 typedef struct Box {
   int data;

   struct Box *next;

   }Box;

//creer une lsite chainer



   //affichages de la liste
 void afficherListe(Box* debut);


 //calcul longueur de la liste

  void Longeurliste(Box* p);



  int Longeurliste2(Box* p);


 //ajout des element a la liste chainer
 //ajouter au debut de liste

  Box* ajoutAuDebut(Box *debut,int elem);



 //ajout de fin de liste

 Box* ajoutFinListe(Box*debut,int elem);


 //ajout milieu de liste

 Box * ajoutMilieu(Box* debut,int elem,int v);


//suppression d elements de la liste chainer

//suppression debut liste

 Box * suppressionDebut(Box *debut);


//suppression fin de liste

 Box *suppressionFin(Box* debut);


//suppression milieur de liste

 Box * suppressionMlieu(Box *debut,int v);

//chercher un element dabs une liste

 void chercherelemen(Box *debut,int elem);


 int position(Box*debut,int elem);

 //trier une liste d ordre croisant

 Box *Listetrier(Box*debut);


 // ajouter dans une liste trier

 Box * ajoutBonendroi(Box* debut,int elem);

 //elimination de doublon dans une liste trier

 Box * ElimiDoublon(Box* debut);






#endif // NOMBRES_H_INCLUDED
