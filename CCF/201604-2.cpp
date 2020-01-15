#include <iostream>

using namespace std;

struct coor {
	int x, y;
};

char c[15][15];
char nc[4][4];
coor shape[4];

bool isborder(int o, int n) {
	if (o >= 11) return true;
	for (int i=0;i<4;++i) {
		int x = coor[i].x; int y = coor[i].y;
		if ()
	}
}

int main() {
	int count = 0;
	for (int i =0;i<15;++i)
		for (int j=0;j<15;++j)
			cin >> c[i][j];
	for (int i=0;i<4;++i)
		for (int j=0;j<4;++j) {
			cin >> n[i][j];
			if (n[i][j] != '0') {
				shape[count].x = i;
				shape[count++].y = j;
			}
		}
	int n;
	cin >> n;
	for (int i=0;i<4;++i) coor[i].y += n;
	int offset = 0;
	while(!isborder(offset, n))
}
