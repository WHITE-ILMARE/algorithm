#include <iostream>

using namespace std;

bool isZero(int init[][30], int row, int col, int i, int j) {
	if (i-2>=0 && init[i-2][j] == init[i-1][j] && init[i-1][j] == init[i][j]) {
		return true;
	} else if (j-2>=0 && init[i][j-2] == init[i][j-1] && init[i][j]==init[i][j-1]) {
		return true;
	} else if (i+2<row && init[i+2][j] == init[i+1][j] && init[i+1][j] == init[i][j]) {
		return true;
	} else if (j+2<col && init[i][j+2] == init[i][j+1] && init[i][j+1] == init[i][j]) {
		return true;
	} else if (i+1<row && i-1>=0 && init[i+1][j] == init[i][j] && init[i][j] == init[i-1][j]) {
		return true;
	} else if (j+1<col && j-1>=0 && init[i][j+1] == init[i][j] && init[i][j] == init[i][j-1]) {
		return true;
	}
	return false;
}

void judgeAndSet(int init[][30], int row, int col) {
	for(int i=0;i<row;i++) {
		for(int j=0;j<col;j++) {
			if (isZero(init, row, col,i,j)) {
				if (j == col-1)
					cout << "0" << endl;
				else cout << "0 "; 
			} else {
				if (j == col -1) 
					cout << init[i][j] << endl;
				else cout << init[i][j] << " ";
			}
		}
	}
}

int main() {
	int n,m;
	cin>>n>>m;
	int init[n][30];
	for (int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>init[i][j];
		}
	}
	judgeAndSet(init,n,m);
}
