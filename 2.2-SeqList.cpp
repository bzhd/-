//
// Created by az on 2022/8/15.
//

#include <cstdio>
#include <cstdlib>

#define Initsize 10
typedef struct {
    int *data;
    int MaxSize;
    int length;
} SeqList;

int LocateElem(SeqList &L, int e) {
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e)
            return i + 1;
    }
    return 0;
}

bool ListDelete(SeqList &L, int i, int &e) {
    if (i < 1 || i >= L.length)
        return false;
    e = L.data[i - 1];//带回删除的元素
    for (int j = i; j < L.length; ++j) {
        L.data[j - 1] = L.data[j];
    }
    --L.length;
    return true;
}
void IncreaseSize(SeqList &L, int len) {
    int *p = (int *) realloc(L.data, sizeof(int) * (L.MaxSize + len));
    L.data = p;

    L.MaxSize = L.MaxSize + len;
}
bool ListInsert(SeqList &L, int i, int e) {
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= L.MaxSize)
        IncreaseSize(L, 5);
    for (int j = L.length; j >= i; --j) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    ++L.length;
    return true;
}



void InitList(SeqList &L) {//初始化
    L.data = (int *) malloc(sizeof(int) * Initsize);
    L.length = 0;
    L.MaxSize = Initsize;
}


int main() {
    SeqList L;
    InitList(L);
    printf("%d\n", L.length);
    printf("%d\n", L.MaxSize);
    IncreaseSize(L, 5);
    printf("%d\n", L.MaxSize);
    for (int i = 0; i < 26; ++i) {
        ListInsert(L, 1, i);
    }
    printf("%d\n", L.length);
    for (int i = 0; i < L.length; ++i) {
        printf("%d", L.data[i]);
    }
    printf("\n%d\n", L.MaxSize);
    int e;
    ListDelete(L, 1, e);
    printf("%d\n", e);
    for (int i = 0; i < L.length; ++i) {
        printf("%d", L.data[i]);
    }
    printf("\n%d", L.data[LocateElem(L, 3)]);
    return 0;
}