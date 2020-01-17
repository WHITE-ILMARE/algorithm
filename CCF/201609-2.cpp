#include <iostream>

using namespace std;

int row[20];

int main() {
	for (int i=0;i<20;++i) row[i] = 0;
	int c, n, i, s, flag = 0, result[5], ok=0, left;
	cin >> c;
	while(c--) {
		cin >> n;
		left = n;
		i = 0;
		for (;i<20;++i) {
			if (5-row[i] >= n) {
				s = row[i]; // start position
				flag = 1;
				row[i] += n;
				for (int k=0;k<n;++k) result[k] = i*5+s+k+1;
				break;
			}
		}
		if (flag == 0) {
			i=0;
			for (;i<20;++i) {
				if (5-row[i]>0) {
					if (5-row[i]<=left) {
						while(row[i]<5) {
							result[ok++] = 5*i+row[i]+1;
							--left; ++row[i];
						}
					} else {
						while(left > 0) {
							result[ok++] = 5*i+row[i]+1;
							++row[i]; --left;
						}
					}
					if (left <= 0) break;
				}
			}
		}
		for (int k=0;k<n;++k) cout << result[k] << ' ';
		cout << endl;
		ok = 0;
	}
}
