//
// Created by Admin on 2022/9/14.
//


#define MAX_TREE_SIZE 100
typedef int ElemType;
struct CTNode{
    int Child;//孩子在数组中的位置
    struct CTNode *next;
};
typedef struct {
    ElemType data;
    struct CTNode *firstChild;
}CTBox;
typedef struct {
    CTBox nodes[MAX_TREE_SIZE];
    int n,r;//节点数和根的位置
}CTree;