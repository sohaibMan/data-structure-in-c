#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    struct node *prev;
    int data;
} node, *liste;

liste insert_liste_beg(liste tail, int data)
{

    liste new_node = (liste)malloc(sizeof(node));
    new_node->data = data;

    if (tail == NULL)
    {
        // LISTE KHAWIA
        new_node->next = new_node;
        new_node->prev = new_node;
        // L = new_node; ma 3nda ma3na
        return new_node;
        //chainage avec lui meme
    }
    //on peut le reduit dans un program first_node(tail)

    // kain au moins un elements
    // tmp is the first elements in the liste
     new_node->next = tail->next;
    //! li maji d had new_node howa awl element f liste
    new_node->prev = tail;
    //! jdid aikon l prev dyalo howa akhir element f liste hit liste chiane circulaire
    tail->next->prev = new_node;
    //! awl elment khasna nrbtweh b new node li wla 9bal mno
    tail->next = new_node;
    //! akhir element tail dyana aikon next dyalo howa awl element

    return tail;
}



void insert_liste_begv2(liste *tail, int data)
{

    liste new_node = (liste)malloc(sizeof(node));
    new_node->data = data;
//tail hnia f 7ad l7ala fih l adrese dyal l pointeur dyana li bydo kaipwani wa7d l adrese li hia noeud
    if (*tail == NULL)
    {
        // LISTE KHAWIA
        new_node->next = new_node;
        new_node->prev = new_node;
        // L = new_node; ma 3nda ma3na
        *tail = new_node;
    }
    // kain au moins un elements
    // tmp is the first elements in the liste
    new_node->next = (*tail)->next;
    //! li maji d had new_node howa awl element f liste
    new_node->prev = *tail;
    //! jdid aikon l prev dyalo howa akhir element f liste hit liste chiane
    (*tail)->next->prev = new_node;
    //! awl elment khasna nrbtweh b new node li wla 9bal mno
    (*tail)->next = new_node;
    //! akhir element tail dyana aikon next dyalo howa awl element

    
}


liste insert_liste_end(liste tail, int data)
{

    liste new_node = (liste)malloc(sizeof(node));
    new_node->data = data;

    if (tail == NULL)
    {
        // LISTE KHAWIA
        new_node->next = new_node;
        new_node->prev = new_node;
        // L = new_node; ma 3nda ma3na
        return new_node;
    }

    new_node->next = tail->next;
    new_node->prev = tail;//had 2 lwla hnia ta9albom
    tail->next->prev = new_node;
    tail->next = new_node;//hado lae

    return new_node;//zidnah f lkher ya3ni aiwli howa lkher howa tail
}
liste insert_pos(liste tail, int data, int pos)
{

    liste new_node = (liste)malloc(sizeof(node));
    new_node->data = data;

    if (tail == NULL)
    {
        // LISTE KHAWIA
        new_node->next = new_node;
        new_node->prev = new_node;
        // L = new_node; ma 3nda ma3na
        return new_node;
    }
    if (pos <= 1)return insert_liste_beg(tail, data);//darori nafa9o bain les cas ou pos <= 1 lwl d liste
    liste tmp = tail->next;
    // f lwasat
    while (pos > 2 && tmp->next != tail)
    {
        tmp = tmp->next;
        pos--;
    }
//kher
if(tmp->next == tail)return insert_liste_end(tail, data);
    // 3 <1  zid 2<1 zid 1<1 stop aizidi 2 fois (i-1)
    // lwsat
    new_node->next = tmp->next;
    new_node->prev = tmp;
    tmp->next = new_node;
    tmp->next->prev = new_node;
    if (tmp == tail)
        return new_node; // as tail
    return tail;
}
liste delete_head(liste tail)
{

    if (tail == NULL)
    {
        puts("liste khawa");
        return NULL;
    }
    if (tail == tail->next)
    {
        free(tail);
        return NULL;
    }
    liste tmp = tail->next; // awl element //!tmp is for read only
    tail->next = tail->next->next;
    tail->next->next->prev = tail;
    free(tmp);

    return tail;
}
liste delete_queque(liste tail)
{
    if (tail == NULL)
    {
        puts("liste khawa");
        return NULL;
    }
    if (tail == tail->next)
    {
        free(tail);
        return NULL;
    }

    liste tmp = tail->prev;
    tmp->next = tail->next;
    tail->next->prev = tmp;

    free(tail);
    return tmp;
}


liste delete_into_pos(liste tail,int pos){

if (tail == NULL)
    {
        puts("liste khawa");
        return NULL;
    }
    if (tail == tail->next)
    {
        free(tail);
        return NULL;
    }

if(pos==1)return delete_head(tail);

liste tmp=tail->next;
while (pos>1)
{
 tmp=tmp->next;pos--;
}
tmp->prev->next=tmp->next;
tmp->next->prev=tmp->prev;

free(tmp);
if(tail==tmp)return tail->prev;
return tail;




}

void printf_liste(liste tail)
{

    if (tail == NULL)
    {
        printf("liste khawia");
        return;
    }
    liste tmp = tail;
    // do
    // {

    //     // printf("%d ", tmp->prev->data);
    //     // tmp = tmp->prev;
    //     printf("%d ", tmp->next->data);
  
    // } while (tmp != tail);
    //liste tmp=tail;
    // while(1){
    //     tmp=tmp->next;
    //     printf("%d ",tmp->data);
    //     if(tmp==tail)break;
    // }

    do
    {
        tmp=tmp->next;
        printf("%d ",tmp->data);
    } while (tail!=tmp);
    

}
void printf_rec_aide(liste head,liste tail){
//affiache inverfe avec recursion 
if(head==tail){
    printf("%d ",tail->data);// to show tail's data !importante
    return;
    //the base case should always be before the call or like the that the functione will go the infiniy of cour 
    //we should pay attention that the tail data's won't appear without that trick
}
printf_rec_aide(head->next,tail);//1
printf("%d ",head->data);//2
//1 then 2  will show the liste in the indericte order  2 then 1 will show it in the direct order

}
void printf_rec(liste tail){
if(tail)printf_rec_aide(tail->next,tail);
else puts("rien a afficher ");

}
void show_liste_inverse_ittertavlly(liste tail){

liste tmp=tail;
do 
{
printf("%d ",tmp->data);//awl valeur atkon hia d taill 
tmp=tmp->prev;//khasna ntl3o f liste


}
while (tmp!=tail);




}


int main()
{
    liste tail = NULL;
    int n = 14;

    for (int i = 1; i <= n; i++)
    {
        // printf(" enter the %d elements \n", i);
        // int tmp;
        // scanf("%d",&tmp);
        // tail = insert_liste_beg(tail, tmp);
        // tail = insert_liste_end(tail, i);
        // tail = insert_liste_beg(tail, i);
        insert_liste_begv2(&tail, i);
    }
   //  tail=insert_pos(tail,99,14);
    //    tail=delete_head(tail);
    //    tail=delete_head(tail);
    //    tail=delete_head(tail);
    //    tail=delete_head(tail);
    //    tail=delete_queque(tail);
    // tail = delete_queque(tail);
    // tail = delete_queque(tail);
    // tail = delete_queque(tail);
    // tail = delete_queque(tail);
    // apres la postion 6
//     printf_liste(tail);
//    tail=delete_into_pos(tail,13);
//  puts("");
    // printf_rec(tail);
    show_liste_inverse_ittertavlly(tail);
}