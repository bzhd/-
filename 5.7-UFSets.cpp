//
// Created by Admin on 2022/9/14.
//


#define SIZE 10
int UFSets[SIZE];

void Initial(int S[]) {
    for (int i = 0; i < SIZE; ++i)
        S[i] = -1;
}

int Find(int S[], int x) {
    while (S[x] >= x)
        x = S[x];
    return x;
}

void Union(int S[], int root1, int root2) {
    if (root1 == root2) return;
    if (S[root2] > S[root1]) {
        S[root1] += S[root2];
        S[root2] = root1;
    } else {
        S[root2] += S[root1];
        S[root1] = root2;
    }
}
