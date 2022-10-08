//
// Created by az on 2022/8/20.
//


#include <cstdio>
#include <malloc.h>

typedef struct DNodeLinkList {
    int data;
    struct DNodeLinkList *prior, *next;
} DNode, *DLinkList;

bool DeleteNextDNode(DNodeLinkList *p) {
    if (p == NULL)
        return false;
    DNodeLinkList *q = p->next;
    if (q == NULL)
        return false;
    p->next = q->next;
    if (p->next != NULL)
        p->next->prior = p;
    free(q);
    return true;
}
void DestoryList(DLinkList &L) {
    while (L->next != NULL)
        DeleteNextDNode(L);
    free(L);
    L = NULL;
}



bool InsertNextDNode(DNodeLinkList *p, DNodeLinkList *s) {
    if (p == NULL || s == NULL)
        return false;
    s->next = p->next;
    p->next = s;
    if (p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    return true;
}

void InitDLinkList(DLinkList &L) {
    L = (DLinkList) malloc(sizeof(DLinkList));
    L->next = NULL;
    L->prior = NULL;
}

int main() {
    DLinkList L;
    InitDLinkList(L);

}
