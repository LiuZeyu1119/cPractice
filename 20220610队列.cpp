#include <stdio.h>

#define MAX_SIZE 10

typedef struct{
    int data[MAX_SIZE];
    int front,rear;
}SqQueue;

void initQueue(SqQueue &Q){
    Q.rear = Q.front =0;
}

bool isEmptyQueue(SqQueue &Q){
    if(Q.front == Q.rear)return true;
    return false;
}
    
bool EnQueue(SqQueue &Q,int x){
    if((Q.rear+1)%MAX_SIZE == Q.front)return false;
    Q.data[Q.rear]=x;
    Q.rear = (Q.rear+1)%MAX_SIZE;
    return true;
}

bool DeQueue(SqQueue &Q,int &x){
    if(Q.rear == Q.front) return false;
    x = Q.data[Q.front];
    Q.front = (Q.front+1)%MAX_SIZE;
    return true;
}

int main(){
    int x = 0;
    SqQueue Q;
    initQueue(Q);
    printf("%d\n",EnQueue(Q,1));
    printf("%d\n",EnQueue(Q,2));
    printf("%d\n",EnQueue(Q,3));
    printf("%d\n",EnQueue(Q,4));

    printf("%d\n",DeQueue(Q,x));
    printf("%d\n",x);
    printf("%d\n",DeQueue(Q,x));
    printf("%d\n",x);
    printf("%d\n",DeQueue(Q,x));
    printf("%d\n",x);
    printf("%d\n",DeQueue(Q,x));
    printf("%d\n",x);
    printf("%d\n",DeQueue(Q,x));
    printf("%d\n",x);
}