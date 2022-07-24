#include <stdlib.h>
#include <stdio.h>

int main(){

int tab[]={4,14,1,5,1,5,6,7,8,9,0,99,5426,236,732,7,2,-2,-672,-652,-2542,623};
//tri a bullles (bulles homa fo9a3at kaichbar 2 a 2 o kiarbtom
int n=sizeof(tab)/sizeof(tab[0]);
int k;
do 
{

   k=0;
// k = needs to be sorted more another time
    for(int i=0;i<n-1;i++)
    {
        //HNA SBA9IN B 1 ALORS KHSAN NWA9F N INCIDE N-1
        //t9dar tkhdam b 2 for loop , dak while gha bach na9so mn les nombres d'itteration

      if(tab[i]>tab[i+1])
      {
       int tmp=tab[i];
       tab[i]=tab[i+1];
       tab[i+1]=tmp;
       k=1;
      }
    }
}
while (k);
for (int i = 0; i < n; i++)
{
   printf("%d\n",tab[i]);
}

    return 0;
}