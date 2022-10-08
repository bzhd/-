//
// Created by Admin on 2022/9/14.
//


typedef int ElemType;
typedef struct CSNode{
    ElemType data;
    CSNode *firstChild,*nextsibling;
}CSNode, *CSTree;