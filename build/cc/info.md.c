//cc1
//ex 03
void  inverse_listev1(noeud **head)
{
    // liste howa * noeud 3ndi 
    //head fih adrese dyal l head li f main 
    liste prev = NULL, next;
    // tmp pointeur 3la l valeur li f l head li f main 
    while((*head))
    {//tmp awl element f liste ( tmp ja b m3na d haid hit howa li aiwli hiead f lkher )//! ___ i am confuseeed ____
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //?FIRST ONE
        next = (*head)->next; // nkhab3o l addrese dyal next
        (*head)->next = prev; // updating the head->next  to the last element (last head)(int the first time the preve is NULL)
                           //---------------------------------------------------------------------------------------------------------------------
                           //?next iteration
        prev = *head;       // temp is the last element
        *head = next;       // head is the next element
    }
     *head=prev; // next aikhroj n null f7al f7al head li dariin while bih
    // o prev aikhroj b akhir elmenet next dyalo null (lkharr d liste ) lhead d liste jdida
}

//exer 1

1)typedef struct node
{
    struct node *next;
    struct node *prev;
    int data;
} node, *liste;
2)

void insert_liste_beg(liste *tail, int data)
{

    liste new_node = (liste)malloc(sizeof(node));
    new_node->data = data;
//tail hnia f 7ad l7ala fih l adrese dyal l pointeur dyana li bydo kaipwani wa7d l adrese li hia noeud
    if (!(*tail))
    {
        // LISTE KHAWIA
        new_node->next = new_node;
        new_node->prev = new_node;
        // L = new_node; ma 3nda ma3na
        *tail=new_node;
    }
    // kain au moins un elements
    // tmp is the first elements in the liste
    new_node->next = (*tail)->next;
    //! li maji d had new_node howa awl element f liste 9dima
    new_node->prev = *tail;
    //! jdid aikon l prev dyalo howa akhir element f liste hit liste chiane
    (*tail)->next->prev = new_node;
    //! awl elment khasna nrbtweh b new node li wla 9bal mno
    (*tail)->next = new_node;
    //! akhir element tail dyana aikon next dyalo howa awl element
 
  //tail aib9a f blasto
}
// l'appele   insert_liste_begv2(&tail, i);

//exer 2

func1 afficher le premier nombre et  saut de suivant vers l'element suivant

ex soit une liste 

//1 2 3 4  4 5 6 6 7 
 
func1 sera afiched 1 3 4 5 6 7 //que les position impaire

//exer 3 

//sure 


2
1
4
3
6
5

void h1(noeud *list){


noeud *p,*q;int temp;
if((!list || !noeud->next))return;
p=list;q=liste->next;
while(q){
temp=p->info;p->info=q->info;q->info=temp;
p=q->next;
q=p?p->next:NULL;
}
}
# exer 04
si list est trier decroissante en considerons meme si  la liste vide ou contient un element alors elle est trier et la fonction renvoie 1
int f(liste L){
  return (
    (!L) || (!L->next )|| (L->data <=L->next->data )&& f(L->next));
}
# exer 05 
int produit(liste p){


if(p==NULL)return 1;

  if(p->data % 3==0)return p->data*produit(p->next);
  else return produit(p->next);


}

# exer 06
//
prefixe : AFFICHAGE-> LEFT -> RIGHT 
posfixe : left->right->affichage
infixe  : LEFT -> AFFICHAGE ->  RIGHT
//
void prefixe(pt_arbre tr){

if(tr==NULL)return; 

printf("------------------------------------------------------\n"); 

if(tr->parent!=NULL)printf("Noeud %d parent %d\n",tr->value,tr->parent->value);
else printf("Noeud %d root \n",tr->value);
prefixe(tr->left);
prefixe(tr->right);


}
void infixe(pt_arbre tr){

if(tr==NULL)return; 

printf("------------------------------------------------------\n"); 

infixe(tr->left);
printf("Noeud %d \n",tr->value);
infixe(tr->right);


}
void posfixe(pt_arbre tr){

if(tr==NULL)return; 

printf("------------------------------------------------------\n"); 


prefixe(tr->left);
prefixe(tr->right);
if(!tr->parent)printf("Noeud %d parent %d\n",tr->value,tr->parent->value);
else printf("Noeud %d root \n",tr->value);

}
# cc2 



