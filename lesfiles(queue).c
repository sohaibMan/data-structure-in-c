#include <stdlib.h> 
#include <stdio.h>

typedef struct  neoud neoud;
typedef  neoud* file;


typedef struct neoud
{
    int val;
    struct  neoud * next;
   
}neoud;




//!file : first in first out (queue) FIFO (first in First out)
//!pile : last in first out (stacks) LIFO (Last In First Out
// Les piles (stack) et les files (queue)
//  

int estVide(file f){
    return f==NULL;
    //if f pointe sur NULL, retourne 1
    //else retourne 0
}
int tete(file f){
    if(estVide(f)){
        printf("Liste vide\n");
        exit(0);
    }
     return f->val;
}
file enfiler(file f, int val){

    if (estVide(f))
    {
        file nouv = (file)malloc(sizeof(neoud));
        nouv->val = val;
        nouv->next = NULL;
        return nouv;

    }
     else  {f->next=enfiler(f->next, val);return f;}
    
}
file defiler(file f, int* val){
    // use haved used the pointeur coz we can't return in c two values
if(estVide(f)){
    printf("Liste vide\n");
    exit(0);
}
else {
    *val = f->val;
  
    file tmp = f->next;
    free(f);
    return tmp;
}

} 
 


file afficher(file P){

if(estVide(P))
{
    printf("file vide\n");
    exit(0);
}
else {
    int x;file q=NULL;
    while (!estVide(P))
    {
P=defiler(P,&x);

q=enfiler(q,x);
printf("%d\n",x);
    }
// while (!estVide(q))
// {
//     int x;
// q=defiler(q,&x);
// P=enfiler(P,x);
// }
// return p;

    return q;
    


}

}



 int main (){ 

file F=NULL;
for(int i=0;i<10;i++){
    F=enfiler(F,i);
}
// printf("%d\n",tete(F));
F=afficher(F);
F=afficher(F);
F=afficher(F);




     return 0;
 }