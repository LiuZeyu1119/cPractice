#include <stdio.h>

#define MAX_SIZE 10

typedef struct 
{
    int data[MAX_SIZE];
    int front,rear;
    int size;
}SqQueue;

void initQueue(SqQueue &Q)
{   
    Q.front = Q.rear = Q.size=0;
}

bool isEmpty(SqQueue &Q){
    if(Q.size == 0)return true;
    return false;
}

bool EnQueue(SqQueue &Q,int x){
    if(Q.size == MAX_SIZE)return false;
    Q.data[Q.rear] = x;
    printf("ENQUE:%d\n",Q.data[Q.rear]);
    printf("ENQUE:%d\n",Q.data[Q.front]);
    Q.rear = Q.rear+1%MAX_SIZE;
    Q.size++;
    return true;
}

bool DeQueue(SqQueue &Q,int &x){
    if(Q.size == 0)return false;
    x = Q.data[Q.front];
    printf("DEQUE:%d\n",Q.data[Q.front]);
    Q.front = ((Q.front- 1)%MAX_SIZE) ;
    Q.size--;
    return true;
}

int main(){
    int x = 0;
    SqQueue Q;
    initQueue(Q);
    printf("E1:%d\n",EnQueue(Q,3));
    printf("E2:%d\n",EnQueue(Q,2));
    printf("E3:%d\n",EnQueue(Q,3));
    printf("E4:%d\n",EnQueue(Q,4));

    printf("D1:%d\n",DeQueue(Q,x));
    printf("%d\n",x);
    printf("D2:%d\n",DeQueue(Q,x));
    printf("%d\n",x);
    printf("D3:%d\n",DeQueue(Q,x));
    printf("%d\n",x);
    printf("D4:%d\n",DeQueue(Q,x));
    printf("%d\n",x);
    printf("D5:%d\n",DeQueue(Q,x));
    printf("%d\n",x);
}