//
// Created by 郑州工业应用技术学院图书馆 on 2022/9/27.
//5叉排序树 B树as多路平衡查找树
typedef int BTreeNodeElemType;
struct Node {
    BTreeNodeElemType keys[4];
    struct Node *child[5];
    int num;
};