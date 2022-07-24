#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// one root of the tree
// every node should have at most 2 nodes(childs)
// exactly one path b/w root and any node(no cycle)

typedef struct arbre
{

    int value;
    struct arbre *left;
    struct arbre *right;
    // struct arbre *parent;
    // we study the trees wihout parents
} arbre, *pt_arbre;

pt_arbre new_node(int data)
{
    pt_arbre new_tree = (pt_arbre)malloc(sizeof(arbre));
    if (new_tree == NULL)
    {
        printf("Erreur d'allocation\n");
        exit(EXIT_FAILURE);
    }

    new_tree->value = data;
    new_tree->left = NULL;
    new_tree->right = NULL;
    // new_tree->parent = NULL;
    // attention à ne pas oublier de renseigner le parent
    // printf("Nouveau noeud cree %d\n", new_tree->value);
    return new_tree;
}

void clean_pt_arbre(pt_arbre tr)
{

    if (tr == NULL)
        return;

    clean_pt_arbre(tr->left);
    clean_pt_arbre(tr->right);
    free(tr);
}

void prefixe(pt_arbre tr)
{

    if (tr == NULL)
        return;

    printf("------------------------------------------------------\n");

    // if (tr->parent != NULL)
    //     printf("Noeud %d parent %d\n", tr->value, tr->parent->value);
    // else
    printf("Noeud %d  \n", tr->value);
    // ida kan l parent null alors on ne peut  pas affiche sa valeu !error
    prefixe(tr->left);
    prefixe(tr->right);
}
// pre aff f lwl in aff f west pos aff f lkhar
//  VOIR L EXEMPLE (SCREEEN SHOOT)
//! POSFIXE : h c i l j d a k e f b r
//! INFIXE  : c h a i d l j r k e  b f
//! PREFIXE : r a c h d i j l  b e k f

pt_arbre join(pt_arbre left, pt_arbre right, int data)
{

    pt_arbre tr = new_node(data);
    tr->left = left;
    tr->right = right;

    // if (left != NULL)
    //     left->parent = tr;
    // if (right != NULL)
    //     right->parent = tr;
    // fa7alat la kant 3nda gha right o left la (Null)
    return tr;
}
// !  binary trees

void insertnumber(arbre **tree, int value)
{

    // root fiha ach f malloc  ya3ni l adderse dyal
    // wa7d structure arbre **tree fiha l adrese li haza had l adrese dyal had
    // arebre li hia malloc
    if (!(*tree))
    {
        // ida ga3ma kan 3nda root
        (*tree) = new_node(value);
        // f wasal mn had tree anroda katpwanti 3la new_node
        return;
    }
    if (value == (*tree)->value)
    {
        // do nothing
        // aready exist
        // do not accepte diplacted value
        return;
    }
    if (value < ((*tree)->value))
        return insertnumber(&((*tree)->left), value);
    else
        return insertnumber(&((*tree)->right), value);
}
int searchfor(arbre *tr, int value)
{

    if (!tr)
        return 0;
    else if (tr->value == value)
        return 1;
    else
        return searchfor(tr->left, value) + searchfor(tr->right, value);
}
bool findnumber(pt_arbre root, int value)
{
    // a single pointue is enought to acces to malloc here (la strucutre li fiha donnes dyana)
    //  gam3a anbdlo f tree ghi an9lbo
    if (root == NULL)
        return false;
    if (root->value == value)
        return true;

    if (root->value > value)
        return findnumber(root->right, value);
    else
        return findnumber(root->left, value);
}

int count_nodes(pt_arbre tr)
{
    return (tr == NULL) ? 0 : 1 + count_nodes(tr->left) + count_nodes(tr->right);
}
int sum_nodes(arbre *tr)
{

    if (!tr)
        return 0;
    else
        return tr->value + sum_nodes(tr->left) + sum_nodes(tr->right);
}
int print_node(arbre *tr)
{
    if (tr)
    {
        printf("%d \n", tr->value);
        return 1;
    }
    else
        return 0;

}
// queque stryax

;

typedef struct queue
{
    arbre *val;
    //  bach aihozo adresse dyal wa7d l arbre
    struct queue *next;

} queue;

void insert_tree_adresse_to_queue(queue **head, arbre *tr)
{

    queue *new_node = (queue *)malloc(sizeof(queue));
    new_node->val = tr;
    new_node->next = NULL;
    queue *q = *head;
    if (!q)
    {
        // liste is empty (firt elment)
        new_node->next = NULL;
        *head = new_node;
        return;
    }
    while (q->next)
    {
        q = q->next;
    }
    q->next = new_node;
}
void pop_tree_adresse_to_queue(queue **head)
{

    // we gonna delete the head
    if (!(*head))
        return;
    queue *tmp = (*head)->next;
    free(*head);
    *head = tmp;

    // *head=NULL;
}

