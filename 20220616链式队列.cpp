#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *rear,*front;
}LinkQueue;

/*初始化队列，带头节点*/
void initQueue(LinkQueue &Q){
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next=NULL;
}

void enQueue(LinkQueue &Q,int x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

void enQueueWithOutHead(LinkQueue &Q,int x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    if(Q.front == NULL){
        Q.front = s;
        Q.rear = s;
    }else{
        Q.rear->next = s;
        Q.rear = s;
    }
}
void deQueue(LinkQueue &Q,int &x){
    if(Q.rear == Q.front)return;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if(p == Q.rear){
        Q.rear = Q.front;
    }
    free(p);
}

void deQueueWithOutHead(LinkQueue &Q,int &x){
    if(Q.front == NULL) return;
    LinkNode *p = Q.front;
    x = p->data;
    Q.front = p->next;
    if(Q.rear == p){
        Q.front = NULL;
        Q.rear = NULL;
    }
    free(p);
}

int main(){
    LinkQueue Q;
    initQueue(Q);
}