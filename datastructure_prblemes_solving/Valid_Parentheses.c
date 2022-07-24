#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define n 150

 typedef struct  pile{
char tab[n];
int sommet;
  }pile;
  
//? piles ni plus utilise comme une tableaux
  int estVide(pile P){
   return P.sommet==-1;
  }

char sommet(pile P){
if(estVide(P))
{
    printf("Pile vide\n");
    exit(0);
}
else return P.tab[P.sommet];
}
int estPlein(pile P){
    return P.sommet==n-1;
    {
    // n-1 = taille de la pile
    // 1 si en ona dans le dernier elment de la pile (plien ) 0 si non
    //    1 2 3 4 5 6 7 8 9 10 (n==10)
    //-1  0 1 2 3 4 5 6 7 8 9
   // 0   0 0 0 0 0 0 0 0 0 1
   //hit bdina b -1
    }
}
pile intaliserPilevide(){
pile q;
q.sommet=-1;
return q;
}
pile empiler(pile P,char data){
    if(estPlein(P))
    {
        printf("Pile pleine\n");
        exit(0);
    }
   P.tab[++(P.sommet)]=data;
    return P;

//haka atabdel f pile nita
} 
pile depiler(pile P,char *x){
    if(estVide(P))
    {
        printf("Pile pleine\n");
        exit(0);
    }
   *x=P.tab[(P.sommet)--];
 
         return  P;

//haka atabdel f pile nita
}


pile afficherpile(pile P){
if(estVide(P))
{
    printf("Pile vide rien a afficher \n");
    exit(0);
}
pile q=intaliserPilevide();
while (!estVide(P))
{
 char x;
 P=depiler(P,&x);
 printf("%d\n",x);
q=empiler(q,x);
}
while (!estVide(q))
{
    char x;
    q=depiler(q,&x);
    P=empiler(P,x);
}
return P;

}
 void valider_parenthese(char *s){

 pile p=intaliserPilevide();
 int i=0;
 while (s[i]!='\0')
 {
 if(s[i]=='(' || s[i]=='{'  || s[i]=='[')
 {
p=empiler(p,s[i]);
 }
else 
 if(s[i]==')')
 {
if(estVide(p) || sommet(p)!='(')
    //awl element dakhl  ([{}]) 
    {
puts("Erreure! parenthese ferme qui n'a pas  ete ouvert");
    exit(0);
    }
else  {char c;p=depiler(p,&c);} 
 }
else if(s[i]==']')
//   || s[i]=='}'  || s[i]==']')
 {
if(estVide(p) || sommet(p)!='[')
    //awl element dakhl  ([{}]) 
    {
puts("Erreure! accolade ferme qui n'a pas  ete ouvert");
        exit(0);
    }
else  {char c;p=depiler(p,&c);} 
 }
else if(s[i]=='}')
 {
    if(estVide(p)|| sommet(p)!='{')
    //awl element dakhl  ([{}]) 
    {
puts("Erreure! chrocher ferme qui n'a pas  ete ouvert");
        exit(0);
    }
    else  {char c;p=depiler(p,&c);} 
 }
 i++;
 }
 if (!estVide(p))
 {
  printf("%c ouvert(e) eset pas ferme(e)",sommet(p)); 
 }
else puts(" toutes est justes !"); 

 }
int main(){
    //valider les parentheses dans une expression arithmetique
    //expression arithmetique = "(((1+2)*3)+4)" 
    //les parentheses sont des operateurs  ( ) [] {}
    /*
    Nous allons écrire une fonction permettant de valider le parenthèses, crochets
    et accolades dans une expression arithmétique.
        - La fonction doit assurer que chaque parenthese '(', crochet '[' ou accolade '{' ouvert
          est fermé dans le bon ordre.
        - L'expression arithmétique est passée sous forme d'une chaîne de caractères
          contenant des valeurs, des variables, des opérations arithmétique et des opérateurs
          (notre objectif est de vérifier si les parentheses sont valides seulement
          et non pas de vérifier que l'expression est bien formée).
*/
// li tafta7 lwl howa li aighla9 lkher -> pile (last in first out)



char expr[150];
puts("saisir une expression arithmetique");
gets(expr);
valider_parenthese(expr);




    return 0;
}