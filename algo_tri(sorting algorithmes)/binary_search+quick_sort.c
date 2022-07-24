#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50
#define z 9
// pivot is the first element of the array
void swap(int *x, int *y);
void quicksort(int array[], int length);
void quicksort_recursion(int array[], int low, int hight);
int partition(int array[], int low, int hight);
void affiche(int array[], int length);
int binarysearch_rec(int array[],int x,int s,int e);
int binarysearch(int array[],int length ,int x);

int main()
{

    int a[MAX];
    // srand(time(NULL));//seed (badra tghadi dak srand bach tab9a tgeneri lk new randome number)
  for (int  i = 0; i < MAX; i++)
  {
a[i]=i;
// a[i]=rand();
  }
  quicksort(a,MAX);
//   int x=9;
 if(binarysearch(a,MAX,z))printf("%d was found ",z);
 else printf("%d was  not found ",z);
    // affiche(a,MAX);

    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int array[], int length)
{
    quicksort_recursion(array, 0, length - 1);
}
int partition(int array[], int low, int hight)
{
    srand(time(NULL));
    int pivot_index = low + (rand() % (hight - low));// generate a random number between low and hight
    if (pivot_index != hight)swap(&array[pivot_index], &array[hight]);
    int pivot_value = array[hight];
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

void quicksort_recursion(int array[], int low, int hight)
{

    if (low < hight)
    {
        int pivot_index = partition(array, low, hight);
        quicksort_recursion(array, low, pivot_index - 1);
        quicksort_recursion(array, pivot_index + 1, hight);
    }
}

void affiche(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", array[i]);
    }
}
int  binarysearch_rec(int array[],int x,int s,int e){
int mid=(s+e)/2;
if(array[mid]==x)return 1;
else if(s>=e)return 0;
else  if(array[mid]>x)return binarysearch_rec(array,x,0,mid-1);
else return binarysearch_rec(array,x,mid+1,MAX-1);
}
int binarysearch(int array[],int length,int x){
if (!length)
{
    printf(" nothing to search for");
    return 0;
}

return binarysearch_rec(array,x,0,MAX-1);
}