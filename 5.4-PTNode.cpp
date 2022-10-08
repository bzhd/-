//
// Created by Admin on 2022/9/14.
//


#define MAX_TREE_SIZE 100
typedef int ElemType;
typedef struct {
    ElemType data;
    int parent;
}PTNode;
typedef struct {
    PTNode nodes[MAX_TREE_SIZE];
    int n;
}PTree;