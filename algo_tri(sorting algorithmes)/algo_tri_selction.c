#include <stdio.h>




int main(){


int tab[]={4,14,1,5,1,5,6,7,8,9,0,99,5426,236,732,7,2,-2,-672,-652,-2542,623};

//ASCENDING
int n=sizeof(tab)/sizeof(tab[0]);

for(int i=0;i<n-1;i++){

int min=tab[i],min_indice=i;//we initialize the min with the first element of the array

for(int j=i;j<n;j++){

if(min>tab[j])
//switch from asc to desc
{
min=tab[j];
min_indice=j;
}
}
int tmp=tab[i];
tab[i]=min;
tab[min_indice]=tmp;

}

for (int i = 0; i < n; i++)
{
   printf("%d\n",tab[i]);
}

    return 0;

} 