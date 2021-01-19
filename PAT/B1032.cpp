//
// Created by 章哲源 on 2021/1/17.
//
#include <stdio.h>
#include <string.h>

int main() {
    int n, index, score;
    scanf("%d", &n);
    int a[n];
    memset(a, 0, sizeof(a));
    for (int i=0;i<n;++i) {
        scanf("%d %d", &index, &score);
        a[index-1] += score;
    }
    index = 0; score = a[0];
    for(int i=0;i<n;++i) {
        if (a[i] >= score) {
            index = i + 1;
            score = a[i];
        }
    }
    printf("%d %d\n", index, score);
}
