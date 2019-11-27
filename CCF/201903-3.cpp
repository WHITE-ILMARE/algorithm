#include <iostream>

using namespace std;

void divide(string, string[]);

int main() {
	int n, s, l, m, order, tempint, col;
	string tempstr;
	cin >> n >> s >> l;
	cin >> tempint >> tempstr;
	col = tempstr.size()/8;
	string data[n][col];
	divide(tempstr, data[tempint]);
	for (int i = 1; i < l; i++) {
		cin >> tempint >> tempstr;
		divide(tempstr, data[tempint]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < col; j++) {
			cout << data[i][j] << ' ';
		}
		cout << endl;
	}
//	cin >> m;
//	for (int i = 0; i < m; i++) {
//		cin >> order;
//		cout << cal()
//	}
}

void divide(string str, string* arr) {
	int len = str.size();
	int times = len / 8;
	for (int i = 0; i < times; i++) {
		arr[i] = str.substr(8 * i, 8);
	}
}
