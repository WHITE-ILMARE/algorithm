#include <iostream>
#include <fstream>

using namespace std;

const int sy = 1800;
const int sm = 1;
const int sd = 1;
const int sw = 1; // 1是星期2
const int nrms[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int rms[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isR(int y) {
    return y % 400 == 0 || (y % 4 ==0 && y % 100 != 0);
}

int calR(int y) { // 计算1800至y-1年中有多少闰年
    int result = 0, it = 1804;
    while(it <y) {
        if (isR(it)) ++result;
        it+=4;
    }
    return result;
}

bool isV(int y, int m, int d) {
    return (isR(y) && d<=rms[m]) || (!isR(y) && d<=nrms[m]);
}

string format(int v) {
    if (v < 10) return "0"+to_string(v);
    else return to_string(v);
}

int main() {
//    ifstream fs;
//    fs.open("test.txt", ifstream::in);
    int a, b, c, y1, y2;
//    fs >> a >> b >> c >> y1 >> y2;
    cin >> a >> b >> c >> y1 >> y2;
//    cout << "a="<<a<<" b="<<b<<" c="<<c<<" y1="<< y1<<" y2="<<y2 <<endl;
    // 计算1月1号是星期几
    for (int y=y1;y<=y2;++y) {
        const int r = calR(y);
//        cout << "1800年至"<<y-1<<"年的闰年共有"<<r<<"个"<<endl;
        int nr = y - 1800 - r+1, result = 1;
        int w = sw;
        w = (w + (r * 366) % 7) % 7;
        w = (w + (nr * 365) % 7) % 7;
//        cout << y<<"年"<<"1月1日是星期"<< w+1<<endl;
        for (int m=0;m<a-1;++m) {
            if (isR(y)) w = (w + rms[m]) % 7;
            else w = (w + nrms[m]) % 7;
        }
//        cout << y<<"年"<<a<<"月1日是星期"<<w+1<<endl;
        if (w+1 <= c) result += c -(w+1);
        else result += 7+c-(w+1);
        result += (b-1) * 7;
        if (isV(y, a-1, result))
            cout << y <<'/'<<format(a)<<'/'<<format(result) <<endl;
        else cout << "none" << endl;
    }
}