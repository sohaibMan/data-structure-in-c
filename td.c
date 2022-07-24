#include <stdlib.h>
#include <stdio.h>

// 01 02 03 04
typedef struct noeud noeud;
typedef noeud *liste;

typedef struct noeud
{
    int data;
    liste next;
} noeud;

liste insertHead(liste L, int data)
{
    liste newnode = NULL;
    newnode = (liste)malloc(sizeof(noeud));
    newnode->data = data;
    newnode->next = L;
    return newnode;
}

void ShowList(liste L)
{

    if (L != NULL)
    {
        printf("%d \n", L->data);
        ShowList(L->next);
    }
}

int maxList(liste head)
{
    liste L = head;
    if (L == NULL)
    {
        printf("Liste vide\n");
        return 0;
    }
    int max = L->data;
    while (L != NULL)
    {

        if (L->data > max)
            max = L->data;
        L = L->next;
    }
    return max;
}

//! ex 01
int maxListRec(liste L)
{
    if (L == NULL)
        return 0;

    if (L->next == NULL)
        return L->data;

    int max = L->data;
    int max2 = maxListRec(L->next);
    if (max2 > max)
        max = max2;

    return max;
}

liste attacheListe(liste L1, liste L2)
{

    if (L2 == NULL)
    {
        printf("rien a ajouter\n");
        return L1;
    }
    liste tmp = L2;
    while (tmp != NULL)
    {
        L1 = insertHead(L1, tmp->data);
        tmp = tmp->next;
    }

    return L1;
}
//! 04
liste changeplaceliste(liste L, int i, int j)
{
    // who is the first and who is the next

    liste v, k;
    v = k = L;
    // khasana par defaut k howa li aikon sba9
    if (j > i)
    {
        int tmp = i;
        i = j;
        j = tmp;
    }
    // i>j

    while (i > 2 && v != NULL)
    {
        v = v->next;
        i--;
    }
    // v fait k
    while (j > 2 && k != NULL)
    {

        k = k->next;
        j--;
    }

    if (!k)
        return k;
    if (!v)
        return v;
    liste tmp1 = k->next, tmp2 = v->next;
    k->next = tmp1->next;
    v->next = tmp2->next;
    tmp2->next = v;

    return L;
}
liste InsertIntoPosRec(liste L, int data, int pos)
{

    if (pos < 1)
    {
        printf("imposible\n");
        return L;
    }
    else if (pos == 1)
        insertHead(L, data);
    else if (L == NULL)
    {
        puts("imposible");
        return L;
    }
    else
        L->next = InsertIntoPosRec(L->next, data, pos - 1);
}
int findpositon(liste L, int data)
{

    if (L == NULL)
        return 1;
    int pos = 1;
    while (L != NULL)
    {
        pos++;
        if (L->data == data)
            break;
        L = L->next;
    }

    return pos;
}

// void func1(liste L){

// while(L->next!=NULL){

// printf("%d \n",L->data);L=L->next->next;
// }
// }

liste insertStack(liste L, int data)
{
    liste newNode = (liste)malloc(sizeof(noeud));
    newNode->data = data;
    newNode->next = L;
    return newNode;
}

liste InssertQueque(liste L, int data)
{

    if (L == NULL)
        return insertStack(L, data);
    // list est vide
    else
    {
        liste newNode = (liste)malloc(sizeof(noeud));
        newNode->data = data;
        newNode->next = NULL;
        // creating the last node (ba9i khsnana narbtoa akhit node bih)
        liste q = L;
        // bghina hit n3mlo copier n addresse d L
        while (q->next != NULL)
            q = q->next;

        q->next = newNode;

        return L;
        // trode awl element hit hada li zidnah zidnah f lkher
    }
}
//! ex 02
liste reverse(liste dest, liste src)
{
    if (src == NULL)
        return dest;

    else
    {
        liste tmp = src;
        while (tmp != NULL)
        {
            dest = InssertQueque(dest, tmp->data);
            tmp = tmp->next;
        }
        return dest;
    }
}
//! ex 03 ( easy if else inserthead )
//

