#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int manipulate(int num, int array[5]) {
    int arr[5];
    arr[0] = array[0];
    int factor = 9973;
   
    for (int i = 0; i < 5; i++) {
        arr[i] = (num + i) * factor;
    }
   
    
    for (int i = 0; i < 4; i++) {
       
        arr[i] = (arr[i] / (i + 1)) ^ (arr[i+1] % 10);
    }
   
    int result = 0;
    for (int i = 0; i < 5; i++) {
        result += arr[i] % 1000;  
    }

    return abs(result);
}

int main() {
    int array[5]={1,2,3,4,5};
    int num = 1234;  
   
    int final_result = manipulate(num,array);

   
    printf("PIN: %d#\n", final_result);  
    return 0;
}