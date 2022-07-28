/*实际上是有限制的单链表，只能从一端添加和删除*/

#include <stdio.h>
#include <stdlib.h>

typedef int StackElementType;
typedef int Belongs_NewBull;
typedef struct node
{
    StackElementType data;
    struct node* next;
}SNode, *linkStack;
//typedef SNode* linkStack;
bool initStack(SNode* top){
    top = (SNode*)malloc(sizeof(SNode));
    if(top == NULL)return false;
    top->next = NULL;
    return true;
}

bool push(SNode* top,StackElementType n){
    SNode* p;
    p  = (SNode*)malloc(sizeof(SNode));
    p->data = n;
    p->next = top->next;
    top->next = p;
    return true;
}
StackElementType pop(SNode *top){
    StackElementType temp;
    SNode *p;
    p = top->next;
    if(p!=NULL){
        top->next = p->next;
        temp = p->data;
        free(p);
        return temp;
    }
    return -1;
    
}
int main(){
    SNode *S;
    if(initStack(S)){
        printf("true\n");
        push(S,1);
    }else
    {
        printf("False\n");
    }
    push(S,1);
    push(S,2);
    push(S,3);
    push(S,4);
    push(S,5);
    push(S,6);
    printf("pop:%d\n",pop(S));
    printf("pop:%d\n",pop(S));
    printf("pop:%d\n",pop(S));
    printf("pop:%d\n",pop(S));
    printf("pop:%d\n",pop(S));
    printf("pop:%d\n",pop(S));
    printf("pop:%d\n",pop(S));
    printf("pop:%d\n",pop(S));
    //printf("pop:%d\n",pop(S));
    return 0;
}