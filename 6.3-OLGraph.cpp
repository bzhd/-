//
// Created by 郑州工业应用技术学院图书馆 on 2022/9/15.
//

//十字链表（有向图）
#define MAX_VERTEX_NUM 100
typedef int VertexType;
typedef struct ArcBox {   // 弧的结构表示

    int tailvex, headvex, info;
    struct ArcBox *hlink, *tlink;
} ArcBox;
typedef struct VexNode {// 顶点的结构表示
    VertexType data;
    ArcBox *firstin, *firstout;
} VexNode;

typedef struct {
    VexNode xlist[MAX_VERTEX_NUM];// 顶点结点(表头向量)
    int vexnum, arcnum;//有向图的当前顶点数和弧数
} OLGraph;