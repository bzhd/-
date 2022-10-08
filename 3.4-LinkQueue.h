//
// Created by az on 2022/8/24.
//

#ifndef 数据结构_3_4_LINKQUEUE_H
#define 数据结构_3_4_LINKQUEUE_H

#include <cstdlib>
#include <cstdio>

typedef struct LinkNode {
    LinkNodeDataType data;
    struct LinkNode *next;
} LinkNode;
typedef struct {
    LinkNode *front, *rear;
} LinkQueue;


bool GetHead(LinkQueue Q, LinkNodeDataType x) {
    if (Q.front == Q.rear)
        return false;
    x = Q.front->next->data;
    return true;
}

bool IsEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

bool DeQ(LinkQueue &Q, LinkNodeDataType x) {
    if (IsEmpty(Q))
        return false;
    LinkNode *s = Q.front->next;
    x = s->data;
    Q.front->next = s->next;
    if (s == Q.rear)
        Q.rear = Q.front;
    free(s);
    return true;
}

void EnQ(LinkQueue &Q, LinkNodeDataType x) {
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;                           //尾插法
}


void InitLinkQueue(LinkQueue &Q) {
    Q.front = Q.rear = (LinkNode *) malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

int length(LinkQueue Q) {
    int len = 0;
    LinkNode *s = Q.front;
    while (s != Q.rear) {
        s = s->next;
        ++len;
    }
    return len;
}

#endif //数据结构_3_4_LINKQUEUE_H
