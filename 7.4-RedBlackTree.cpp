//
// Created by az on 2022/9/25.
//
/*
 * 1.每个节点是黑色或红色
 * 2.根节点是黑色
 * 3.叶节点（外部节点、NULL节点、失败节点）均是黑色
 * 4.不存在两个相邻的红节点（即红节点的父节点和孩子节点均是黑色）
 * 5.对于每个节点，从该节点到任一叶子节点的简单路径上，所含黑节点的数目相同
 */
typedef struct RBNode{
    int key;
    RBNode* p;//父
    RBNode* l;//左
    RBNode* r;//右
    int color;
}RBNode,*RBTree;