void spearate(liste L, liste *L1, liste *L2)
{
    liste tmp = L;

    while (tmp != NULL)
    {
        if (tmp->data >= 0)
            *L1 = insertHead(*L1, tmp->data);
        else
            *L2 = insertHead(*L2, tmp->data);
        tmp = tmp->next;
    }
}

//! ex 05
// 01
liste delete (liste L, int data)
{
    if (!L)
        return NULL;
    liste tmp, current = L;
    // ida kan l head fih data
    while (L && L->data == data)
    {
        current = L;
        L = L->next;   // lhead dyana fih data li kan9lbo 3lih alors khaso aitbdel
        free(current); // free current li howa l 9dima
    }
    if (!L)
        return NULL;
    current = L; // current ma fihachi data
    while (current->next)
    {
        if (current->next->data == data)
        {
            tmp = current->next;
            current->next = current->next->next;
            free(tmp);
        }
        else
            current = current->next;
        // dir while 3ad retourner lhead dyal liste
    }
    return L;
}

// 02
liste deletev1(liste L, int data, int k)
{
    if (!L)
        return NULL;
    if (k < 0)
        return L;
    if (k == 0)
        return delete (L, data);
    liste tmp = L;
    while (tmp)
    {

        if (tmp->data == data)
            k--; //
        if (k <= 0)
            break;
        tmp = tmp->next;
    }
    // ida kharjna b null mn while ya3ni  liste kamla ma fihachi k element mn data  dyna
    if (tmp)
        tmp->next = delete (tmp->next, data);

    return L;
}

// 03

liste deletev2(liste L)
{

    liste tmp = L;
    while (tmp)
    {

        L = deletev1(L, tmp->data, 1);
        tmp = tmp->next;
    }

    return L;
}
// 06:
//! using itterative way
liste inverse_liste(liste head)
{
    liste prev = NULL, next;
    while (head)
    {
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //?FIRST ONE
        next = head->next; // nkhab3o l addrese dyal next
        head->next = prev; // updating the head->next  to the last element (last head)(int the first time the preve is NULL)
                           //---------------------------------------------------------------------------------------------------------------------
                           //?next iteration
        prev = head;       // temp is the last element
        head = next;       // head is the next element
    }
    return prev; // next aikhroj n null f7al f7al head li dariin while bih
    // o prev aikhroj b akhir elmenet next dyalo null (lkharr d liste ) lhead d liste jdida
}
void inverse_listev1(noeud **head)
{
    // liste howa * noeud* 3ndi awla *liste makhsara f *liste=liste b had ma3na
    // head fih adrese dyal l head li f main (head li f had function howa pointeur 3la l head b yado li f main function (haz addrese dyalo )
    liste prev = NULL, next;

    // f lwl prev aikon howa null o next aikon khawi o tmp aikon how valeur li f head ( valeur d & head ) = contenu d lhead
    // tmp pointeur 3la l valeur li f l head li f main
    while (*head)
    {
        // * 3lach kaipwani l head li f main
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //?FIRST ONE
        next = (*head)->next; // nkhab3o l addrese dyal next ( we will need it)
        (*head)->next = prev; // updating the head->next  to the last element (last head)(int the first time the preve is NULL)
                              //---------------------------------------------------------------------------------------------------------------------
                              //?next iteration
        prev = (*head);
        *head = next;
    }
    *head = prev; // 3nda function void khasna l head li bara li 3nda l addrese dyalo n7oto f contenu dyalo l addrese dyal prev li howa akhir wa7d f liste 9dima
                  // next aikhroj n null f7al f7al head li dariin while bih
    // o prev aikhroj b akhir elmenet next dyalo null (lkharr d liste ) lhead d liste jdida
}
// apple  inverse_listev1(&head);  inverse_liste_rec(&L1);
//! using recursion way
liste inverse_liste_rec(liste head)
{
    if (head == NULL || head->next == NULL)
        return head;
    liste tmp = inverse_liste_rec(head->next);
    head->next->next = head;
    head->next = NULL;
    return tmp; // tmp is the last element of the liste
}
// ex 07

