#include <cstdio>
#include <cstdlib>
#include <ctime>

//
// Created by Admin on 2022/9/30.
//



//void InsertSort(int a[], int n) {//插入排序
//    int i, j, temp;
//    for (i = 1; i < n; ++i)
//        if (a[i] < a[i - 1]) {
//            temp = a[i];
//            for (j = i - 1; j >= 0 && a[j] > temp; --j)
//                a[j + 1] = a[j];
//            a[j + 1] = temp;
//        }
//}

void InsertSort(int a[], int n) {//a[0]作为哨兵，实际数据从a[1]开始
    int i, j, low, high, mid;
    for (i = 2; i < n; ++i)
        if (a[i] < a[i - 1]) {
            a[0] = a[i];
//            for (j = i - 1; a[j] > a[0]; --j)//a[0]不会大于a[0]
//                a[j + 1] = a[j];
            low = 1;//折半
            high = i - 1;
            while (low <= high) {
                mid = (low + high) / 2;
                if (a[mid] > a[0])high = mid - 1;
                else
                    low = mid + 1;
            }
            for (j = i - 1; j >= low; --j)
                a[j + 1] = a[j];
            a[j + 1] = a[0];
        }
}

void print(int a[], int n) {
    for (int i = 1; i < n; ++i) {
        printf("%d ", a[i]);
    }

}

void randA(int a[], int n) {
    srand((unsigned) time(NULL));
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % (100) + 1;
    }
}
int main() {
    int arr[13];
    randA(arr, 13);
    InsertSort(arr, 13);
    print(arr, 13);
}