#include <stdio.h>
#include <stdlib.h>
#define MaxSize 64
//定义栈
typedef struct 
{
   int data[MaxSize];
   int top;
}sqstack,*sqslink;

int EmptyStack(sqslink s)
{
    if(s->top < 0)
    {
        return 1;
    }else{
        return 0;
    }
}

int Push(sqslink s,int x)
{
    if(s->top>=MaxSize-1)
        return 0;
    else{
        s->top++;
        s->data[s->top] = x;
        return 1;
    }
}

int pop(sqslink s){
    if(EmptyStack(s) == 1){
        return NULL;
    }else
    {
        int n;
        n = s->data[s->top];
        s->top--;
        return n;
    }
}

int main(){
    sqslink s1;
    s1 = (sqslink)malloc(sizeof(sqstack)); //公式：(分配类型 *)malloc(分配元素个数 *sizeof(分配类型))
    
    printf("%d\n",s1->top);
    for(int i = 1;i<=66;i++)
    {
        if(Push(s1,i)==0) break;
        printf("%d has Pushed \n",i);
    }
    printf("top is pointed to %d \n",s1->top);
     for(int i = s1->top;i>0;i--)
    {
        printf("pop %d\n",pop(s1));
    }
   
    printf("top is pointed to %d \n",s1->top);
}