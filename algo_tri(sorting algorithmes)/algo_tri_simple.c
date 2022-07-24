#include <stdlib.h>
#include <stdio.h>
#define max 1000
int main(){
int tab[max],tmp;


for(int i=0;i<max;i++)
{
tab[i]=rand();
}


for(int i=0;i<max;i++)
{
 for (int  j = i+1; j < max; j++)
 {
    
if(tab[i]>tab[j])//croissant
{
tmp=tab[i];
tab[i]=tab[j];
tab[j]=tmp;
}
}

}


for(int i=0;i<max;i++)
{
    // THE SORTED ARRAY
printf("%d \t",tab[i]);
}


}