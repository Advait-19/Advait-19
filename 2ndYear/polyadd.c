#include <stdio.h>
void main()
{
    int i,j,m,n;
    printf("Enter highest degree of polynomial 1:");
    scanf("%d",&m);
    printf("Enter highest degree of polynomial 2:");
    scanf("%d",&n);
    int p1[m+1],p2[n+1];

    if(m<=n)
    {
        j=n+1;
    }
    else
    {
        j=m+1;
    }
    int sum[j];

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

    if(m<=n)
    {
        for(i=0;i<j;i++)
        {
            sum[i]=p2[i];
        }
    }
    else
    {
        for(i=0;i<j;i++)
        {
            sum[i]=p1[i];
        }
    }
 
    if(m<=n)
    {
        for(i=0;i<m+1;i++)
        {
            sum[i]=sum[i]+p1[i];
        }
    }
    else
    {
        for(i=0;i<n+1;i++)
        {
            sum[i]=sum[i]+p2[i];
        }
    }

    printf("Polynomial Sum =");
    for(i=0;i<j;i++)
        {
            printf("%dx^%d + ",sum[i],i);
        }
}