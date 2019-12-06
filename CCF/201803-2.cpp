#include <iostream>

using namespace std;

struct status {
	int x, d; // 1:->,-1:<-
};

int main() {
	int n,L,t;
	cin >> n >> L >> t;
	struct status balls[n];
	for (int i=0;i<n;++i) {
		cin >> balls[i].x;
		if (balls[i].x == L) balls[i].d = -1;
		else balls[i].d = 1;
	}
	for (int i=0;i<t;++i) { // cal per tick
		for (int j=0;j<n;++j) {
			balls[j].x += balls[j].d;
			if (balls[j].x == 0 || balls[j].x == L) balls[j].d = -balls[j].d; 
		}
		for (int j=0;j<n;++j) {
			for(int p=j;p<n;++p) {
				if (balls[j].x == balls[p].x) {
					balls[j].d = -balls[j].d;
					balls[p].d = -balls[p].d;
				}
			}
		
//			cout<<"("<<balls[j].x<<','<<balls[j].d<<')'<<endl;
		}
	}
	for (int i=0;i<n-1;++i) {
		cout << balls[i].x << ' ';
	}
	cout << balls[n-1].x << endl;
}
