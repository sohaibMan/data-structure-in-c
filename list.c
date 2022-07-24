#include <stdlib.h>
#include <stdio.h>

// typedef struct  node{
// int data;
//  struct node *next;
// }node,*liste;

typedef struct node node;
typedef node *liste;
struct node
{
  int data;
  liste next;
};
liste DeletenTete(liste L)
{
  // kifach nam7i awl element mn list
  // khasni nchof wach liste khawia la kant khawia ma kain ma aitm7a7a
  //
  if (L == NULL)
  {
    puts("la liste est vide ,rien a supprimer");
    return L;
  }
  // bach nakhab3o l element  l li anm7aw kankhb3weh f wa7d tmp bach nams7oh morha kanbdlo l
  //  L->next  f L  haka anbdlweh blast ma aipwenti 3la awl element aipawnti 3la tani o morha n9dro nm7aw lwl li howa L li 7otina f tmp ms
  // L 9dim machi hada f7ali hozana l ponteur l mn lwl n tani o morha m7ina lwl but khasna nkhb3weh b3da 3ad nm7weh
  else
  {
    liste tmp = L;
    L = L->next;
    free(tmp);
    return L;
    //liste tmp=L->next;free(L);return tmp;
  }
}

liste DelteIntoposRec(liste L, int pos)
{
//recusion

  if (L == NULL ||pos < 1)
  {
    printf("Liste is empty\n");
    return L;
  } 
  if (pos == 1) return DeletenTete(L);
    L->next = DelteIntoposRec(L->next, pos - 1);
   return L;
}

liste DelteIntopos(liste L, int pos)
{
  //iterataive
  if (L == NULL)
  {
    printf("Liste is empty\n");
    return L;
  }
  
  
    if (pos == 1)
      return DeletenTete(L);
    else
    {
      liste p, q=L; 
// o n'a besoin de  2 pointeurs p  cuur o q next

      while ((pos > 2) && (q != NULL))
      {
        // rode blak  mn null.next == erorr
        // p = q; // pos hia 3 ya3ni khasek tzid 2 fois pos -1 3liha >1  (3 > 1  2 > 1 )=2 fois
        // incrementer la position de p
        q = q->next;
        pos--;
      }
      //? we have q in pos and p in pos-1 
      //? ida kona f q null ya3ni kan7walo nam7aw chi 7aja ga3ma kaina
      if (q != NULL)
      {
        // ida kharjana b q  not null
  p=q->next;

        q->next = p->next;//sauter (chainage)
        free(p);// howa l pos li khsan nm7aw
 
      }
      else
      {
        // ya3ni khorjna mn q ==null ya3ni tsalat list dyana f pos li baghi howa (element asln makianchi )
        puts("imposible de suprimer l'elements ( il n'exist pas ) ");
      }
        return L;
    
  }

  if (pos < 1)
  {
    puts("erreur");
    return L;
  }
}

liste DeletenQueque(liste L)
{
  // principe nwa9fo 9abal mn element lkhar bach n3tawh null o nm7aw lkhar alors on a besion de 2 pointeur
  if (!L)return NULL;
    // aucune elements a supprimer
    
    // un seull elemenet
    liste p = L;
    if (p->next == NULL)
    {
      free(p);
      // L = NULL;
      return NULL;
    }
    
      // plus d'un element
      liste q = L;
      while (q->next != NULL)
      {
        p = q;
        q = q->next;
      }

     //  !p est le dernier element  et q null  attention khasek test b q->next bach q twa9f a akhri elem li next dyalo null o p twa9f 9bal mn
      p->next = NULL;//chod listr
      free(q);//lhkar
      return L;//rode l haead
    
  
}

liste DeletenQuequeRec(liste L)
{
if(!L)return NULL;
if(!L->next) return DeletenTete(L);//atmsa7 L o trode null ( f hade l cas)
  L->next = DeletenQuequeRec(L->next);
  return L;
}



liste insertStack(liste L, int data)
{
  liste newNode = (liste)malloc(sizeof(node));
  newNode->data = data;
  newNode->next = L;
  return newNode;
}

