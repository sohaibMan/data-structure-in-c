// the same as a singly list but the diffrenet is the last node point to the first node

#include <stdlib.h>
#include <stdio.h>
typedef struct node node;
typedef node *liste;
struct node
{
  int data;
  liste next;
};
//the beging of the liste

liste insert_liste_beg(liste tail, int data)
{
  liste new_node = (liste)malloc(sizeof(node));
  if (new_node == NULL)
  {
    printf("malloc failed");
    exit(EXIT_FAILURE);
  }
  new_node->data = data;
  if (tail == NULL)
  {
   new_node->next = new_node;
    return new_node;
    
    //liste khawia
  }

  new_node->next = tail->next;
  //tail->next adress of the first node
  tail->next = new_node;
  return tail;
}

liste insert_liste_end(liste tail,int data){



 liste new_node = (liste)malloc(sizeof(node));
  if (new_node == NULL)
  {
    printf("malloc failed");
    exit(EXIT_FAILURE);
  }
  new_node->data = data;
  if (!tail)
  {
    new_node->next = new_node;//kain gha element wa7d aipwanti 3la rasu niiiiit
     return new_node;
    //liste khawia
  }

  new_node->next = tail->next;
  //tail->next adress of the first node
  tail->next = new_node;
  return new_node;// tail ga3ma tbdal fiha walu hit kanzido f lwl o tail katpawtni 3la lkhar


}

liste pop_head(liste tail){
//aucun elemets
if(tail==NULL){
  printf("liste vide\n");
  return tail;
}
// 1 seule
if(tail==tail->next){
free(tail);
return NULL;//aitdbel tail
}
//plusieurs
liste tmp=tail->next;
tail->next=tmp->next;
free(tmp);
return tail;//ga3ma aitbdel f had l cas
}
liste pop_tail(liste tail){


//ida kant khawia
if(tail==NULL){
  printf("liste vide\n");
  return tail;
}
// ida kan fiha gha wa7d
if(tail->next==tail){
free(tail);
return NULL;
}

//ida kant 3amara

liste tmp=tail->next;
while(tmp->next!=tail){

  tmp=tmp->next;
//na9wefoh f  element li 9abal tail 
}
tmp->next=tail->next;
// na9zo bih n lawara
free(tail);
// tail=NULL;
return tmp;



}
liste pop_position(liste tail ,int pos){

//no element

if(tail==NULL){
  printf("liste vide\n");
  return tail;
}
// one element
if(tail->next==tail){

free(tail);
tail=NULL;
return tail;

}
// more than one element
liste tmp=tail->next;
if(pos<=1)return pop_head(tail);
while (pos>2 && tmp->next!=tail){
  tmp=tmp->next;
}

// tmp aiwa9f f pos -1
if(tmp->next==tail)return pop_tail(tail);//yan3i rak wa9tfi f element li 9bal tail cta ya pos li khtart hia lkhara ya pos kbar mn size d liste

  liste tmp2=tmp->next;
  //handling the case of the lasat node here we should change the tail

  tmp->next=tmp2->next;
  free(tmp2);
  return tail;
//ya arod tail lwla kifma hia ya airda li 9bl tail ida kant positon hia lkahra

}


int count_node(liste tail){

int count=1;
if(tail==NULL)return 0;
liste current=tail->next;
while(current!=tail){
  current=current->next;
  count++;
}
return count;




}




int count_rec_aide(liste L,liste current){
if(!L)return 0;
if(L==current)return 1;
return 1+count_rec_aide(L->next,current);


}
int count_rec(liste tail){


  if (!tail)return 0;
 return  count_rec_aide(tail->next,tail);// we are sure that the tail is not null
  
}

 







// void insert_liste_beg( node **tail, int data)
// {
//   liste new_node = (liste)malloc(sizeof(node));
//   if (new_node == NULL)
//   {
//     printf("malloc failed");
//     exit(EXIT_FAILURE);
//   }
//   new_node->data = data;
//   if (*tail == NULL)
//   {
//     (*tail)= new_node;
//     new_node->next = *tail;
  
//     //liste khawia
//   }

//   new_node->next = (*tail)->next;
//   //tail->next adress of the first node
//   (*tail)->next = new_node;

// }

liste insert_into_post(liste tail,int data,int pos){

liste new_node = (liste)malloc(sizeof(node));
liste temp =tail->next;//temp db f lwl

  if (new_node == NULL)
  {
    printf("malloc failed");
    exit(EXIT_FAILURE);
  }
  new_node->data = data;

while(pos>1){
  temp=temp->next;
  pos--;
}

new_node->next=temp->next;
temp->next=new_node; 

if(temp==tail)return new_node;//tizid  f lkher d liste

return tail;

}
void printf_liste(liste tail)
{
  liste p = tail;
//tail -> next howaa awl element f liste
  do
  {
    printf("%d ", p->next->data);
    p = p->next;
  } while (p != tail);
  printf("\n");
  //! tail.next == head
}
int search_liste(liste tail,int data){
liste p=tail->next;

while(p!=tail){
  if(p->data==data)return 1;
  p=p->next;
}

return 0;



}



int main()
{
  liste tail = NULL;int n=15;

  for (int i = 1; i <= n; i++)
  {
    // printf(" enter the %d elements \n", i);
    // int tmp;
    // scanf("%d",&tmp);
    // tail = insert_liste_beg(tail, tmp);
    tail = insert_liste_end(tail, i);
  }

tail=insert_liste_beg(tail,3);
tail=insert_liste_beg(tail,3);
tail=insert_liste_beg(tail,3);
tail=insert_liste_beg(tail,3);
tail=insert_liste_beg(tail,3);
tail=insert_liste_beg(tail,3);
tail=insert_liste_beg(tail,3);
tail=insert_liste_beg(tail,3);
tail=insert_liste_beg(tail,3);
//     printf_liste(tail);
printf("%d %d\n",count_node(tail),count_rec(tail));
  // tail=pop_head(tail);
  // tail=pop_tail(tail);
  // tail=pop_head(tail);
  // tail=pop_tail(tail);
  // tail=pop_tail(tail);
  // tail=pop_tail(tail);
// tail=pop_positionRec(tail,5);
// printf("%d\n",count_node(tail));
// printf("%d\n",search_liste(tail,10));

  //printf_liste(tail);

  return 0;
}