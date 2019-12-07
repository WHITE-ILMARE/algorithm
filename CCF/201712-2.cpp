#include <iostream>
#include <list>

using namespace std;
const int N = 1000;


int main() {
	// 两种思路：1.模拟循环数数的过程，使用链表；2.得到移除的数学公式，直接计算。用1
	list<int> l;
	int n, k;
	long long count = 1;
	cin >> n >> k;
	for (int i=1;i<n+1;++i) l.push_back(i);
	list<int>::iterator iter = l.begin();
	while(l.size()>1) {
		if (count%k==0 || count%10==k) iter = l.erase(iter);
		else ++iter;
		if (iter == l.end()) iter = l.begin();
		++count;
//		cout <<"*iter="<<*iter<<endl;
	}
	cout << *iter;
}
