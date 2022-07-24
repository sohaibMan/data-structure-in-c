#include <stdlib.h>
#include <stdio.h> 
#include <string.h>

void affiche(char array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c\n", array[i]);
    }
}
void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}


int partition(char array[], int low, int hight)
{
    
    int pivot_index = low + (rand() % (hight - low));// generate a random number between low and hight
    if (pivot_index != hight)swap(&array[pivot_index], &array[hight]);
    char pivot_value = array[hight];
    int i = low;
    for (int j = low; j < hight; j++)
    {
        if (array[j] <= pivot_value)
        {

            swap(&array[i], &array[j]);
            i++;
        }
    }
    swap(&array[i], &array[hight]);

    return i;
}

void quicksort_recursion(char array[], int low, int hight)
{

    if (low < hight)
    {
        int pivot_index = partition(array, low, hight);
        quicksort_recursion(array, low, pivot_index - 1);
        quicksort_recursion(array, pivot_index + 1, hight);
    }
}

void quicksort(char array[], int length)
{
    quicksort_recursion(array, 0, length - 1);
}

void sammeletters(char array1[],char array2[],int length){

for(int i=0;i<length;i++)
{
    if(array1[i]!=array2[i])
    {
        printf("they area not anagrams ");
        exit(0);
    }
}

}
void frequncy(char array1[],char array2[],int frqA[],int frqB[],int length){

quicksort(array1,length);
quicksort(array2,length);
sammeletters(array1,array2,length);
for (int i = 0; i < length;i++)
{
    frqA[i]=frqB[i]=-1;
}
for (int  i = 0; i < length; i++)
{
    int cmpt=1;
 for (int j = i+1; j < length; j++)
 {
   if(array1[i]==array1[j]){
cmpt++;
frqA[j]=0;
   }

 }
 
    if (frqA[i]!=0)
    {
         frqA[i]=cmpt;
   
    }

}

for (int  i = 0; i < length; i++)
{
    int cmpt=1;
 for (int j = i+1; j < length; j++)
 {
   if(array2[i]==array2[j]){
cmpt++;
frqB[j]=0;
   }

 }
 
    if (frqB[i]!=0)
    {
         frqB[i]=cmpt;
   
    }

}


// for (int  i = 0; i < length; i++)
// {
//     printf("%d->%c\n",frqA[i],array1[i]);

// }
int isanagrams=1;
for (int  i = 0; i < length; i++)
{
if(frqA[i]!=frqB[i]){
    isanagrams=0;break;
}
}

if (isanagrams)
{
   printf("yes it is anagrams ");
}
else printf("no it is not angaarams");

}

int main(){


char A[50],B[50];
int frqA[50],frqB[50];
puts("saisir la premier element ");
gets(A);
puts("saisir le deuxieme element ");
gets(B);

if(strlen(A)!=strlen(B)){
    printf("they are not anagrams\n");
    return 0;
}
// WE ASSUME THAT THEY ARE THE SAME LENGTH (LOOK ABOVE)
frequncy(A,B,frqA,frqB,strlen(A));
// strlen(B) =strlen(A)

}