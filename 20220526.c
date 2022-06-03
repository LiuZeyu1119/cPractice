/*约瑟夫环*/

#include <stdio.h>
#include <stdlib.h>

typedef struct  node
{
   int number;
   struct  node *next;   
}person;

person * initlink(int n){
    person *head = (person*)malloc(sizeof(person));
    head->number=1;
    head->next=NULL;

    person *cycle =head;

    for(int i = 2; i <= n;i++){
        person *body = (person*)malloc(sizeof(person));
        body->number=i;
        body->next=NULL;
        cycle->next=body;
        cycle=cycle->next;
    } 
    cycle->next=head;
    return head;
} 
void findAndKillK(person * head,int k,int m)
{

    person * tail = head;
    while (tail->next!=head)
    {
        tail=tail->next;
    }
    person *p =head;
    while (p->number!=k)
    {
       tail = p;
       p = p->next;
    }
    while (p->next!=p)
    {
   
        for(int i = 1; i < m ; i++)
        {
            tail = p;
            p=p->next;
        }
    }
    printf("%d\n",p->number);
    free(p);
}
int main(){
    int n = 5;//The number of person

}