//ex 04
int negativevalues(liste l){

if(l==NULL)return 1;
else if(l->data<0)return l->data*negativevalues(l->next);
else return negativevalues(l->next);
//if the list is empty it will return 1
}

//exer 5
void afficherNodeR(liste p) {
if(p!= NULL){
      afficherNodeR(p->next);
      printf("%d\n",p->data);
}
}
// exe 6
liste reverse(liste dest,liste src){
  if(src==NULL)return dest;

  else {
liste tmp=src;
while (tmp!=NULL)
{
 dest=InssertQueque(dest,tmp->data);
  tmp=tmp->next;
  }
return dest;
}
}
// exe 7

void removeDuplicates(liste L)
{
  // here
  //! ATENTION ! PASSAGE PAR ADDRESE ICI !

  liste ptr1, ptr2, dup;
  ptr1 = L;

  /* Pick elements one by one */
  // ptr1 pour parcourir la liste kamlaaa mn lwl n lkhar
  //  o dak  ptr1 != NULL && ptr1->next blasat man3mlo 2 if ptr1->next == NULL zidnaha f while hit fa7ala
  while (ptr1 != NULL && ptr1->next != NULL)
  {
    ptr2 = ptr1;

    /* Compare the picked element with rest
       of the elements */
    // ptr2 aikon daemina howa kahir valeur 9bal ptr1
    while (ptr2->next != NULL)
    {
      /* If duplicate then delete it */
      if (ptr1->data == ptr2->next->data)
      {
        /* sequence of steps is important here */
        dup = ptr2->next;
        ptr2->next = ptr2->next->next;
        free(dup);
      }
      else /* This is tricky */
        ptr2 = ptr2->next;
    }
    ptr1 = ptr1->next;
  }
}



// exe 8


#include <stdlib.h>
#include <stdio.h> 
#include <math.h>

typedef struct  terme
{
int coef;
float val;

}terme;

typedef struct poly
{
 terme data;
 struct poly *next;

}poly,*pt_poly;

pt_poly addterme(pt_poly p,int a ,float b){

pt_poly nouv = (pt_poly)malloc(sizeof(poly));
if(nouv==NULL){
printf("malloc failed");
exit(EXIT_FAILURE);//awedi how cares
}
nouv->data.coef = a;
nouv->data.val = b;
nouv->next = p;
return nouv; //add the begging of the liste

}

 float eval(pt_poly p,float x){

if(!p)return 0;
return p->data.val*pow(x,p->data.coef)+eval(p->next,x); // rappele p-> means (*p). so we should use p->data->val that is incrroect
//3x =3 * x ^ 1 
// 3x^9= 3 * x ^ 9 // O(expo) attentient (penser a utiliser la scheme de horner pour evalur ce poly de meme maniere)

 }
int main(){

pt_poly p=NULL;//awl val wla boda null (bach lkhaar tkon null)

int x=0;



while (x!=-1)
{


printf("coef : \n");
int coef;
float val;
scanf("%d",&coef);
printf("val : \n");
scanf("%f",&val);
p=addterme(p,coef,val);

 printf("ajouter  terme 1 si oui  -1 si non  \n");
   scanf("%d",&x);
 
}
 

printf("entre x pour calculer P(x) =\n");
float img;
scanf("%f",&img);
printf("P(%f) = %.2f\n",img,eval(p,img));

    return 0;
}
// ex 09 
int count(liste L){

  if(!L)return 0;
  return 1+count(L->next);
}
