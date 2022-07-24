#include <stdlib.h>
#include <stdio.h>
int kth_larget_elment(int tab[],int kth,int size){

int index;int larg;
// we spouse that the largest element is  larg 
int arr[size],tmp;
for (int  i = 0; i < size; i++)
{
 arr[i]=tab[i];  
}
int counter=0;
for (int  i = 0; i < size; i++)
{
larg=arr[i];index=i;
for (int  j = i+1;j < size; j++)
{
if(arr[j]>larg)
{
larg=arr[j];
index=j;
}
}
tmp=arr[i];
arr[i]=arr[index];
arr[index]=tmp;
if(counter++==kth)break;
}

return arr[kth-1];




}
int main(){




int tab[10]={1,61,56,12,0,1,51,33,112,53};
int size=sizeof(tab)/sizeof(tab[0]);

printf("%d",kth_larget_elment(tab,4,size));






    return 0;
}