liste tab_liste(int tab[], int size)
{
    liste L = NULL;
    for (int i = 0; i < size; i++)
    {
        L = insertHead(L, tab[i]);
    }
    return L;
}
liste deplicate_liste(liste L)
{
    liste tmp = L, new = NULL;
    while (tmp)
    {
        new = insertHead(new, tmp->data);
        tmp = tmp->next;
    }
    return new;
}

// ex 09
//  tout les elemem
int prouidt_v(liste p)
{
    return p != NULL ? p->data * prouidt_v(p->next) : 1;
}

// que de positivie
int prouidt_v1(liste p)
{
    if (!p)
        return 1;

    else if (p->data >= 0)
        return p->data * prouidt_v1(p->next);
    else
        return prouidt_v1(p->next);
}
// que de negative
int prouidt_v2(liste p)
{
    if (!p)
        return 1;

    else if (p->data < 0)
        return p->data * prouidt_v1(p->next);
    else
        return prouidt_v1(p->next);
}
// ex 10
// LES deux au meme temps (utilisation de pointeur )
//  void prouidt_v1(liste p ,int *prod_pos,int *prod_neg)
//  ......
// ex 11

// fill a liste untile the user enter a number differnete from 0

liste user()
{
    int x;
    liste L = NULL;

    while (1)
    {
        printf("1 pour ajouter un autre elemenet autre pour sortir\n ");
        scanf("%d", &x);
        if (x != 1)
            break;

        printf("enter a value\n");
        scanf("%d", &x); // hnia wkha nafs x
        L = insertHead(L, x);
    }
    return L;
}

int main()
{

#define limit 5
    liste L1 = NULL;

    for (int i = 1; i <= limit; i++)
        L1 = InssertQueque(L1, i);
    // L1 = InssertQueque(L1, 37);
    // L1 = InssertQueque(L1, 3);
    // L1 = InssertQueque(L1, 2);
    // L1 = InssertQueque(L1, 12);
    // L1 = InssertQueque(L1, 2);

    // L1 = insertHead(L1, 3);
    // L1 = insertHead(L1, 3);
    // L1 = insertHead(L1, 31);
    // L1 = insertHead(L1, 3);
    // for (int i = 1; i <= limit; i++)
    //     L1 = InssertQueque(L1, 1);
    // L1 = InssertQueque(L1, 2);
    // L1 = InssertQueque(L1, 1);
    // L1 = InssertQueque(L1, 3);
    // L1 = InssertQueque(L1, 3);
    // L1 = InssertQueque(L1, 3);
    // puts("HI");
    // printf("%d\n", maxListRec(L1));
    // L1 = delete (L1, 2);
    //    L1 = delete(L1, 3);
    //    L1 = delete (L1, 3);
    // L1 = deletev1(L1, 3, 30); //,khali 4 d 3
    //    L1 = deletev1(L1,2,1); //,khali 2 d 1
    // L1 = deletev2(L1);
    //  liste L2 = NULL;
    //  for (int i = 51; i <= limit * 50; i++)
    //  {
    //      L2 = insertHead(L2, -i);
    //      L2 = insertStack(L2, i);
    //  }
    // ShowList(L1);
    // inverse_listev1(&L1);
    // puts("new list");
    // ShowList(L1);
    //  L1 = deletev1(L1, 2, 1); //,khali 2 d 1
    // printf("le max est %d\n",maxList(L));
    // printf("le max est %d\n", maxListRec(L2));
    // L1=attacheListe(L1,L2);
    //  ShowList(L1);
    // 1 2 3 4 5 6 7 8 9 10

    L1 = changeplaceliste(L1, 3, 5);
    // liste L3 = NULL;
    // liste L4 = NULL;
    // spearate(L2, &L3, &L4);
    // ShowList(L3);
    // puts("\n");

    ShowList(L1);

    // ShowList(L1);
    // 3 2 1 4 5 6 7 8 9 10

    // ShowList(L1);
    // 1 2 3 4 4 5 6 7 8 9 10
    // int tab[] = {1, 2, 3, 4, 5, 5,'q'};
    // tab to liste
    // liste L5 = tab_liste(tab, sizeof(tab) / sizeof(tab[0]));
    // ShowList(L5);

    return 0;
}