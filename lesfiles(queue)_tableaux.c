#include <stdlib.h>
#include <stdio.h>

// les files queue (FIFO)
// enfiler  et defiler  estvide estpliene tete

#define TAILLE_MAX 50

typedef struct file
{
   int T[TAILLE_MAX]; // tab circulaire
   int tete;          // indice de la tete de la file
   int fin;           // incicde d'element disponible
} file;

int estVide(file f)
{
   return f.tete == f.fin;
}
int tete(file f)
{
   if (estVide(f))
   {
      printf("Liste vide\n");
      exit(0);
   }
   else
      return f.T[f.tete];
   // first in first out (queue)
}
int estpliene(file f)
{

   return f.tete == (f.fin + 1) % TAILLE_MAX;
}
void enfiler(file *f, int v)
{
  // printf("%d", v);

   if (estpliene(*f))
   {
      printf("tab plienne");
      exit(0);
   }
   else
      (*f).T[((*f).fin)++] = v;
   if ((*f).fin == TAILLE_MAX)
      (*f).fin = 0;
   //  (*f).fin%=n;
}
int defiler(file *f)
{

   if (estVide(*f))
   {
      printf("file vide");
      exit(0);
   }
   else
   {
      int x = (*f).T[((*f).tete)];
      (*f).tete = ((*f).tete + 1) % TAILLE_MAX;
      // (++(*f).tete)%= TAILLE_MAX;
      // (*f).tete======== f->tete
      return x;
   }
}

file intialiserfiler()
{

   file f;
   f.tete = 0;
   f.fin = 0;
   return f;
}

int main()
{

   file F = intialiserfiler();

   for (int i = 0; i < TAILLE_MAX -1; i++)
   {
      enfiler(&F, i);
   }
   for (int i = 0; i < TAILLE_MAX -1; i++)
   {
      printf("%d ", defiler(&F));
   }

   return 0;
}