#include <stdlib.h>
#include <stdio.h>



void find(int arr[],int target,int size,int output[2]){

int i=0;
//2,4,5,5,5,5,5,7,9,9
//              i
while (arr[i]!=target)
{
 i++;
}
output[0]=i;
while (arr[i]==target)
{
   i++;
}
output[1]=i-1;



}
int main(){


int arr[]={2,4,5,5,5,5,5,7,9,9}; 
// sorted array
int target=5;
int output[2];
find(arr,target,sizeof(arr)/sizeof(arr[0]),output);

printf("premier element %d deuxsime elment %d",output[0],output[1]);

    return 0;
}