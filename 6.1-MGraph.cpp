//
// Created by 郑州工业应用技术学院图书馆 on 2022/9/15.
//
//邻接矩阵

#define MaxVertexNum 100
typedef struct {
    char Vex[MaxVertexNum];
//    bool Edge[MaxVertexNum][MaxVertexNum];
    int Edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
} MGraph;