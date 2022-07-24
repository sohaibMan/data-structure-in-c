
#include <stdlib.h>
#include <stdio.h> 
#include <math.h>

typedef struct  terme
{
int coef;
float val;

}terme;

typedef struct poly
{
 terme data;
 struct poly *next;

}poly,*pt_poly;

void addterme(pt_poly *p,int a ,float b){

pt_poly nouv = (pt_poly)malloc(sizeof(poly));
if(nouv==NULL){
printf("malloc failed");
exit(EXIT_FAILURE);
}
nouv->data.coef = a;
nouv->data.val = b;
nouv->next = *p;
*p=nouv; 

}

 float eval(pt_poly p,float x){

if(p==NULL)return 0;
 
else return p->data.val*pow(x,p->data.coef)+eval(p->next,x);


 }
int main(){

pt_poly p=NULL;

int x=0;



while (x!=-1)
{


printf("coef : \n");
int coef;
float val;
scanf("%d",&coef);
printf("val : \n");
scanf("%f",&val);
addterme(&p,coef,val);

 printf("ajouter  terme 1 si oui  -1 si non  \n");
   scanf("%d",&x);
 
}

printf("entre x pour calculer P(x) =\n");
float img;
scanf("%f",&img);
printf("P(%f) = %.2f\n",img,eval(p,img));

    return 0;
}