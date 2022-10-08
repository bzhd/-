//
// Created by az on 2022/8/15.
//


#include <cstdio>
#include <malloc.h>

//===============================
//struct LNodeLinkList {
//    int data;
//    struct LNodeLinkList *next;
//};
//typedef struct LNodeLinkList LNodeLinkList;
//typedef struct LNodeLinkList *LinkList;
//===============================
typedef struct LNodeLinkList {
    int data;
    struct LNodeLinkList *next;
} LNode, *LinkList;



void InitList(LinkList &L) {
    L = (LinkList) malloc(sizeof(LinkList));
    L->next = NULL;
}
bool InsertPriorNode(LNode *p, int e) {
    if (p == NULL)
        return false;
    LNode *t = (LNode *) malloc(sizeof(LNode));
    t->next = p->next;
    p->next = t;
    t->data = p->data;
    p->data = e;
    return true;
}

bool InsertNextNode(LNode *p, int e) {
    if (p == NULL)
        return false;
    LNode *t = (LNode *) malloc(sizeof(LNode));
    t->next = p->next;
    p->next = t;
    t->data = e;
    return true;
}
LNode *GetElem(LinkList L, int i) {
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i) {
        p = p->next;
        ++j;
    }
    return p;
}
bool ListInsert(LinkList &L, int i, int e) {
    if (i < 1)
        return false;
    LNode *p = GetElem(L, i - 1);
    return InsertNextNode(p, e);
}

bool ListDelete(LinkList &L, int i) {
    if (i < 1)
        return false;
    LNode *p = GetElem(L, i - 1);
    LNode *q = p->next;
    p->next = q->next;
    free(q);
    return true;
}





LNode *LocateElem(LinkList L, int e) {
    LNode *p = L->next;
    while (p == NULL || p->data == e)
        p = p->next;
    return p;
}

int length(LinkList L) {
    int len = 0;
    LNode *p = L;
    while (p->next != NULL) {
        p = p->next;
        ++len;
    }
    return len;
}

LinkList List_TailInsert(LinkList &L) {
    int x;
    L = (LinkList) malloc(sizeof(LinkList));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;

}

LinkList List_HeadInsert(LinkList &L) {
    int x;
    L = (LinkList) malloc(sizeof(LinkList));
    L->next = NULL;
    LNode *s;
    scanf("%d", &x);
    while (x != 9999) {
        InsertNextNode(L, x);
        scanf("%d", &x);
    }
    return L;
}

void print(LNode *s) {
    while (s->next != NULL) {
        s = s->next;
        printf("%d", s->data);
    }
}

int main() {
    LinkList L;
    List_HeadInsert(L);
    print(L);

}