//
// Created by 郑州工业应用技术学院图书馆 on 2022/9/15.
//
//邻接多重表（无向图）
#define MAX_VERTEX_NUM 100
typedef int VertexType;
typedef struct ArcNode {   // 边节点的结构表示

    int i, j;
    int info;
    struct ArcNode *ilink, *jlink;
} ArcNode;
typedef struct VexNode {// 顶点的结构表示
    VertexType data;
    ArcNode *firstedge;
} VexNode;

typedef struct {
    VexNode list[MAX_VERTEX_NUM];// 顶点结点(表头向量)
    int vexnum, arcnum;//有向图的当前顶点数和弧数
} OLGraph;