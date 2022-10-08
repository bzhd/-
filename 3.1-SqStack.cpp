//
// Created by az on 2022/8/20.
//


#include <cstdio>
#include <malloc.h>
typedef int ElemType;
#define MaxSize 10
typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;


void InitSqStack(SqStack &S) {
    S.top = -1;
}

bool StackEmpty(SqStack S) {
    return S.top == -1;
}

bool Push(SqStack &S, ElemType x) {
    if (S.top >= MaxSize || S.top < -1)
        return false;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, ElemType &x) {
    if (S.top > MaxSize || S.top <= -1)
        return false;
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, ElemType &x) {
    if (S.top > MaxSize || S.top <= -1)
        return false;
    x = S.data[S.top];
    return true;
}
int main() {

}
