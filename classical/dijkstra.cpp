//
// Created by 章哲源 on 2020/2/5.
// 最短路径算法
//

/**
 * input: n个顶点，m条边，m行边的信息(start,end,weight),weight < 10e9
 */

#include <iostream>

using namespace std;

const int MAX_INT = 0x3f3f3f3f;

int main () {
    int n, m, start, end, temp, weight, min = MAX_INT;
    cin >> n >> m;
    int dis[n], visit[n], rec[n][n];
    memset(rec, MAX_INT, sizeof(rec)); memset(dis,MAX_INT, 4*n); memset(visit, 0, 4*n); // 初始化，注意memset指定的是字节数
//    cout << "------dis------" << endl;
//    for (int i=0;i<n;++i) cout << dis[i] << ' ';
//    cout << endl;
//    cout << "------dis------" << endl;
//    cout << "------visit------" << endl;
//    for (int i=0;i<n;++i) cout << visit[i] << ' ';
//    cout << endl;
//    cout << "------visit------" << endl;
    for (int i=0;i<m;++i) {
        cin >> start >> end >> weight;
        rec[start - 1][end - 1] = weight;
    }
    cout << "------邻接矩阵------" << endl;
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            cout << rec[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "------邻接矩阵------" << endl;
    // 计算1号顶点到其他顶点的距离
    for (int i=0;i<n;++i) {
        rec[i][i] = 0; // 补充初始化
        dis[i] = rec[0][i];
    }
    for (int t=1;t<n;t++) {
        temp = 0; min = MAX_INT;
        for (int i=0;i<n; ++i) {
            if (visit[i] == 0 && dis[i] < min) {
                temp = i;
                min = dis[i];
            }
        }
        visit[temp] = 1;
        for (int j=0;j<n;++j) {
            if (visit[j] == 0 && (rec[temp][j] + dis[temp] < dis[j])) {
                dis[j] = rec[temp][j] + dis[temp];
            }
        }
    }
    for (int i=0;i<n;++i) {
        cout << dis[i] << ' ';
    }
    return 0;
}
