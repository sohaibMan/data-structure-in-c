#include <stdlib.h>
#include <stdio.h>

typedef struct node
{

    int data;
    struct node *next;
    struct node *prev;

} node, *pt_node;
typedef struct liste
{
    int length;
    node *head;
    node *tail;

} dliste, *pt_dliste;
// kol node 3ndo data dyalo 3ndo li 9abl mno o li morah
//  o pt_dliste kamla ma hia ila pointur kaihoz 2 add dyal bdo o dyal lkhar o kahoz length m3ah




int liste_length(pt_dliste l)
{
    return l->length;//if not empty add it
}
int liste_head_value(pt_dliste l)
{
    return l->head->data;// if not empty add it 
}
int liste_tail_value(pt_dliste l)
{
    return l->tail->data;//if not empty add it
}

pt_dliste allocate_liste(){
    pt_dliste L=(pt_dliste)malloc(sizeof(dliste));
    L->head=NULL;
    L->tail=NULL;
    L->length=0;
    return L;
}  //allocates a list with its head tail an lentgh set to 0

pt_node allocate_node(int data){

pt_node new=(pt_node)malloc(sizeof(node));
  if (!new)
    {
        printf("malloc failed");
        exit(EXIT_FAILURE);
    }
new->next=NULL;
new->prev=NULL;
new->data=data;
return new;
}

pt_dliste first_node(pt_dliste l ,int data){

 l = allocate_liste();//allocation of list
pt_node new_node = allocate_node(data);
        l->head = new_node;
        l->tail = new_node;
         l->length++;
         return l;

//if our liste is empty we create a new liste and we full the head of it and the tail of it with the new node (the first element hada)

}

pt_dliste push_tail(pt_dliste l, int data)
{
   
    if (!l)return first_node(l,data);// our list is empty (Null) we should fill it
    pt_node new_node= allocate_node(data);

        l->tail->next = new_node;
        new_node->prev = l->tail;
        l->tail = new_node;

        // l fih tail o tail fiha next o pre
        // db hnia kanzido n lakhr d pt_dliste  mn limn ya3ni lakant 3 kanzido 9bal mna 2
        //
    l->length++;
    return l;
}


pt_dliste push_head(pt_dliste l, int data)
{


    if (!l)return first_node(l,data);// our list is empty (Null) we shoulud fill it
    pt_node new_node= allocate_node(data);
        //? there is at least one element in the liste
        l->head->prev = new_node;
        new_node->next = l->head;
        //new_node->prev=NULL; deja fait car on a intialise TOUTes les champes par null
        l->head = new_node;
         l->length++;
        //?
         return l;
}

pt_dliste pop_tail_dlist(pt_dliste L)
{
    if (!L)
    {
        puts("list is empty");
        return NULL;
    }
    if (L->length == 1)
    {
      
        // 1 node// ou bien L //? L->head==L->tail;======= L->length
        free(L->tail);
        // l->tail= l->head;
      
        return NULL;
    }
    pt_node tmp = L->tail;
    L->tail = L->tail->prev;

    // tmp->next = NULL;
    // tmp->prev = NULL;
    // darori NULL
    // tmp = NULL;
    L->tail->next = NULL;
    free(tmp);
    L->length--;
    return L;
}

pt_dliste pop_head_dlist(pt_dliste L)
{
    if (!L)
    {
        puts("list is empty");
        return NULL;
    }
    if (L->length == 1)
    {
        // 1 node
        free(L->head);
        return NULL;
    }
    pt_node tmp = L->head;
    L->head = L->head->next;
    // tmp->next = NULL;
    // tmp->prev = NULL;
    L->head->prev = NULL;
    free(tmp);
    // tmp = NULL;
    L->length--;
    return L;
}


void print_list(pt_dliste l)
{
    // sens direct
    if (!l)
     {
     puts("list is empty");

    return;
  } 
     pt_node tmp = l->head;
    // pt_node tmp = l->tail;
    while (tmp != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
        // tmp = tmp->prev;
    }

    printf("\n");
}
// 123456
void afficher_recv11(pt_node L){

if(!L)return;
printf("%d ",L->data);
afficher_recv11(L->next);
//sense direcete
}
//654123
void afficher_recv12(pt_node L){

if(!L)return;
afficher_recv12(L->next);
printf("%d ",L->data);
//sense direcete
}

//654321
void afficher_recv21(pt_node L){

if(!L)return;
printf("%d ",L->data);
afficher_recv21(L->next);
//sense direcete
}
//123456
void afficher_recv22(pt_node L){

if(!L)return;
afficher_recv22(L->next);
printf("%d ",L->data);
//sense direcete
}

pt_dliste clear_liste(pt_dliste l)
{

    while (l)
    {
        pop_head_dlist(l);
    }
}
int main()
{

    // exercise 1
    pt_dliste l = NULL;

    for(int i=1;i<50;i++){

        l=push_tail(l,i);
        //   l=push_head(l,i);
        //   l=pop_head_dlist(l);
        //   l=pop_tail_dlist(l);
        
    }
//print_list(l);
    // l = push_tail(l, 1);

    // print_list(l);
    // l = push_tail(l, 2);

    // print_list(l);
    // l = push_tail(l, 3);
    // print_list(l);
    // l = push_head(l, 4);
    // print_list(l);
    // l = push_head(l, 5);
    // print_list(l);
    // l = push_head(l, 6);
    // print_list(l);
    // pop_head_dlist(l);
    // int x = liste_length(l);
    //   for(int i=0;i<x;i++){
    //        l=pop_tail_dlist(l);
    //   }

    // printf("%d\n",liste_length(l));
//    print_list(l);
afficher_recv21(l->tail);
 //   l = clear_liste(l);

    return 0;
}