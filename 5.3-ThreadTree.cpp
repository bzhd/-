//
// Created by az on 2022/9/5.
//


#include <cstdlib>

struct ElemType {
    int value;
};
typedef struct ThreadNode {
    ElemType data;
    ThreadNode *l, *r;
    int ltag, rtag;
} ThreadNode, *ThreadTree;
ThreadNode *pre = NULL;

void InThread(ThreadTree T) {
    if (T != NULL) {
        InThread(T->l);
        if (T->l == NULL) {
            T->ltag = 1;
            T->l = pre;
        }
        if (pre != NULL && pre->r == NULL) {
            pre->rtag = 1;
            pre->r = T;
        }
        pre = T;
        InThread(T->r);
    }
}

void CreateInThread(ThreadTree T) {
    pre = NULL;
    if (T != NULL) {
        InThread(T);
        pre->r = NULL;
        pre->rtag = 1;
    }
}

void PreThread(ThreadTree T) {
    if (T != NULL) {
        if (T->l == NULL) {
            T->ltag = 1;
            T->l = pre;
        }
        if (pre != NULL && pre->r == NULL) {
            pre->rtag = 1;
            pre->r = T;
        }
        pre = T;
        if (T->ltag == 0)
            PreThread(T->l);
        PreThread(T->r);
    }
}

void CreatePreThread(ThreadTree T) {
    pre = NULL;
    if (T != NULL) {
        PreThread(T);
        pre->r = NULL;
        pre->rtag = 1;
    }
}

void PostThread(ThreadTree T) {
    if (T != NULL) {
        if (T->l == NULL) {
            T->ltag = 1;
            T->l = pre;
        }
        if (pre != NULL && pre->r == NULL) {
            pre->rtag = 1;
            pre->r = T;
        }
        pre = T;
        PostThread(T->l);
        PostThread(T->r);
    }
}

void CreatePostThread(ThreadTree T) {
    pre = NULL;
    if (T != NULL) {
        PostThread(T);
        pre->r = NULL;
        pre->rtag = 1;
    }
}

ThreadNode *FirstNode(ThreadNode *p) {
    while (p->ltag == 0)p = p->l;
    return p;
}

ThreadNode *NextNode(ThreadNode *p) {
    if (p->rtag == 0)return FirstNode(p->r);
    return p->r;
}