#include <stdlib.h>
#include <stdio.h>
#define max 1000


void combine(int a[],int s,int m,int e){ 


int *buffer=malloc(sizeof(int)*(e-s+1));
for(int i=s;i<=e;i++){
    buffer[i-s]=a[i];
}
int i=s,j=m+1,k=s;
while(i<=m && j<=e){
    if(buffer[i-s]<=buffer[j-s]){
        a[k]=buffer[i-s];
        i++;
    }
    else{
        a[k]=buffer[j-s];
        j++;
     }
    k++;
}
// copy the rest of the left part of the array into the buffer or the right part of the array into the buffer (if one of the them exhausted before)
while(i<=m){
        a[k]=buffer[i-s];
        i++;k++;
 
}
while(j<=e){
  
        a[k]=buffer[j-s];
        j++;k++;
}
free(buffer);

}
void merge_help(int a[],int s,int e){
if(s>=e)return;//base case
int mid=(s+e)/2;
merge_help(a,s,mid);
merge_help(a,mid+1,e);
combine(a,s,mid,e);

}
void MergeSort(int a[],int n)
{
merge_help(a,0,n-1);



}
int main(){
int tab[max],tmp;


for(int i=0;i<max;i++)
{
tab[i]=rand();
}



MergeSort(tab,max);
for(int i=0;i<max;i++)
{
    // THE SORTED ARRAY
printf("%d \t",tab[i]);
}



}