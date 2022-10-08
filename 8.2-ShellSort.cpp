#include <cstdio>
#include <cstdlib>
#include <ctime>

//
// Created by Admin on 2022/9/30.
//

void ShellSort(int a[], int n) {////仅适用于顺序表 不稳定 a[0]为暂存
    int d, i, j;
    for (d = n / 2; d >= 1; d /= 2) {
        for (i = d + 1; i <= n; ++i)
            if (a[i] < a[i - d]) {
                a[0] = a[i];
                for (j = i - d; j > 0 && a[0] < a[j]; j -= d)
                    a[]
            }


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
//    InsertSort(arr, 13);
    print(arr, 13);
}