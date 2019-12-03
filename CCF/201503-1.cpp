#include <bits/stdc++.h>

using namespace std;

int a[1000][1000];

int main() {
	int n,m;
	cin >> n >> m;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			cin >> a[i][j];
	for (int i=m-1;i>=0;--i) {
		for (int j=0;j<n;++j) {
			if (j != n-1)
			cout << a[j][i] << ' ';
			else cout << a[j][i]; 
		}
		cout << endl;
	}
}
