#include <stdio.h>
void main()
{
    int i,j,m,n;
    printf("Enter highest power of polynomial 1:");
    scanf("%d",&m);
    printf("Enter highest power of polynomial 2:");
    scanf("%d",&n);
    int p1[m+1],p2[n+1];
    int result[m+n+1];
    

    printf("For Polynomial 1:\n");
    for(i=0;i<m+1;i++)
    {
        printf("Coefficient of x^%d=",i);
        scanf("%d",&p1[i]);
    }
    printf("For Polynomial 2:\n");
    for(i=0;i<n+1;i++)
        {
            printf("Coefficient of x^%d=",i);
            scanf("%d",&p2[i]);
        }

    for(i=0;i<n+1;i++)
    {
        for(j=0;j<m+1;j++)
        {
            result[i+j]=0;
        }
    }

    for(i=0;i<n+1;i++)
    {
        for(j=0;j<m+1;j++)
        {
            result[i+j]=result[i+j]+p2[i]*p1[j];
        }
    }
    
    int k=m+n+1;
    printf("Polynomial Multiplication =");
    for(i=0;i<k;i++)
        {
            printf("%dx^%d + ",result[i],i);
        }
}