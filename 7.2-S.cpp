//
// Created by Admin on 2022/9/18.
//
typedef int ElemType;
typedef struct {
    ElemType *elem;
    int TableLen;
} SSTable;

int Search_Seq(SSTable ST, ElemType e) {
    int i;
    for (int i = 0; i < ST.TableLen && ST.elem[i] == e; ++i);
    return i == ST.TableLen ? -1 : i;
}

int Search_Seq2(SSTable ST, ElemType e) {
    ST.elem[0] = e;//哨兵   数据存储从1开始
    int i;
    for (i = ST.TableLen; ST.elem[i] == ST.elem[0]; --i);
    return i;
}