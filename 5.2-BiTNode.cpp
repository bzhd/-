//
// Created by az on 2022/9/3.
//

#include <cstdio>


typedef int ElemType;
typedef struct BiTNode {
    ElemType data;
    BiTNode *l, *r;
} BiTNode, *BiTree;

typedef BiTNode* LinkNodeDataType;

#include "3.4-LinkQueue.h"

void visit(BiTree T) {
    printf("", T->data);
}

void NLR(BiTree T) {
    if (T == NULL)
        return;
    visit(T);
    NLR(T->l);
    NLR(T->r);
}

void LNR(BiTree T) {
    if (T == NULL)
        return;
    LNR(T->l);
    visit(T);
    LNR(T->r);
}

void LRN(BiTree T) {
    if (T == NULL)
        return;
    LRN(T->l);
    LRN(T->r);
    visit(T);
}

void Level(BiTree T) {
    LinkQueue Q;
    InitLinkQueue(Q);
    BiTree p;
    EnQ(Q, T);
    while (!IsEmpty(Q)) {
        DeQ(Q, p);
        visit(p);
        if (p->l != NULL)
            EnQ(Q, p->l);
        if (p->r != NULL)
            EnQ(Q, p->r);
    }

}
int main(){

}

