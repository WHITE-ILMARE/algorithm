#include <iostream>

using namespace std;

struct status {
	int x, d; // 1:->,0:<-
};

int main() {
	int n,L,t;
	cin >> n >> L >> t;
	struct status balls[n] = {struct status(0,1)};
	for (int i=0;i<n;++i) {
		cin >> balls[i].x;
	}
	for (int i=0;i<t;++i) { // cal per tick
		for (int j )
	}
}
