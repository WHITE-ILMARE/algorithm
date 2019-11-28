#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

using namespace std;

void divide(string, string[]);

int main() {
	int n, s, l, m, order, tempint, col, fd, sd, so, ps;
	unsigned int result;
	string tempstr;
	ifstream testfile("./test.txt");
	cin >> n >> s >> l;
//	testfile >> n >> s >> l;
	int a[n] = {0};
	cin >> tempint >> tempstr;
//	testfile >> tempint >> tempstr;
	a[tempint] = 1;
	col = tempstr.size()/8;
	string data[n][col];
	divide(tempstr, data[tempint]);
	for (int i = 1; i < l; i++) {
		cin >> tempint >> tempstr;
//		testfile >> tempint >> tempstr;
		a[tempint] = 1;
		divide(tempstr, data[tempint]);
	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < col; j++) {
//			cout << data[i][j] << ' ';
//		}
//		cout << endl;
//	}
	cin >> m;
//	testfile >> m;
	for (int i = 0; i < m; i++) {
		cin >> order;
//		testfile >> order;
		so = order / s; // ��ѯ���ڵڼ��������� 
//		cout << "stripe order=" << so << endl;
		fd = so % n; // ��ѯ���ڵڼ��������� 
//		cout << "first dimension=" << fd << endl;
		if (a[fd] == 0 && n - l >= 2) { // ��ѯ����ȱʧ�����޷���ԭ
			cout << '-' << endl;
			continue; 
		}
//		cout << "row=" << fd << endl; // ��һ��ά�� 
		int stripes = (so - fd) / n; // ��ѯ�����ڵ�����ǰ���ж��ٸ����� 
//		cout << stripes << " stripes before target" << endl;
		ps = floor((stripes + fd + 1 - n) / (double)n) + 1; // ��ѯ����������ǰ���ж��ٸ�P(+1����Ϊ�����P��0��ʼ����)
//		cout << ps << " Ps before target" << endl; 
		sd = (stripes + ps) * s + (order % s); // �ڶ���ά�� 
//		cout << "col=" << sd << endl;
//		cout << "data=" << data[fd][sd] << endl;
		result = 0; 
		if (a[fd] == 0) { // ��Ҫ��������� 
			for (int i = 0; i < n; i++) {
				if (i != fd) {
					result ^= stoul(data[i][sd], nullptr, 16);
				}
			}
		} else result = stoul(data[fd][sd], nullptr, 16);
		cout << setw(8) << setfill('0') << hex << uppercase << result << endl;
	}
}

void divide(string str, string* arr) {
	int len = str.size();
	int times = len / 8;
	for (int i = 0; i < times; i++) {
		arr[i] = str.substr(8 * i, 8);
	}
}
