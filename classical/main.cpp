#include <fstream>
#include <iostream>

using namespace std;
const int sy = 1800;
const int sm = 1;
const int sd = 1;
const int sw = 1; // 1是星期2
const int nrms[] = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
const int rms[] = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

bool isR(int y) {
    return y % 400 == 0 || (y % 4 ==0 && y % 100 != 0);
}

int calR(int y) { // 计算1800至y-1年中有多少闰年
    int result = 0, it = 1804;
    while(it <y && isR(it)) {
        ++result;
        it+=4;
    }
    return result;
}

int main() {
    fstream fs;
    fs.open("test.txt", fstream::in);
    int a, b, c, y1, y2;
    fs >> a >> b >> c >> y1 >> y2;
    // 计算a月1号是星期几
    for (int y=y1;y<=y2;++y) {
        const int r = calR(y);
        int nr = y - 1800 - r;
        int w = sw;
        w = (w + (r * 366) % 7) % 7;
        w = (w + (nr * 365) % 7) % 7;

    }
}