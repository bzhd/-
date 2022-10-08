//
// Created by az on 2022/8/24.
//


#include <cstdio>

typedef int LinkNodeDataType;

#include "3.4-LinkQueue.h"


int main() {
    LinkQueue Q;
    InitLinkQueue(Q);
    EnQ(Q, 1);
    EnQ(Q, 2);
    EnQ(Q, 1);
    EnQ(Q, 2);
    EnQ(Q, 1);
    EnQ(Q, 2);
    EnQ(Q, 1);
    EnQ(Q, 2);
    EnQ(Q, 1);
    EnQ(Q, 2);
    EnQ(Q, 1);
    EnQ(Q, 1);
    int x = 0;
    DeQ(Q, x);
    GetHead(Q, x);

    printf("%d %d %d", x, length(Q), IsEmpty(Q));
}