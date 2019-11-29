#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <map>
#include <string.h>

using namespace std;

map<int, char> mm;
const char* en = "0123456789ABCDEF";
void cacheMap();

int main() {
	ios::sync_with_stdio(false); // 神器，从30分到100分，禁用了cin的兼容，极大提升了cin的效率 
	int n, s, l, m, order, tempint, col, fd, sd, so, ps, maxBlock;
	string tempstr;
	cin >> n >> s >> l;
	string data[n];
	int a[n] = {0};
	for (int i = 0; i < l; i++) {
		cin >> tempint >> tempstr;
		a[tempint] = 1;
		data[tempint] = tempstr;
	}
	maxBlock = data[tempint].size() / 8 * (n - 1);
	cacheMap();
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> order;
		so = order / s; // 查询块在第几个条带上 
		if (order >= maxBlock || (a[fd] == 0 && n - l >= 2)) { // 查询到了缺失盘且无法还原
			cout << "-" << endl;
			continue; 
		}
		int stripes = so / (n - 1); // 查询块所在的条带前面有多少个条带 
		fd = so % n;
		sd = stripes * s + (order % s); // 第二个维度 
		char result[9] = "00000000"; 
		if (a[fd] == 0) { // 需要做异或运算 
			for (int i = 0; i < n; i++) {
				if (i != fd) {
					for (int j=0;j<8;j++) {
						result[j] = mm[result[j]*128+(data[i][sd*8+j])];
					}
				}
			}
			cout << result;
		} else {
			for (int i=0;i<8;i++) {
				int start = sd * 8;
				cout << data[fd][start+i];	
			}
		}
		cout << endl;
	}
}

void cacheMap() {
	for (int i=0;i<16;i++) {
		for (int j =0;j<16;j++) {
			mm[en[i]*128+en[j]] = mm[en[j]*128+en[i]] = en[i^j];
		}
	} 
}
