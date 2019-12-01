#include <iostream>

using namespace std;

int main() {
	int a[100][100] = {0};
	int n, x1, y1, x2, y2;
	cin >> n;
	int result = 0;
	for (int i=0;i<n;i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1;j<x2;j++) {
			for (int q = y1;q<y2;q++) {
				if (a[j][q] == 0) {
					++result;
					a[j][q] = 1;
				}
			}
		}
	}
	cout << result << endl;
}
