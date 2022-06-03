#include <stdio.h>

void test(int *x){ 
    *x = 1024;
    printf("In test x = %d \n",*x);
}

int main(){
    int x = 1;
    printf("Before test x = %d \n",x);
    test(&x);
    printf("After test x = %d \n",x);
    return 0;
}