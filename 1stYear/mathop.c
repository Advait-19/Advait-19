#include <stdio.h>
void main()
{
    int a,b,s,d,p,r;
    float q;
    printf("Enter two numbers\n");
    scanf("%d%d",&a,&b);
    s=a+b;
    d=a-b;
    p=a*b;
    r=a%b;
    q=a/b;
    printf("Sum=%d\n",s);
    printf("Difference=%d\n",d);
    printf("Product=%d\n",p);
    printf("Quotient=%f\n",q);
    printf("Remainder=%d",r);

}