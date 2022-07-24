#include <stdlib.h> 
#include <stdio.h>



typedef struct noeud {
 struct noeud *next;
 struct noeud *prev;
    int info;


}noeud,*pt_noeud;
typedef struct liste{

noeud* head,*tail;
int length;//zaida o safi 

}liste,*pt_liste;


int is_empty(pt_liste L){
    return L==NULL;
    }

pt_liste allocate_liste(){
    pt_liste L=(pt_liste)malloc(sizeof(liste));
    L->head=NULL;
    L->tail=NULL;
    L->length=0;
    return L;
}  //allocates a list with its head tail an lentgh set to 0
pt_noeud allocate_node(int data){

pt_noeud new=(pt_noeud)malloc(sizeof(noeud));
new->next=NULL;
new->prev=NULL;
new->info=data;
return new;
}



pt_liste push_head_list(pt_liste L,int x){

if(L==NULL){
    printf("erreur malloc\n");
     
}
else {

pt_noeud new_node=(pt_noeud)malloc(sizeof(noeud));
new_node->info=x;
new_node->next=NULL;
new_node->prev=NULL;
if(new_node==NULL){
    printf("erreur malloc\n");
     exit(EXIT_FAILURE);
}

if(!L){
L=(pt_liste)malloc(sizeof(liste));
L->head=new_node;
L->tail=new_node;
L->length=0;
return L;
}
else {
new_node->next=L->head;
L->head->prev=new_node;
L->head=new_node;

}
L->length++;
return L;
}

return L;


}    




int main(){
    pt_liste l = NULL;


//exercise 1




return 0;
}