// arbre * implement_rec(arbre *tr,int data){

// arbre*tr=new_node(data);
// puts("L CHIL -1 IF NOT ");
//     int x;
//     scanf("%d",&x);
// if(x!=-1){
// tr=join(new_node(x));
// }
  


// return tr;

// }

// arbre * implement(arbre *tr){
//     printf("sair un nombre\n");
//     int x;
//     scanf("%d",&x);
// return implement_rec(tr,x);
//}
void levelorder(arbre *tr)
{

    // Parcours en largeur(nivaux par nivaux)
    //          F
    // D                  J
    // B  E                G   K
    // A    C               I
    //                   H
    // queque fifo
    // F D J
    // UNE FOIS ANKHOD CHILD DYALO AN3MLO POP + PRINT
    // D J B E , B E WLAD LWL D
    //   E  G K A C  , printt D
    // FIRST ONE HOWA VISTED UN FIOS KANJIBO WALDO NZIDOHOM F QUEUE KAN7WEH O NPRITAWH O NJBDO WALD LI MORAH O NTA GHADI

    if (!tr)
        return;
    queue *head = NULL;
    insert_tree_adresse_to_queue(&head, tr);
    while (head)
    {
        arbre *current = head->val;
        printf("%d ", current->value);

        if (current->left)
            insert_tree_adresse_to_queue(&head, current->left);

        if (current->right)
            insert_tree_adresse_to_queue(&head, current->right);
        pop_tree_adresse_to_queue(&head);
        //  insert_tree_adresse_to_queue will insert intot the queue (file)
        // pop_tree_adresse_to_queue(&head);  will delte the head ( supprimer le premier element)
    }
}

float max_tree(arbre *tr)
{

    if (!tr)return -INFINITY;
    float max1 = max_tree(tr->left);
    float max2 = max_tree(tr->right);
    float max = tr->value;
    if (max1 > max)
        max = max1;
    if (max2 > max)
        max = max2;
    return max;
}
float min_tree(arbre *tr)
{

    if (!tr)return INFINITY;
    float min1 = min_tree(tr->left);
    float min2 = min_tree(tr->right);
    float min = tr->value;
    if (min1 < min)
        min = min1;
    if (min2 < min)
        min = min2;
    return min;
}
int max(int a,int b){
    return a>b ? a:b;
}
int hieght(arbre *tr){
// the longest parth from the root nood to the last leaves
if(!tr)return -1;
int left=hieght(tr->left);
int right=hieght(tr->right);
return max(left,right)+1;

}
int is_subtree_lesser(arbre * tr, int value ){
return tr->value<value;
}
int is_subtree_greeter(arbre * tr, int value ){
return tr->value>value;
}
int is_binary_tree(arbre *tr){
if(
   tr==NULL
 &&is_subtree_lesser(tr->left,tr->value)
 &&is_subtree_greeter(tr->right,tr->value)
 &&is_binary_tree(tr->left)
 &&is_binary_tree(tr->right)
)
return 1;
else return 0;
}
int main()
{

    //  pt_arbre tr = join(new_node(1),new_node(2),3);
    //     3
    //    1 2
    // the root element is tr (parent)

    // printf("%d\n",(tr->value));

    // printf("%d\n",(tr->right)->value);

    // printf("%d\n",(tr->value);

    // printf("%d\n",(tr->left->parent)->value);

    //  6
    // 2    4
    // 8  3

    // pt_arbre tr1 = join(join(new_node(8), new_node(3), 2), new_node(4), 6);
    //  prefixe(tr1);
    // printf("le nombre de nodes est %d\n", count_nodes(tr));

    pt_arbre btr=NULL;
    for(int i=0;i<100;i++)insertnumber(&btr,rand());
    printf("%d",is_binary_tree(btr));
    // it is so fast if the numbre is not sorted and the tree is not balanced
    // printf("find number %d\n",findnumber(btr,5));
    // prefixe(btr);

    //  6
    // 2 4
    // 8  3
    //  6 2 4 8 3

    // levelorder(tr1);
    // if(searchfor(tr1,15))printf("found");
    // else printf("doesn't found");
    // printf("%d",sum_nodes(tr1));

//     pt_arbre tr1 = join(join(new_node(81), new_node(23), 32), new_node(43), 9);
//   printf("%d",hieght(tr1));

  //  clean_pt_arbre(tr1);

    return 0;
}