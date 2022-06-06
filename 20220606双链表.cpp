#include <stdio.h>
#include <stdlib.h>

typedef struct DNode{
    int data;
    struct DNode *prior,*next;    
}DNode,*DLinkList;//节点，链表

bool initList(DLinkList &L){
    L = (DNode*)malloc(sizeof(DNode));//当malloc函数分配内存成功后,会返回一个void*类型的指针回来,而void*类型的指针又可被转换为任意类型的指针,所以在malloc函数前加强转和不加强转是等价的。
    if(L==NULL)return false;
    L->prior = NULL;
    L->next = NULL;
    printf("func:%p\n",L->prior);
    printf("func:%p\n",L);
    printf("func:%p\n",L->next);
    return true;
}

bool insertNode(DNode *p,DNode *s){
    if(p==NULL||s==NULL)return false;
    s->next = p->next;
    if(p->next != NULL){
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return true;
}

int main(){
    
    DLinkList L;
    initList(L);
    printf("main:%p\n",&L);
    printf("main:%ld\n",NULL);
    return 0;
}