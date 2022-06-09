#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

struct Node{
    int data;
    int next;
};

typedef struct Node0
{
    int data;
    int next;
}SLinkList [MAX_SIZE];//第二种写法



int main(){
    struct Node a[MAX_SIZE];
    
    for(int i = 0;i<50;i++)
    {
        a[i].next=-2;
        printf("%d\n",a[i].next);//区别在于指针带下标时，以是数组形式访问，此时用“.”，如果不带下标（或使用偏移），此时用“->”
    }
    printf("%lu\n",sizeof(a));
    SLinkList b;
}