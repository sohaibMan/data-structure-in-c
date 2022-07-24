#include <stdlib.h>
#include <stdio.h>

int main(){




    // how it works
    /*

5 1 4 2 5 3 7 9 8 10
a i=0   var =5;j=-1; tab[0]=5; nothing change in i=0 ya3ni ofc n9dro ndaw boucle dyana mn 1
a i=1  var =1;j=0;  tab[0]=5  > var=1 tab[1]=tab[0] j=-1 tab[0]=1
1  4 5 2 3 7 9 8 10
i=2 j=1
.......

    */

int tab[]={4,14,1,5,1,5,6,7,8,9,0,99,5426,236,732,7,2,-2,-672,-652,-2542,623};
int size=sizeof(tab)/sizeof(tab[0]),i,j,var;

for(i=1;i<size;i++)
{
    // andoro 3la ga3 les elements li kainin f tab 

j=i-1;
var=tab[i];
    // wa7d tab li kaibda mn 0 tan i-1 (les element li 9abl mn var dyana)
while (j>=0 && tab[j]>var)
{
    tab[j+1]=tab[j];
    j--;
}
tab[j+1]=var;


}
for(i=0;i<size;i++)
{
    printf("%d\n",tab[i]);
}















return 0;
}