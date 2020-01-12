#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

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
    if (o1.v != o2.v) { // ��Ч��ǰ
        return o1.v == true;
    } else if (o1.t != o2.t) { // ������ǰ
        return o1.t > o2.t;
    } else return o1.p > o2.p; // �۸���ǰ
}

int main() {
    string op; int c = 0, bc = 0, sc = 0, cancel; double p, s, rp = 0.00; long long maxsell = 0, maxbuy = 0, result = 0;
    ifstream ifs;
//    ifs.open("test.txt", ifstream::in);
    while(cin >> op) {
//    while(ifs >> op) {
        if (op == "buy") {
            cin >> p >> s;
//            ifs >> p >> s;
            temp = {1, p, s, true};
            o[c++] = temp;
            bc++;
        } else if (op == "sell") {
            cin >> p >> s;
//            ifs >> p >> s;
            temp = {0,p,s,true};
            o[c++] = temp;
            sc++;
        } else if(op == "cancel") {
            cin >> cancel;
//            ifs >> cancel;
            o[cancel-1].v = false;
            if (o[cancel-1].t ==0) sc--;
            else if (o[cancel-1].t==1) bc--;
            temp = {-1,0.0,0.0,true};
            o[c++] = temp;
        }
    }
    sort(o, o+c, cmp);

//    cout << "------------arr------------" << endl;
//    for (int i=0;i<c;++i) {
//        cout << o[i].v << ','<<o[i].t<<','<<o[i].p<<','<<o[i].s<<endl;
//    }
//    cout << "------------arr------------" << endl;
//    cout << "bc= "<<bc << " sc=" << sc << endl;

    int realc = bc + sc;
    for(int i=0;i<bc;++i) {
        maxbuy = 0; maxsell = 0;
        p = o[i].p; // ���������
        for (int bi=0;bi<=i;++bi) {
            if (o[bi].p >= p) maxbuy += o[bi].s;
        }
        int si = realc-1;
        while(si>=bc&&o[si].p<=p) {
            maxsell += o[si].s;
            --si;
        }

//        cout << "price=" << p << " maxsell= " << maxsell << " maxbuy= " << maxbuy << endl;

        long long temp = min(maxsell, maxbuy);
        if (temp > result) {
            rp = p;
            result = temp;
        }
    }
    cout << fixed << setprecision(2) << rp << ' ' << result << endl;
    return 0;
}

