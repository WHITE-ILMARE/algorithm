#include <iostream>

using namespace std;
const int N = 2000;

struct t {
	int s;
	int e;
};
struct t a[N],b[N];

int main() {
	ios::sync_with_stdio(false);
	int n,a_c=0,b_c=0,result=0;
	cin >> n;
	for (int i=0;i<n;++i) cin >> a[i].s >> a[i].e;
	for (int i=0;i<n;++i) cin >> b[i].s >> b[i].e;
	while(a_c<=n-1 && b_c<=n-1) {
		if (a[a_c].e <= b[b_c].s) {
			++a_c;	
//			cout << "a="<<a_c<<" b="<<b_c<< "a is too small" << endl;
		} else if(a[a_c].s<=b[b_c].s && a[a_c].e <= b[b_c].e) {
			result+=(a[a_c].e-b[b_c].s);
//			cout << "a="<<a_c<<" b="<<b_c<< " result=" << result << endl;
			++a_c;
		} else if (a[a_c].s<=b[b_c].s && a[a_c].e > b[b_c].e) {
			result+=(b[b_c].e-b[b_c].s);
//			cout << "a="<<a_c<<" b="<<b_c<< " result=" << result << endl;
			++b_c;
		} else if (a[a_c].s >b[b_c].s && a[a_c].e <= b[b_c].e) {
			result += (a[a_c].e - a[a_c].s);
//			cout << "a="<<a_c<<" b="<<b_c<< " result=" << result << endl;
			++a_c;
		} else if (a[a_c].s >b[b_c].s && a[a_c].s <=b[b_c].e && a[a_c].e >b[b_c].e) {
			result += (b[b_c].e - a[a_c].s);
//			cout << "a="<<a_c<<" b="<<b_c<< " result=" << result << endl;
			++b_c;
		} else if (a[a_c].s > b[b_c].e) {
			++b_c;
//			cout << "a="<<a_c<<" b="<<b_c<< "b is too small" << endl;
		}
	}
	cout << result << endl;
}
