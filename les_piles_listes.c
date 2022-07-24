#include <stdlib.h>
#include <stdio.h>

//!les piles sont des structures de type liste qui sont chainees   de type liste 
//!file : first in first out (queue) FIFO (first in last out)
//!pile : last in first out (stacks) LIFO (Last In First Out)
//! Les piles (stack) et les files (queue)

typedef struct  node node;
typedef node *pile;
 struct  node{
int data;
 pile next;
};

int estVide(pile P){return P==NULL;}
int sommet(pile P)
{
    
    if(estVide(P))
    {
        printf("Pile vide\n");
        exit(0);
    }
     else return P->data;
     //it will return the first element of the stack(pile)
}
pile empiler(pile P,int data)
{
    //insert tete
    pile newNode=(pile)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=P;
    return newNode;

}



void affichepile(pile P){


if(estVide(P))
{
    printf("Pile vide\n");
    exit(0);
}
printf("%d",P->data);
affihcer(P->next);

}
//solution 1
int depiler2(pile *P){
//remove head + return data
int data=(*P)->data;//atkhsar data
pile temp=(*P);// tkhba3 l addrese d awl element
(*P)=(*P)->next;//dwaz lhead n element li morah 
free(temp);//tam7i P 9idma
return data;//rode l valeur 

}
//on ne peut pas return 2 valeurs en c avec une return alors on a 2 solutions soit en utilisant un pointeur sur pile lui meme ** et 
//on retourne data or une passage par addrese de la data et on retoure data
//soultion 2
pile depiler(pile P,int *data){
    if(estVide(P))
    {
        printf("Pile vide\n");
        exit(0);
    }
*data=(P)->data;
pile temp=P;
P=P->next;
free(temp);
return P;

// pile temp=P->next;
// free(P);
// return tmp;


//derna pasage par addrese hit ga3ma an9dro ndiro doubel return
//int a;
// appelle :depiler(P,&a)

}

pile afficher(pile P){
 pile q=NULL;
if(estVide(P))
{
    printf("Pile vide\n");
    exit(0);
}

while (!P)
    {
    int x;
P=depiler(P,&x);
q=empiler(q,x);
printf("%d\n",x);
    }
// while (!P)
//     {
//     int x=depiler(&P);//aitrode valeur li kaina f head o aidoz l head n next
// q=empiler(q,x);
// printf("%d\n",x);
//     }
//---------------
// while (!q)
// {
//     int x;
// q=depiler(q,&x);
// P=empiler(P,x);
// }
//     return P;
    
return q;
    
}









int main (){

pile P=NULL;
for(int i=0;i<10;i++){

P=empiler(P,i);

}
//P=afficher(P);
printf("le premier element de la pile est : %d\n",sommet(P));
int x;P=depiler(P,&x);
printf("le premier element de la pile est : %d\n",x);
printf("le premier element de la pile est : %d\n",sommet(P));
P=afficher(P);



    return 0;
}
