#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 255
typedef struct
{
    char ch[MAXLEN];
    int length;
}SString; 
//方案一：最后一位为length
//方案二：首位为length（优点：位序与下标相同，缺陷：长度不能超过255）
//方案三：/0结尾,缺点：知道长度要遍历
//方案四：2+3，舍弃首位，尾为长度
typedef struct
{
    char *ch;
    int length;
}HString; 

typedef struct 
{
    char ch[4];
    struct String * next;
}StringNode,*String;
//char只占一个字节，struct占4个，存储密度低，所以一个节点存储四个字符；

int main(){
    HString S;
    S.ch = (char*)malloc(sizeof(char)); //首位为基地址
    S.length = 0;

    return 0;
}
