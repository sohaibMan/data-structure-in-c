#include <stdlib.h>
#include <stdio.h>
#include <math.h>
// 12 hr =360*
//1 hr =360/12=30*
//1 hr=60min 

//---------------
// 60 minutes=360* 
//1 min =6*
//
float min(float a,float b){
    return ((a>b)? b:a);
}
float hours_to_degrees(float hours,float minutes){
if (!(hours>=0 || hours <=12))
{
 printf("set hours\n ");
 scanf("%f",&hours);
}
if (!(minutes>=0 || minutes <=60))
{
 printf("set minutes\n ");
 scanf("%f",&minutes);
}
float min_deg=minutes*6;
float hours_deg=((hours+(minutes/60))*30);
if((int)hours_deg==360)hours_deg=0;
//  to reset if clock is 12h if is devide it by 360 set it to 0

return min(abs(hours_deg-min_deg),360-abs(hours_deg-min_deg));



}

int main (){


printf("%f",hours_to_degrees(12,30));



    return 0;
}