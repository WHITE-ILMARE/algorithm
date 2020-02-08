//
// Created by 章哲源 on 2020/2/8.
// 图的Breadth First Search算法
//
#include <queue>
#include <iostream>

using namespace std;

struct node {
    int value, visited;
};

queue<node> q;

int main() {
    int n, m, start, end;
    cout << "Input quantity of nodes: ";
    cin >> n;
    cout << "Input quantity of edges: ";
    cin >> m;
    node ns[n]; int arcs[n][n]; memset(arcs, 0, sizeof(arcs));
    for (int i=0;i<n;++i) { // init nodes
        ns[i].value = i+1;
        ns[i].visited = 0;
    }
    cout << "Input every edge(start end) :" << endl;
    for (int i=0;i<m;++i) { // init adjacent matrix
        cin >> start >> end;
        arcs[start-1][end-1] = 1;
    }
    cout << "visit node-1" << endl; // visit node before enqueue
    ns[0].visited = 1;
    q.push(ns[0]);
    while(!q.empty()) {
        node temp = q.front();
        q.pop();
        for (int i=0;i<n;++i) {
            if (arcs[temp.value-1][i] != 0 && ns[i].visited == 0) {
                cout << "visit node-" << i+1 << endl;
                ns[i].visited = 1;
                q.push(ns[i]);
            }
        }
    }
    return 0;
}

