#include <stdlib.h>
#include <stdio.h>


typedef union marks{
    int score;//score is  number of the mark
    char mark;//mark is letter of the mark
}marks;
//? unions are used to store different types of data in the same memory location to save more memory space
//! the size of the union is the size of the largest type in the union


int main (){
marks noqta;
noqta.score=10;
printf("%d\n",noqta.score);
noqta.mark='A';
printf("%c\n",noqta.mark);



    return 0;
}