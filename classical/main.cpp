#include <iostream>
#include <algorithm>

using namespace std;

struct ope {
    int t; // 1->buy;0->sell;-1->cancel
    double p;
    double s;
    bool v;
};

const int N = 5000;
ope o[N], temp;

bool cmp(ope o1, ope o2) {
    if (o1.v != o2.v) { // 有效在前
        return o1.v == true;
    } else if (o1.t != o2.t) { // 买入在前
        return o1.t > o2.t;
    } else return o1.p > o2.p; // 价高在前
}

int main() {
    string op; int c = 0, bc = 0, sc = 0, cancel; double p, s; long double maxsell = 0, maxbuy = 0;
    while(cin >> op) {
        if (op == "buy") {
            cin >> p >> s;
            temp = {1, p, s, true};
            o[c++] = temp;
            bc++;
        } else if (op == "sell") {
            cin >> p >> s;
            temp = {0,p,s,true};
            o[c++] = temp;
            sc++;
        } else if(op == "cancel") {
            cin >> cancel;
            o[cancel-1].v = false;
            if (o[cancel-1].t ==0) bc--;
            else if (o[cancel-1].t==1) sc--;
            temp = {-1,0.0,0.0,true};
            o[c++] = temp;
        } else break;
    }
    sort(o, o+c, cmp);
//    for (int i=0;i<c;++i) {
//        cout << o[i].v << ','<<o[i].t<<','<<o[i].p<<','<<o[i].s<<endl;
//    }
    for(int i=0;i<bc;++i) {
        p = o[i].p; //
    }
    return 0;
}
