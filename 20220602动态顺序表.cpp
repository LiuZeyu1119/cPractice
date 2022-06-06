#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50
typedef struct
{
    char *name;
}elemType;

typedef struct
{
    elemType *data;
    int MaxSize,length;
}SqList;

void initList(SqList &L)
{
   L.data = (elemType*)malloc(sizeof(elemType)*MAX_SIZE);
   L.length = 0;
   L.MaxSize = MAX_SIZE;
}

bool insertList(int i,SqList &L,elemType e)//最好O(1)最坏O(n)平均O(n)
{
    if(i<1||i>L.length+1)//顺序表数据之间要紧密相接
    {
        return false;
    }
    if(L.length >= MAX_SIZE){
        return false;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e; //注意：数组下标为i-1
    L.length++;
    return true;   
}

bool deleteList(int i,SqList &L,elemType e)
{
     if(i<1||i>L.length+1)
    {
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

elemType getElem(SqList &L,int i ){
    return L.data[i-1];
}

int localElem(SqList &L,elemType e){
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (L.data[i].name == e.name)
        {
            return i+1;
        }
    }
    return 0;
    
}
int main(){
    SqList L;
    elemType e;
    elemType e1;
    e.name = "Bob";
    initList(L);
    insertList(1,L,e);
    deleteList(1,L,e1);
    return 0;
}