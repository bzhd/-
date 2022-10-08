//
// Created by 郑州工业应用技术学院图书馆 on 2022/9/15.
//


#define MaxVertexNum 8
typedef struct {
    char Vex[MaxVertexNum];
//    bool Edge[MaxVertexNum][MaxVertexNum];
    int Edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
} Graph;
typedef int LinkNodeDataType;

#include "3.4-LinkQueue.h"

LinkQueue Q;
bool visited[MaxVertexNum];
int d[MaxVertexNum], path[MaxVertexNum];

void Init(Graph &G) {
    G.vexnum = G.arcnum = 0;
    for (int i = 0; i < MaxVertexNum; ++i) {
        visited[i] = false;
        for (int j = 0; j < MaxVertexNum; ++j) {
            G.Edge[i][j] = 0;
        }
    }
}

void visit(Graph G, int x) {
    printf("%c", G.Vex[x]);
}

bool Adjacent() {//判断图G是否存在边<x,y>或(x,y)

}

void Neighbors() {//列出图G中与节点x邻接的边

}

void InsertVertex() {//插入顶点x

}

void DeleteVertex() {//删除顶点x

}

void AddEdge() {//添加边

}

void RemoveEdge() {//删除边

}

int FirstNeighbor(Graph G, int x) {//x的第一个邻接点号
    for (int i = 0; i < G.vexnum; ++i)
        if (G.Edge[x][i] == 1)return i;
}

int NextNeighbor(Graph G, int x, int y) {//返回除y之外下一个邻接点号
    for (int i = y + 1; i < G.vexnum; ++i)
        if (G.Edge[x][i] == 1)return i;
    return -1;
}

void Get_edge_value() {//权值

}

void Set_edge_value() {//权值

}

void BFS(Graph G, int v) {
    visit(G, v);
    visited[v] = true;
    EnQ(Q, v);
    while (!IsEmpty(Q)) {
        DeQ(Q, v);
        for (int i = FirstNeighbor(G, v); i >= 0; i = NextNeighbor(G, v, i)) {
            if (!visited[i]) {
                visit(G, i);
                visited[i] = true;
                EnQ(Q, v);
            }
        }
    }
}

void BFS_Min_Distance(Graph G, int v) {
    for (int i = 0; i < MaxVertexNum; ++i) {
        d[i] = 9999;
        path[i] = -1;
    }
    d[v] = 0;
    visited[v] = true;
    EnQ(Q, v);
    while (!IsEmpty(Q)) {
        DeQ(Q, v);
        for (int i = FirstNeighbor(G, v); i >= 0; i = NextNeighbor(G, v, i))
            if (!visited[i]) {
                d[i] = d[v] + 1;
                path[i] = v;
                visited[i] = true;
                EnQ(Q, v);
            }//for-if
    }//while
}

void BFSTraverse(Graph G) {
    for (int i = 0; i < G.vexnum; ++i)
        visited[i] = false;
    InitLinkQueue(Q);
    for (int i = 0; i < G.vexnum; ++i)
        if (!visited[i])
            BFS(G, i);
}

void DFS(Graph G, int v) {
    visit(G, v);
    visited[v] = true;
    for (int i = FirstNeighbor(G, v); i >= 0; i = NextNeighbor(G, v, i)) {
        if (!visited[v])
            DFS(G, i);
    }
}

void CreateG(Graph &G) {
}

int main() {
}