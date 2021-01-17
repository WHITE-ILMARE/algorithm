#include <iostream>

using namespace std;
struct Node{
    int x, y;
};
int ca = 0, cb = 1000;
Node nodes[2000];
int cal(int p0, int p1, int p2, Node nn) {
    return p0+nn.x*p1+nn.y*p2>0;
}

int check(int p0, int p1, int p2) {
    int basis_a = cal(p0, p1, p2, nodes[0]);
    for (int i=1;i<ca;++i) {
        if (basis_a != cal(p0,p1,p2,nodes[i])) return 0;
    }
    int basis_b = cal(p0,p1,p2,nodes[1000]);
    for (int i=1001;i<cb;++i) {
        if (basis_b != cal(p0,p1,p2,nodes[i])) return 0;
    }
    return basis_a != basis_b;
}

int main () {
    int n,m,x,y,p0,p1,p2;
    char t;
    cin >> n >> m;
    for (int i=0;i<n;++i) {
        struct Node temp;
        cin >> x >> y >> t;
        temp.x=x;temp.y=y;
        if (t=='A') nodes[ca++]=temp;
        else nodes[cb++]=temp;
    }
    for (int i=0;i<m;++i) {
        cin >> p0 >> p1 >> p2;
        if (check(p0, p1, p2)) {
            cout << "Yes" << endl;
        } else cout << "No" << endl;
    }
    return 0;
}