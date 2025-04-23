#include <stdio.h>
struct Employee
{
    int emp_id,basic;
    char name[50],designation[50];
    float hra,da;
};

void main()
{
    int n,i;
    printf("Enter number of employees: ");
    scanf("%d",&n);

    struct Employee emp[n];

    for(i=0;i<n;i++)
    {
        printf("For Employee %d:\n",i+1);
        printf("Name:");
        scanf("%s",&emp[i].name);
        printf("Employee ID:");
        scanf("%d",&emp[i].emp_id);
        printf("Designation:");
        scanf("%s",&emp[i].designation);
        printf("Basic salary:");
        scanf("%d",&emp[i].basic);
        printf("HR Allowance:");
        scanf("%f",&emp[i].hra);
        printf("Daily Allowance:");
        scanf("%f",&emp[i].da);

    }
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        printf("Employee %d:\n",i+1);
        printf("Name: %s\n",emp[i].name);
        printf("Employee ID: %d\n",emp[i].emp_id);
        printf("Designation: %s\n",emp[i].designation);
        printf("Basic salary: %d\n",emp[i].basic);
        printf("HR Allowance: %f\n",emp[i].hra);
        printf("Daily Allowance: %f\n",emp[i].da);
        
        float gross= emp[i].basic + (emp[i].hra*emp[i].basic)/100 + (emp[i].da*emp[i].basic)/100;
        printf("Gross salary: %f ",gross);
    }    

}