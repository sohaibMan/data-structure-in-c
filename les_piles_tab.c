
#include <stdlib.h>
#include <stdio.h>
#define n 5

//! les piles avec les tableaux


 typedef struct  pile{
int tab[n];
int sommet;
  }pile;
  
//? piles ni plus utilise comme une tableaux
  int estVide(pile P){
   return P.sommet==-1;
  }

int sommet(pile P){
if(estVide(P))
{
    printf("Pile vide\n");
    exit(0);
}
else return P.tab[P.sommet];
}
int estPlein(pile P){
    return P.sommet==n-1;
    {
    // n-1 = taille de la pile
    // 1 si en ona dans le derne elment de la pile (plien ) 0 si non
    //    1 2 3 4 5 6 7 8 9 10 (n==10)
    //-1  0 1 2 3 4 5 6 7 8 9
   // 0   0 0 0 0 0 0 0 0 0 1
   //hit bdina b -1
    }
}
pile intaliserPilevide(){
pile q;
q.sommet=-1;
return q;
}
pile empiler(pile P,int data){
    if(estPlein(P))
    {
        printf("Pile pleine\n");
        exit(0);
    }
   P.tab[++(P.sommet)]=data;
    return P;

//haka atabdel f pile nita
} 
pile depiler(pile P,int *x){
    if(estVide(P))
    {
        printf("Pile pleine\n");
        exit(0);
    }
   *x=P.tab[(P.sommet)--];
 
         return  P;

//haka atabdel f pile nita
}


pile afficherpile(pile P){
if(estVide(P))
{
    printf("Pile vide rien a afficher \n");
    exit(0);
}
pile q=intaliserPilevide();
while (!estVide(P))
{
 int x;
 P=depiler(P,&x);
 printf("%d\n",x);
q=empiler(q,x);
}
while (!estVide(q))
{
    int x;
    q=depiler(q,&x);
    P=empiler(P,x);
}
return P;

}


int main (){
pile p=intaliserPilevide();
//p=afficherpile(p);


for(int i=0;i<n;i++)p=empiler(p,i);





p=afficherpile(p);










    return 0;
}