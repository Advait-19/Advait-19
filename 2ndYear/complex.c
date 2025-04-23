#include <stdio.h> 
#include <stdlib.h>
typedef struct
{
    float real;
    float imag;
}Complex;

Complex AddComplex(Complex C1,Complex C2)
{
    Complex result;
    result.real=C1.real + C2.real;
    result.imag=C1.imag + C2.imag;
    return result;
}

void MultiplyComplex(Complex *C1,Complex *C2, Complex *result)
{
    result->real=C1->real*C2->real-(C1->imag*C2->imag);
    result->imag=C1->imag*C2->real+(C1->real*C2->imag);
}

int main()
{
    Complex C1,C2,result;
    int choice;
    printf("Enter the real and imaginary part of 1st complex number:");
    scanf("%f %f",&C1.real,&C1.imag);
    printf("Enter the real and imaginary part of 2nd complex number:");
    scanf("%f %f",&C2.real,&C2.imag);

    do{
    printf("\nMenu options:\n");
    printf("1. Addition of complex numbers\n");
    printf("2. Multiplication of complex numbers\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
        result=AddComplex(C1,C2);
        printf("Sum of complex numbers= %.2f+i%.2f",result.real,result.imag);
        break;
        case 2:
        MultiplyComplex(&C1,&C2,&result);
        printf("Product of complex numbers= %.2f+i%.2f",result.real,result.imag);
        break;
        case 3:
        printf("\nVisit us again");
        exit(0);
        break;
        default:
        break;
        }
    }
    while(choice!=3);
    {
       return 0;
    }   
}
