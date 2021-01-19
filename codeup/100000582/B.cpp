//
// Created by 章哲源 on 2021/1/19.
//
// 核心是二维数组，g[i][j]表示第i组有多少个j，细节是需要记录不重复的数和组数(diff和valid)
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main() {
    int s, n, temp, b=0;
    scanf("%d", &s);
    while(s--) {
        scanf("%d", &n);
        int a[n+10], diff[n],flag =1, len = 0;
        for(int i=0;i<n;++i){
            scanf("%d", &a[i]);
            if(a[i] >b) b = a[i];
            if (len == 0) diff[len++] = a[i];
            else {
                for (int k=0;k<len;++k) {
                    if (diff[k] == a[i]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1) diff[len++] = a[i];
                flag = 1;
            }
        }
        sort(diff, diff + len);
        int g[n+10][b+10]; int valid[n+10];
        memset(valid, 0, sizeof(valid));
        memset(g, 0, sizeof(g));
        int max = 0;
        for(int i=0;i<n;++i){
            scanf("%d", &temp);
            valid[temp] = 1;
            if (max < temp) max = temp;
            g[temp][a[i]] += 1;
        }
        for (int i=1;i<=max;++i) {
            if (valid[i] == 0) continue;
            printf("%d={", i);
            for (int j=0;j<len;++j) {
                if (j!=len-1) printf("%d=%d,", diff[j], g[i][diff[j]]);
                else printf("%d=%d", diff[j], g[i][diff[j]]);
            }
            printf("}\n");
        }
    }
}