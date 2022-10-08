//
// Created by az on 2022/8/15.
//



#include <cstdio>

#define MaxSize 10
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;



int LocateElem(SqList &L, ElemType e) {
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e)
            return i + 1;
    }
    return 0;
}

bool ListDelete(SqList &L, int i, ElemType &e) {
    if (i < 1 || i >= L.length)
        return false;
    e = L.data[i - 1];//带回删除的元素
    for (int j = i; j < L.length; ++j) {
        L.data[j - 1] = L.data[j];
    }
    --L.length;
    return true;
}

bool ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1)
        return false;
    for (int j = L.length; j >= i; --j) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    ++L.length;
    return true;
}

void InitList(SqList &L) {//初始化
    L.length = 0;
}
int main() {
    SqList L;
    InitList(L);
    printf("%d\n", L.length);
    for (int i = 0; i < 6; ++i) {
        ListInsert(L, 1, i);
    }
    printf("%d\n", L.length);
    for (int i = 0; i < L.length; ++i) {
        printf("%d", L.data[i]);
    }
    int e;
    ListDelete(L, 1, e);
    printf("%d\n", e);
    for (int i = 0; i < L.length; ++i) {
        printf("%d", L.data[i]);
    }
    printf("\n%d", L.data[LocateElem(L, 3)]);
    return 0;
}