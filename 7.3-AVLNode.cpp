//
// Created by az on 2022/9/25.
//平衡二叉树   修改最小不平衡子树
typedef struct AVLNode {
    int key;
    int balance;
    struct AVLNode *l, *r;
} AVLNode, *AVLTree;
void LL(AVLTree gf,AVLTree f,AVLTree p){
    f->l=p->r;
    p->r=f;
    gf->r=p;
}
void RR(AVLTree gf,AVLTree f,AVLTree p){
    f->r=p->l;
    p->l=f;
    gf->r=p;
}