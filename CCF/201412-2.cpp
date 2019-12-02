 #include <bits/stdc++.h>
 
 using namespace std;
 
 struct Directions {
 	int drow;
 	int dcol;
 }dirt[4] = {{0,1},{1,0},{1,-1},{-1,1}};
 
 const int EAST = 0;
 const int SOUTH = 1;
 const int SOUTHWEST = 2;
 const int NORTHEAST = 3;
 const int N = 500;
 
 int a[N][N];
 
 int main() {
 	int n;
 	cin >> n;
 	for (int i = 0; i < n; i++) 
 		for (int j = 0; j < n; j++)
 			cin >> a[i][j];
	int col, row, next = EAST;
	cout << a[row][col] << ' ';
	while(col != n-1 || row != n-1) {
		row += dirt[next].drow;
		col += dirt[next].dcol;
		cout << a[row][col] << ' ';
		if (next == EAST && row == 0) {
			next = SOUTHWEST;
		} else if (next == EAST && row == n-1) {
			next = NORTHEAST;
		} else if (next == SOUTHWEST && row == n-1) {
			next = EAST;
		} else if (next == SOUTHWEST && col == 0) {
			next = SOUTH;
		} else if (next == SOUTH && col == 0) {
			next = NORTHEAST;
		} else if (next == SOUTH && col == n-1) {
			next = SOUTHWEST;
		} else if (next == NORTHEAST && col == n-1) {
			next = SOUTH;
		} else if (next == NORTHEAST && row == 0) {
			next = EAST;
		}
	}
	return 0;
 }
