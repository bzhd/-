//
// Created by az on 2022/8/23.
//




#include <cstdio>

#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int front, rear;
//    int size;
//    int tag;
} SqQueue;



int length(SqQueue Q) {
    return (Q.rear + MaxSize - Q.front) % MaxSize;
}

bool QueueEmpty(SqQueue Q) {
    return Q.front == Q.rear;
}

bool GetHead(SqQueue Q, int &x) {
    if (Q.front == Q.rear)
        return false;
    x = Q.data[Q.front];
    return true;
}

bool DeQ(SqQueue &Q, int &x) {
    if (Q.front == Q.rear)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

bool EnQ(SqQueue &Q, int x) {
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;

}

void InitQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;

}

int main() {
    SqQueue Q;
    InitQueue(Q);
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

    GetHead(Q, x);

    printf("%d %d %d %d %d", x, Q.front, Q.rear, length(Q), QueueEmpty(Q));
}