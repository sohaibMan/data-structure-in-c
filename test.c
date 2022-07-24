#include <stdlib.h>
#include <stdio.h> 

void combine(int tab[],int s,int mid,int e){

int* buffer=malloc(sizeof(int)*(e-s+1));
for(int i=0;i<(e-s);i++)buffer[i]=tab[i+s];

// for(int i=s;i<=e;i++){
//     buffer[i-s]=a[i];
// }





}

void merge_rec(int tab[],int s,int e){

if(s>=e)return;

int mid=(s+e)/2;

merge_rec(tab,0,mid);
merge_rec(tab,mid+1,e);
combine(tab,s,mid,e);


}
// merge sort 
void merge(int tab[],int size){

merge_rec(tab,0,size-1);




}


int main(){

int tab[15]={8,6,9,1,3,7,4,10,-6,-100,1,6,3,6,7};

// {0,6,9,1,3,7,4,8,6,10,5};
// min=0
 

// merge(tab,sizeof(tab)/sizeof(tab[9]));

// for(int i=0;i<10;i++)
// {
// printf("%d\n",tab[i]);
// }




int a=3,b=4;
a*=b+=5;
printf("a=%d b=%d",a,b);












    return 0;
}