void  inverse_listev1(node **head)
{
    // liste howa * noeud* 3ndi awla *liste makhsara f *liste=liste b had ma3na
    //head fih adrese dyal l head li f main (head li f had function howa pointeur 3la l head b yado li f main function (haz addrese dyalo )
    liste prev = NULL, next;

    // f lwl prev aikon howa null o next aikon khawi o tmp aikon how valeur li f head ( valeur d & head ) = contenu d lhead 
    // tmp pointeur 3la l valeur li f l head li f main 
    while(*head)
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
     *head=prev;// 3nda function void khasna l head li bara li 3nda l addrese dyalo n7oto f contenu dyalo l addrese dyal prev li howa akhir wa7d f liste 9dima
      // next aikhroj n null f7al f7al head li dariin while bih
    // o prev aikhroj b akhir elmenet next dyalo null (lkharr d liste ) lhead d liste jdida
}
//apple  inverse_listev1(&head);  inverse_liste_rec(&L1);
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


liste InssertQueque(liste L, int data)
{

  if (L == NULL)return insertStack(L, data);
  // list est vide
  else
  {
    liste newNode = (liste)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    // creating the last node (ba9i khsnana narbtoa akhit node bih)
    liste q = L;
    // bghina hit n3mlo copier n addresse d L
    while (q->next)q = q->next;

    q->next = newNode;

    return L;
    // trode awl element hit hada li zidnah zidnah f lkher
  }
}

liste insertquequeRec(liste L, int data)
{
  if (!L)
  {
    liste newNode = (liste)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
    //insertin in the stack 
  }
  else
  {
    L->next = insertquequeRec(L->next, data);
    return L;
  }
}

liste InsertIntoPos(liste L, int data, int pos)
{
  if (pos < 1)
  {
    printf("imposible d'insert dans %d", pos);
    return L;
  }

  else if (pos == 1)
    return insertStack(L, data);

  liste newNode = (liste)malloc(sizeof(node));
  newNode->data = data;

  // break the chaine
  // newNode khaso aipawnti 3la li morah(pos+1) o li 9abl mno khaso aipawani 3lih how nit
  liste q = L;
   while (pos>2 && q != NULL)
  {
    pos--;
    q = q->next;
  }
  if (q == NULL)
  {
    puts("imposible");
    return L;
  }

  newNode->next = q->next; // hadi fia l add dyal li morah (3ndk tkteb fiha)
  q->next = newNode;
  // db rabtna li 9abl mno b 1 b new newnode

  return L;
}
//
liste InsertIntoPosRec(liste L, int data, int pos)
{

  if (pos < 1)
  {
    printf("imposible\n");
    return L;
  }
   if (pos == 1) return insertStack(L, data);
   if (L == NULL)
  {
    puts("imposible");
    return L;
  }
  
   L->next = InsertIntoPosRec(L->next, data, pos - 1); // here
     return L;
}

void afficherNode(liste p)
{
  liste l = p;
  while (l != NULL)
  {
    printf("%d\n", l->data);
    l = l->next;
  }
}

void afficherNodeR(liste p)
{
  if (p)
  {
    printf("%d\n", p->data);
    afficherNodeR(p->next);
  }
}

int negativevalues(liste l)
{
  // return the miltiplication of negative values

  if (l == NULL)
    return 1;
  else if (l->data < 0)
    return l->data * negativevalues(l->next);
  else
    return negativevalues(l->next);
  // if the list is empty it will return 1
}

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

void test(liste L)
{

  // L->next=NULL;
  L = NULL;
  // HANA RA KANPSAW L espace memoire malloc li 3maranh f L ya3ni L dyana fih
  // l addresse dyal wa7d node bo7da li howa nit li kain f L ya3ni L dyana f test machi hia nafs L li kaina
  // f main kol wa7d wa addrese dyalo wa 7a9 alh walkin li baintom machratack howa ana
  // L li fl main o L li f test 3ndom  nafs fl valeuer dyalom nafs l addresed dyal poiintuer 3la
  // wa7d blasa fl memoire li hia li fiha data o next
  // ya3ni kholsat l9wal ida baldti chi 7aja fl valeur dyal l pointeur li how L awla no9oll L1
  // hit 9olna &l fl test != &l li fl main ya3ni li valeur dyalom b 2 fihom dak espace malloc

  // mohim ida bghina l v L nit li kain main khsana ndiro passage par addrese n L bydo
  // ya3ni &L haka ida baldna f l addrese li fiha L fl main ankonol bldna fihom b 2
}

// NA9DRO NBADLO L ES VALEUES LI KAIPWANTI 3LIHOM l MLI NDKHLO LIHJOM BL FOCNTION DYANA BUT MAND9ROCHI NDBALO l BYDO

