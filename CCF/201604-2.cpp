#include <iostream>
#include <fstream>

using namespace std;

struct coor {
	int x, y;
};

char c[15][10];
char nc[4][4];
coor shape[4];

bool isborder(int o) {
	for (int i=0;i<4;++i) {
		if(shape[i].x+o+1 >= 15 || c[shape[i].x+o+1][shape[i].y] != '0') return true;
	}
	return false; 
}

int main() {
	int count = 0;
	ifstream ifs("201604-2.txt");
	for (int i =0;i<15;++i)
		for (int j=0;j<10;++j)
//			ifs >> c[i][j];
			cin >> c[i][j];
//	cout << "----------------input c----------------"<<endl;
//	for (int i=0;i<15;++i) {
//		for (int j=0;j<10;++j)
//			cout << c[i][j] << ' ';
//		cout << endl;
//	}
//	cout << "----------------input c----------------"<<endl;
	for (int i=0;i<4;++i)
		for (int j=0;j<4;++j) {
//			ifs >> nc[i][j];
			cin >> nc[i][j];
			if (nc[i][j] != '0') {
				shape[count].x = i;
				shape[count++].y = j;
			}
		}
//	for (int i=0;i<4;++i) {
//		cout << "shape["<<i<<"] = ("<<shape[i].x <<","<<shape[i].y<<")"<<endl;
//	}
	int n;
	cin >> n;
//	ifs >> n;
	for (int i=0;i<4;++i) shape[i].y += (n-1);
	int offset = 0;
	while(!isborder(offset)) ++offset;
	for (int i=0;i<4;++i) c[shape[i].x+offset][shape[i].y] = '1';
	for (int i=0;i<15;++i) {
		for (int j=0;j<10;++j) {
			cout << c[i][j] << ' ';	
		}
		cout << endl;
	}
}
