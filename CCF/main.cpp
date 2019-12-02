#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n][n];
	queue<int> q;
	for (int i=0;i<n;++i) {
		for (int j=0;j<n;++j) {
			cin >> a[i][j];
		}
	}
	int x,y=0;
	q.push(a[0][0]);
	while(x<n&&y<n) {
		if (y<n-1) {
			++y;
			q.push(a[x][y]);
		} else {
			++x;
			q.push(a[x][y]);
		}
		while(x<n-1&&y>0) {
			++x; --y;
			q.push(a[x][y]);
		}
		if (x==n-1) { // xÏÈ´¥¼°±ß½ç
			++y; 
			q.push(a[x][y]);
		} else {
			++x;
			q.push(a[x][y]);
		}
		while(x>0&&y<n-1) {
			--x; ++y;
			q.push(a[x][y]);
		}
	}
	int sum = n * n;
	for (int i=0;i<sum;++i) {
		cout << q.front() << ' ';
		q.pop();
	}
	cout << endl;
}
