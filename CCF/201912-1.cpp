//
// Created by 章哲源 on 2020/6/15.
//

#include <iostream>
#include <cstring>

using namespace std;

bool jump(int n) {
    if (n % 7 == 0) return true;
    while(n>10) {
        if (n % 10 == 7) return true;
        n = n / 10;
    }
    if (n == 7) return true;
    return false;
}

int main() {
    int sum, cou, realsum, n, a[4];
    memset(a, 0, sizeof(int)*4); // 这一行是必要的，不确保运行环境中声明出来就是0
    sum = 1; cou = 0, realsum = 1;
    cin >> n;
    while(realsum <= n) {
        if (!jump(sum)) {
            ++realsum;
            ++sum;
            cou = (cou + 1) % 4;
        } else {
            ++a[cou];
            ++sum;
            cou = (cou + 1) % 4;
        }
    }
    for (int i=0;i<4;++i) {
        cout << a[i] << endl;
    }
}