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
	while(x<n||y<n) {
		q.push(a[x][y]);
		if (y<n-1) {
			++y;
			q.push(a[x][y]);
		} else {
			++x;
			q.push(a[x][y]);
		}
	}
}
