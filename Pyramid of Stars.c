#include <stdlib.h>
#include <stdio.h>


// number of lines
void half_Pyramid_of_stars(int n){
    for(int i=1;i<=n;i++){
for(int j=1;j<=i;j++){
        printf("*");

}

        printf("\n");
    }

}
void half_Pyramid_of_number(int n){
    for(int i=1;i<=n;i++){
for(int j=1;j<=i;j++){
        printf("%d",j);

}

        printf("\n");
    }

}
void full_Pyramid_of_start(int n ){
static int i,j,k;

for(i=1;i<=n;i++){
for(k=0;k<n-i;k++)printf(" ");

for  (j=0; j <2*i-1; j++)
{
 printf("*"); 
}

printf("\n");
}


}
void half_Pyramid_of_Alphabets(int n){

    for(int i=1;i<=n;i++){
    for(int j=0;j<i;j++){
        // printf("%c ",'A'+j);
        printf("%c ",'A'+i);
}

        printf("\n");
    }

}
int main(){


int n=10;
//full_Pyramid_of_start(n);
//half_Pyramid_of_stars(n);
//half_Pyramid_of_number(n);
half_Pyramid_of_Alphabets(n);

    return 0;
}