#include <stdio.h>
void main()
{
    int a,b,c,max,min;
    printf("Show the numbers\n");
    scanf("%d%d%d",&a,&b,&c);
    if(a>b) 
    {
    max=a;
    min=b;
    } 
    else
{
    max=b;
    min=a;
} 

    if(c>max) 
{
    max=c;
} 
    else if(c<min) 
{
   min=c;
}
   
   printf("Largest number=%d\n",max);
   
   printf("Smallest number=%d\n",min);
}   