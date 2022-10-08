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
int Binary_Search(SSTable L,ElemType e){//二分查找/折半查找 不适用链表，因为链表不能随机访问
    int low=0,mid,high=L.TableLen-1;
    while (low<=high){
        mid=(low+high)/2;
        if(L.elem[mid]==e)
            return mid;
        else if(L.elem[mid]>e)
            high=mid-1;
        else
            high=mid+1;
    }
    return -1;
}
/*
向上取整    ⌈59/60⌉=1   ⌈-59/60⌉=0
向下取整    ⌊59/60⌋=0   ⌊-59/60⌋=-1
 */
