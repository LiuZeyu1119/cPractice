#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10
typedef struct 
{
    char data[MAX_SIZE];
    int top;
}SqStack;

void initStack(SqStack &s){
    s.top = -1;    
}

bool isEmpty(SqStack &S){
    if(S.top == -1)return true;
    return false;
}

bool Push(SqStack &s,char x){
    if(s.top == MAX_SIZE - 1) return false;
    s.data[++s.top] = x;
    return true;
}

bool Pop(SqStack &s,char &x){
    if(s.top == -1) return false;
    x = s.data[s.top--];
    return true;
}

char backetMach(char b){
    if(b == ')') return '(';
    if(b == ']') return '[';
    if(b == '}') return '{';
    return 0;
}

int main(){
    SqStack s;
    initStack(s);
    char backets[] = "{()}";
    int length = strlen(backets);
    for(int i = 0;i < length;i++){
        if(backets[i] == '{' || backets[i] == '(' || backets[i] == '['){
            Push(s,backets[i]);
        }else{
            char topChar;
            Pop(s,topChar);
            if(backetMach(backets[i]) != topChar){
                return 0;
            }
        }
    }
    return 1;
}