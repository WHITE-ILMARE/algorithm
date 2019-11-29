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
	ios::sync_with_stdio(false); // ��������30�ֵ�100�֣�������cin�ļ��ݣ�����������cin��Ч�� 
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
		so = order / s; // ��ѯ���ڵڼ��������� 
		if (order >= maxBlock || (a[fd] == 0 && n - l >= 2)) { // ��ѯ����ȱʧ�����޷���ԭ
			cout << "-" << endl;
			continue; 
		}
		int stripes = so / (n - 1); // ��ѯ�����ڵ�����ǰ���ж��ٸ����� 
		fd = so % n;
		sd = stripes * s + (order % s); // �ڶ���ά�� 
		char result[9] = "00000000"; 
		if (a[fd] == 0) { // ��Ҫ��������� 
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
