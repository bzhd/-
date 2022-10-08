//
// Created by 郑州工业应用技术学院图书馆 on 2022/9/15.
//
//邻接表法（顺序+链式存储）

#define MaxVertexNum 100

typedef int VertexType;
typedef struct ArcNode {
    int adjvex;
    ArcNode *next;
} ArcNode;
typedef struct VNode {
    VertexType data;
    ArcNode *first;
} VNode, AdjList[MaxVertexNum];
typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;
