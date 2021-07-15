//
// Created by 章哲源 on 2021/7/12.
//

#include <iostream>
#include <algorithm>

// 快排模版
void quick_sort(int q[], int l, int r) {
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while(i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    // x取l + r >> 1，则子区间为(l,j)和(j+1,r)
    // x取(l + r + 1) >> 1,则子区间取(l,j-1)和(j,r)
    // 为了避免[0,1] -> [0,1]的无限循环
    quick_sort(q, l, j), quick_sort(q, j+1, r);
}

// 归并模版
void merge_sort(int q[], int l, int r) {
    if (l >= r) return;

    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1, tmp[];
    while(i <= mid && j <= r) {
        if (q[i] < q[j]) temp[k++] = a[i++];
        else temp[k++] = q[j++];
    }
    while(i <= mid) temp[k++] = q[i++];
    while(j <= r) temp[k++] = q[j++];

    for (i = l, j = 0; i <= r; i++, j++) q[i] = temp[j];
}

// 整数二分模版,check()的写法决定check()==true时是l=mid还是r=mid，而r=mid还是l=mid决定mid取(l+r)>>1还是(l+r+1)>>1
// 终极意义是使每次循环，区间长度至少减1，避免陷入死循环
bool check(int ind);

int bsearch_1(int l, int r) {
    while(l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int bsearch_2(int l, int r) {
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1
    }
}