#include <iostream>

using namespace std;

const int MOD = 1000000007;

int main () {
    int n;
    cin >> n;
    // status[i][j]：在填写第i位时保持第j种状态的所有可能数字的个数
    /**
     * (0): 2
     * (1): 0,2
     * (2): 2,3
     * (3): 0,1,2
     * (4): 0,2,3
     * (5): 0,1,2,3
     */
    long long status[n+1][6];
    for (int i=0;i<6;++i) {
        status[0][i] = 0;
        status[1][i] = 0;
    }
    status[1][0] = 1;
    for (int i=1;i<n+1;++i) {
        status[i][0] = 1;
        status[i][1] = (status[i-1][0] + 2 * status[i-1][1]) % MOD;
        status[i][2] = (status[i-1][0] + status[i-1][2]) % MOD;
        status[i][3] = (status[i-1][1] + 2 * status[i-1][3]) % MOD;
        status[i][4] = (status[i-1][1] + status[i-1][2] + 2 * status[i-1][4]) % MOD;
        status[i][5] = (status[i-1][3] + status[i-1][4] + 2 * status[i-1][5]) % MOD;
    }
    cout << status[n][5] << endl;
    return 0;
}