#include <iostream>
#include <cstring>
#include <algorithm> 

using namespace std;

char result[100][100];
char s[100], p[100], low[100];

void getNext(int next[], char s[]) {
	int len = strlen(s);
	int k = -1, j = 0;
	next[0] = -1;
	while(j < len - 1) {
		if (k == -1 || s[j] == s[k]) {
			++j; ++k;
			next[j] = k;
		} else {
			k = next[k];
		}
	}
}

int main() {
	int flag, n, count = 0;
	cin >> p >> flag >> n;
	int plen = strlen(p);
	int next[plen];
	getNext(next, p);
//	for (int i = 0;i<plen;++i) {
//		cout << next[i] << ' ';
//	}
//	cout << endl;
	if  (flag == 0) {
		for (int i=0;i<plen;++i) p[i] = tolower(p[i]);
//		cout << p << endl; 
	}
	for (int i=0;i<n;++i) {
		cin >> s;
		int len = strlen(s);
		strcpy(low, s);
		if (flag == 0) 
			for (int l=0;l<len;++l) 
				low[l] = tolower(low[l]);
		int j = 0, k = 0;
		while(j < len && k < plen) {
//			cout << j << ' ' << k << endl;
			if (k == -1 || low[j] == p[k]) {
				++k; ++j;
			} else {
				k = next[k];
			}
		}
		if (k == plen) strcpy(result[count++], s);
		k = 0; j = 0;
	}
	for (int i=0;i<count;++i) cout << result[i] << endl;
}
