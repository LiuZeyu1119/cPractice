#include <stdio.h>
#define MAX_SIZE 50

typedef struct stack
{
    int data[MAX_SIZE];
    int top;  //栈顶指针
}SqStack; //sequence

typedef struct shareStack
{
    int data[MAX_SIZE];
    int top0;  //栈顶指针
    int top1;
}SQshareStack; //sequence

void InitStack(SqStack &S){
    S.top = -1;

}

void InitShareStack(SQshareStack &S1){
    S1.top0 = 0;
    S1.top1 = MAX_SIZE;
}

bool Push(SqStack &S,int elem){
    if(S.top == MAX_SIZE - 1) return false;//栈满
    //S.top++;
    //S.data[S.top] = elem;
    S.data[++S.top] = elem;//++top而不是top++，先加在执行
    return true;
}

bool Pop(SqStack &S,int &elem){
    if(S.top == -1) return false;
    elem = S.data[S.top--];
    return true;
}
bool getTop(SqStack &S,int &x){
    if(S.top == -1) return false;
    x=S.data[S.top];
    return true;
}
int main(){
    int i = 0;
    int x = 0;
    SqStack S;//分配了连续的内存空间
    SQshareStack S1;
    InitStack(S);
    printf("***************PUSH*****************\n");
    while(Push(S,1))
    {
        printf("%d\n",S.data[i++]);
    }
    printf("***************POP******************\n");
    i--;
    while (Pop(S,x))
    {
        printf("%d\n",S.data[i--]);
    }
    
}