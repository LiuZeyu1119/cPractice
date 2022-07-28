#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
   int age;
   int height;
}elemType;

typedef struct Node
{
   elemType data;
   struct Node *next;   
}Node,*LinkList; //LinkList指向Struct Node的指针Node* 等价于 *LinkList

bool InitList(LinkList &L){
    L = (Node*)malloc(sizeof(Node)); //分配头节点
    if(L==NULL){
        return false;  //内存不足
    }
    L->next = NULL; //暂时无节点
    return true;
}

LinkList List_HeadInsert(LinkList &L){ //头插法建立
    Node *s;
    elemType x;
    int n;
    L = (LinkList)malloc(sizeof(Node));
    L->next=NULL;
    scanf("%d",&n);
    x.age = n;
    while (n != 9999)
    {
        s=(Node*)malloc(sizeof(Node));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&n);
        x.age = n;
    }
    return L;
}

LinkList List_TailInsert(LinkList &L){ //尾插法建立
    int n;
    elemType x;
    L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;
    Node *s,*r=L;                  
    scanf("%d",n);
    x.age = n;
    while (n != 9999)
    {
        s = (Node *)malloc(sizeof(Node));
        s->data=x;
        r->next=s;
        r=s;
    }
    r->next = NULL;
    return L;
}

Node *GetElem(LinkList L,int i){ //返回第i个节点
    if(i<0){
        return NULL;
    }
    Node *p; //指针p指向当前扫描的节点
    int j = 0;//当前p指向的是第几个节点
    p = L;//L指向头节点
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
    
}

Node* localElem(LinkList L,elemType e){
    Node* p = L->next;
    while (p!=NULL&&p->data.age!=e.age)
    {
        p = p->next;
    }
    return p;
}

bool Empty(LinkList L){
    if(L ->next == NULL){
        return true;
    }else{
        return false;
        
    }
}

int main(){
   LinkList L; //声明单链表指针
   InitList(L);//初始化单链表
    printf("%d,%d\n",L->data.age,L->data.height);
   printf("%p\n",&L);
   return 0;
} 

