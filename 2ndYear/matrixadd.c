#include <stdio.h>
void main()
{
    int m,n,i,j;
    printf("Enter no.of rows and columns of matrix 1:");
    scanf("%d %d",&m,&n);
    int arr1[m][n];
    printf("Enter the elements:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr1[i][j]);
        }
    }
    int count1=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
        {
            if(arr1[i][j]!=0)
                count1++;
        }
    }
    int p,q;
    printf("Enter no.of rows and columns of matrix 2:");
    scanf("%d %d",&p,&q);
    int arr2[p][q];
    printf("Enter the elements:\n");
    for(i=0;i<p;i++){
        for(j=0;j<q;j++)
        {
            scanf("%d",&arr2[i][j]);
        }
    }
    int count2=0;
    for(i=0;i<p;i++){
        for(j=0;j<q;j++)
        {
            if(arr2[i][j]!=0)
                count2++;
        }
    }
    int t1[count1+1][3],t2[count2+1][3];
    t1[0][0]=m;t1[0][1]=n;
    t2[0][0]=p;t2[0][1]=q;
    t1[0][2]=count1;
    t2[0][2]=count2;
    int row1=1;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
        {  
            if(arr1[i][j]!=0)
            {
                    for(int l=0;l<3;l++){
                        if(l==0){
                            t1[row1][l]=i;}
                        if(l==1){ 
                            t1[row1][l]=j;}
                        if(l==2){ 
                            t1[row1][l]=arr1[i][j];}
                    }
                    row1++;
            }
            
        }
    }  
    printf("3-tuple of Matrix 1:\n");
    for(i=0;i<row1;i++){
        for(j=0;j<3;j++){
            printf("%d ",t1[i][j]);
        }
        printf("\n");
    }
    int row=1;
    for(i=0;i<p;i++){
        for(j=0;j<q;j++)
        {  
            if(arr2[i][j]!=0)
            {
                    for(int l=0;l<3;l++){
                        if(l==0){
                            t2[row][l]=i;}
                        if(l==1){ 
                            t2[row][l]=j;}
                        if(l==2){ 
                            t2[row][l]=arr2[i][j];}
                    }
                    row++;
            }
            
        }
    }  
    printf("3-tuple of Matrix 2:\n");
    for(i=0;i<row;i++){
        for(j=0;j<3;j++){
            printf("%d ",t2[i][j]);
        }
        printf("\n");
    }
    

}