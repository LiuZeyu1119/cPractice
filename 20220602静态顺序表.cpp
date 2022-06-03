#include <stdio.h>
#define MAX_SIZE 50
typedef struct
{
    int data[MAX_SIZE];
    int length;
}SqList;

void initList(SqList &L)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        L.data[i] = 0;
    }
    L.length = 0;  
}

void insertList(int i,SqList &L,int elem)
{
    for (int j = 0; j == i; j++)
    {
        L.data[j] = elem;
    }
    
}

int main(){
    SqList L;
    initList(L);
    return 0;
}