//
// Created by az on 2022/8/23.
//

#include <cstdio>
#include <malloc.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} *LiStack;


void print(LiStack S) {
    while (S != NULL) {
        printf("%d", S->data);
        S = S->next;
    }
}

bool StackEmpty(LiStack S) {
    return S == NULL;
}
bool GetTop(LiStack S, int &x) {
    if (StackEmpty(S))
        return false;
    x = S->data;
    return true;
}


bool Pop(LiStack &S, int &x) {
    LiStack l = S;
    x = S->data;
    S = S->next;
    free(l);
    return true;
}

bool Push(LiStack &S, int x) {
    LiStack l = (LiStack) malloc(sizeof(LinkNode));
    l->data = x;
    l->next = S;
    S = l;
    return true;
}

void InitLiStack(LiStack &S) {
    S = NULL;
}

int main() {
    LiStack S;
    InitLiStack(S);
    Push(S, 1);
    Push(S, 2);
    print(S);
}