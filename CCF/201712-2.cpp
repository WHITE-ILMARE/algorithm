#include <iostream>
#include <list>

using namespace std;
const int N = 1000;


int main() {
	// ����˼·��1.ģ��ѭ�������Ĺ��̣�ʹ������2.�õ��Ƴ�����ѧ��ʽ��ֱ�Ӽ��㡣��1
	list<int> l;
	int n, k;
	long long count = 1;
	cin >> n;
	for (int i=1;i<n+1;++i) l.push_back(i);
	list<int>::iterator iter = l.begin();
	while(l.size()>1) {
		cout << "count="<<count<<"iter="<<*iter<<"list.size="<<l.size()<<endl;
		if (count%k==0 || count%10==k) iter = l.erase(iter);
		cout << "123";
		cout << "iter==l.end(): "<<(iter==l.end())<<endl;
		if (iter == l.end()) iter = l.begin();
		else ++iter;
		++count;
	}
	cout << *iter;
}