void removeDuplicates(liste L)
{
  // here

  liste ptr1, ptr2, dup;
  ptr1 = L;

  /* Pick elements one by one */
  // ptr1 pour parcourir la liste kamlaaa mn lwl n lkhar
  //  o dak  ptr1 != NULL && ptr1->next blasat man3mlo 2 if ptr1->next == NULL zidnaha f while hit fa7ala
  while (ptr1 != NULL && ptr1->next != NULL)
  {
    // aiw9af la kant liste khawia awla next khawi
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

liste freeListe(liste p)
{

  if (p == NULL)
    return NULL;

  liste tmp = p->next;
  free(p);
  return freeListe(tmp);
  // ida kan p li dakhl bih null rod null ida kan tkan lae copi dak p f tmp hit ata7atjo bach t accede n element li maji
  // mora atm7ih howa o ta3it n li morah o nta machi ta twasal n null
}

liste reversev1(liste L)
{

  // reverse the order of the same liste

  liste tmp = L;
  liste new = NULL, tmp1 = NULL;
  while (tmp != NULL)
  {
    new = insertStack(new, tmp->data);
    tmp1 = tmp->next;
    free(tmp);
    tmp = tmp1;
    // ida bghiti ga3ma ta3ait n freeliste(L)
  }
  // msa7 liste 9dima daimn baste l mochkil dyalk
  // L = freeListe(L);
  return new;
}

int occurence(liste p, int data)
{
  if (p == NULL)
    return 0;

  if (p->data == data)
    return 1 + occurence(p->next, data);
  else
    return occurence(p->next, data);
}

void h1(liste list)
{

  liste p, q;
  int temp;
  if ((!list || !list->next))
    return;
  p = list;
  q = list->next;
  while (q)
  {
    temp = p->data;
    p->data = q->data;
    q->data = temp;
    p = q->next;
    q = p ? p->next : NULL;
  }
}

int count(liste L)
{

  if (L == NULL)
    return 0;
  else
    return 1 + count(L->next);
}
int prouidt_v(liste p)
{
  return p != NULL ? p->data * prouidt_v(p->next) : 1;
}
int produit(liste p)
{

  if (p == NULL)
    return 1;

  if (p->data % 3 == 0)
    return p->data * produit(p->next);
  else
    return produit(p->next);
}

void insert_sorted_liste(node **L, int data)
{
  // 1 3 4 5 //!7// 52 110
  // 7
  //  ASCENDING
  node *tmp = *L;

  if (!tmp)
  {
    *L = insertStack(tmp, data);
    return;
  }
  if (tmp->data > data)
  {
    *L = insertStack(tmp, data);
    return;
  }
  insert_sorted_liste(&tmp->next, data);
}

int sum_liste(liste L)
{
  return L == NULL ? 0 : L->data + sum_liste(L->next);
}
int sum(liste L1, liste L2)
{
  return sum_liste(L1) + sum_liste(L2);
}
int f(liste L){
  return (
    (!L) || (!L->next )|| (L->data <=L->next->data )&& f(L->next));
}


liste alternate(liste head1,liste head2){

  // we have two liste as inputs and one liste as out put 
  // L:A - B - C 
  // R:J - K -L 
  //LR A - J -B - K - C -L  D- M
  // this will alternate the addressee  not values (zipping )
 
  liste tail=head1;
  liste current1=head1->next,current2=head2;
  int counter=0;
  while (current1!=NULL && current2 !=NULL)
  {
    if (counter%2==0)
    {
   tail->next=current2;
   current1=current1->next;
    }
    else 
    {
   tail->next=current2;
   current2=current2->next;
    }
    tail=tail->next;
    
   counter++;
}
  if(current1!=NULL)tail->next=current1;
  if(current2!=NULL)tail->next=current2;
  
return head1;

}

int main()
{

  // liste head = NULL;
  //  liste second = NULL;
  //  liste third = NULL;

  // head=(liste)malloc(sizeof(node));
  // third=(liste)malloc(sizeof(node));
  // second=(liste)malloc(sizeof(node));

  // head->data=1;
  // head->next=second;
  // second->data=2;
  // second->next=third;
  // third->data=3;
  // third->next=NULL;
  // output(head);
  liste L1 = NULL;
  liste L2 = NULL;
  // for (int i = 0; i < 3; i++)
  // {
  // L1=insertStack(L1,i);
  // }
  // for (int i = 0; i <6; i++)
  // {
  // L2=insertStack(L2,i);
  // }
    L1=insertquequeRec(L1,0);
    L1=insertquequeRec(L1,1);
    L1=insertquequeRec(L1,2);
    L1=insertquequeRec(L1,3);
    L1=insertquequeRec(L1,4);
    L2=insertquequeRec(L2,7);
    L2=insertquequeRec(L2,8);
    L2=insertquequeRec(L2,9);
    L2=insertquequeRec(L2,10);
    L2=insertquequeRec(L2,11);
  L1=alternate(L1,L2);
  
   afficherNode(L1);

  // L = insertStack(L, 6);
  // L = insertStack(L, 5);
  // L = insertStack(L, 4);
  // L = insertStack(L, 3);
  // L = InssertQueque(L, 5);
  // L = insertStack(L, 4);
  // L = InssertQueque(L, 3);
  // L = insertStack(L, 2);
  // L = InssertQueque(L, 1);
  // printf("%d\n",f(L));
  
  // puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
  // L=DelteIntopos(L,3);
  //  afficherNode(L);

  // L=DeletenQuequeRec(L);
  // L=DeletenQuequeRec(L);

  // puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
  // afficherNode(L);
  // L = insertStack(L, 1);
  // L = InssertQueque(L, 1);
  // L = insertStack(L, 2);
  // L = InssertQueque(L, 2);
  // L = insertStack(L, 3);
  // L = InssertQueque(L, 3);
  // printf("%d\n", &L);
  // //test(L);

  // //?3 2 1 1 2  3
  // removeDuplicates(L);

  // L=insertStack(L,-114);
  // L=insertquequeRec(L,20);
  // L=insertStack(L,4);

  // L=insertStack(L,14);
  // L=insertStack(L,114);
  // L=insertStack(L,54);
  // liste desc=NULL;
  // desc=reverse(desc,L);
  // L=del1(L);

  // afficherNodeR(desc);
  // afficherNode(L);
  // puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
  // afficherNode(desc);
  // printf("%d\n",negativevalues(L));
  // printf("%d\n",count(L));
  // L=InsertIntoPos(L,40,54);
  // afficherNode(L);
  // afficherNodeR(L);
  // L=DeletenTete(L);
  // puts("wihtout the first elements");
  // afficherNode(L);
  // afficherNodeR(L);
  // 54 114  14 4 20 120
  // afficherNode(L);
  // DeletenQueque(L);
  // afficherNode(L);

  // 5 0  1 4 54 40
  // DeletenQuequeRec(L);

  // afficherNode(L);
  // 5 0  1 4 54
  // L=DelteIntopos(L,2);
  // 5 4 54 40 120
  // L=DelteIntopos(L,52);
  // puts("after deleting the last element");
  //  afficherNode(L);
  // liste L = NULL;
  //L = insertquequeRec(L, 120);
  // L=insertStack(L,54);
  // L = InsertIntoPos(L, 4, 1);
  // L = InsertIntoPos(L, 4, 1);
  // L = InsertIntoPos(L, 4, 1);
  // L = InsertIntoPos(L, 4, 1);
  // L = InsertIntoPos(L, 4, 1);
  // L = InsertIntoPos(L, 4, 1);
  // L = InsertIntoPos(L, 0, 1);
  // L = InsertIntoPos(L, 5, 1);
  // L = InsertIntoPosRec(L, 40, 5);
  // for (int i = 1; i <= 6; i++)
  //   L = insertquequeRec(L, i);
  // h1(L);
  // afficherNode(L);
  // L=DelteIntoposRec(L,5);
  // L=reversev1(L);
  //   afficherNode(L);
  // printf("%d",produit(L));

  // nombre d'occurence d;un element
  //  printf("%d\n",occurence(L,4));

  // L=freeListe(L);
  // afficherNode(L);
  //liste sorted = NULL;

  //   insert_sorted_liste(&sorted,14);
  //   insert_sorted_liste(&sorted,1);
  //   insert_sorted_liste(&sorted,15);
  //   insert_sorted_liste(&sorted,14);
  //   insert_sorted_liste(&sorted,1);
  //   insert_sorted_liste(&sorted,15);

  //   insert_sorted_liste(&sorted,-14);
  //   insert_sorted_liste(&sorted,143);
  //   insert_sorted_liste(&sorted,415);
  //   insert_sorted_liste(&sorted,3);
  //   insert_sorted_liste(&sorted,-1);
  //   insert_sorted_liste(&sorted,-1495);

  // afficherNode(sorted);
  //   liste L1=NULL;

  // liste L2=NULL;
  // L1=insertquequeRec(L1,1);
  // L1=insertquequeRec(L1,1);
  // L2=insertquequeRec(L2,'C');
  // L2=insertquequeRec(L2,'D');
  // printf("%d\n",sum(L1,L2));

  // afficherNode(sorted);
  

return 0 ;
}