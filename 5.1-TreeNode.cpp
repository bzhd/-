//
// Created by az on 2022/9/3.
//


#define MaxSize 100
typedef int ElemType;
struct TreeNode {
    ElemType value;
    bool isEmpty;
};

void Init(TreeNode *T){
    for (int i = 0; i < MaxSize; ++i) {
        T[i].isEmpty = true;
    }
}

int main(){
    TreeNode T[MaxSize];
    Init(T);
}