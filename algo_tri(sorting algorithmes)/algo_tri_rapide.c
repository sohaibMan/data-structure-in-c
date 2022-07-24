#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// pivot is the first element of the array
void swap(int *x, int *y);
void quicksort(int array[], int length);
void quicksort_recursion(int array[], int low, int hight);
int partition(int array[], int low, int hight);
void affiche(int array[], int length);

int main()
{

    int a[] = {4, 14, 1, 5, 1, 5, 6, 7, 8, 9, 0, 99, 5426, 236, 732, 7, 2, -2, -672, -652, -2542, 623};
    // int a[]={1,4,2,1,5,6,7,5,9,10};
    int length = sizeof(a) / sizeof(a[0]);
   // srand(time(NULL));//seed (badra tghadi dak srand bach tab9a tgeneri lk new randome number)
    
    // quicksort(a,length);
    // affiche(a,length);

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