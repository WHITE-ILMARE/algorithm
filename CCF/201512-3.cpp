#include <iostream>
#include <stack> 

using namespace std;

struct coor {
	int x, y;
};
char c[100][100];
stack<coor> cs;

void lineOnce(char c[][100], int x, int y, char ch) {
	if ((c[x][y] == '-' && ch == '|') || (c[x][y] == '|' && ch=='-')) c[x][y] = '+';
	else c[x][y] = ch;
}

bool isborder(char c[][100], int x, int y, int w, int h, char ch) {
	return x == -1 || y == -1 || x == w || y == h || c[x][y] == '-' || c[x][y] == '|' || c[x][y] == '+' || c[x][y] == ch;
}

int main() {
	for (int k=0;k<100;++k)
		for (int p=0;p<100;++p)
			c[k][p] = '.';
	int n, m, q, op, x1, y1, x2, y2, x, y; char ch;
	cin >> m >> n >> q;
	for (int i=0;i<q;++i) {
//		for (int r=n-1;r>=0;--r) {
//			for (int v=0;v<m;++v) {
//				cout << c[v][r] << ' ';
//			}
//			cout << endl;
//		}
		cin >> op;
		if (op == 0) {
			cin >> x1 >> y1 >> x2 >> y2;
//			cout << "("<<x1<<","<<y1<<"),("<<x2<<","<<y2<<")"<<endl;
			if (x1 == x2) {
				if (y1 < y2)
					for (int t = y1;t<=y2;++t) lineOnce(c, x1, t, '|');
				else
					for(int t=y2;t<=y1;++t) lineOnce(c, x1, t, '|');
			} else {
				if (x1<x2) {
					for (int t=x1;t<=x2;++t) lineOnce(c, t, y1, '-');
				} 
				else
					for (int t=x2;t<=x1;++t) lineOnce(c, t, y1, '-');
			}
		} else {
			cin >> x >> y >> ch;
			coor tc{x, y};
			cs.push(tc);
			while(!cs.empty()) {
				coor tc = cs.top();
//				cout << "top = ("<<tc.x<<','<<tc.y<<"), size=("<<cs.size()<<")"<<endl;
				c[tc.x][tc.y] = ch;
				cs.pop();
				if (!isborder(c, tc.x-1, tc.y, m, n, ch)) {
//					cout << "("<<tc.x-1<<","<<tc.y<<") is not border" << endl;
					coor temp{tc.x-1, tc.y}; cs.push(temp);
				}
				if (!isborder(c, tc.x, tc.y+1, m, n, ch)) {
//					cout << "("<<tc.x<<","<<tc.y+1<<") is not border" << endl;
					coor temp{tc.x, tc.y+1}; cs.push(temp);
				}
				if (!isborder(c, tc.x+1, tc.y, m, n, ch)) {
//					cout << "("<<tc.x+1<<","<<tc.y<<") is not border" << endl;
					coor temp{tc.x+1, tc.y}; cs.push(temp);
				}
				if (!isborder(c, tc.x, tc.y-1, m, n, ch)) {
//					cout << "("<<tc.x<<","<<tc.y-1<<") is not border" << endl;
					coor temp{tc.x, tc.y-1}; cs.push(temp);
				}
			}
		}
	}
	for (int j=n-1;j>=0;--j) {
		for (int i=0;i<m;++i) {
			cout << c[i][j] << ' ';
		}
		cout << endl;
	}
} 
