#include <list>
#include <iostream>
using namespace std;

list<int> l;

int main() {
	int n, m, order, op, before =0, after=0;
	cin >> n;
	for (int i=0;i<n;++i) l.push_back(i+1);
	after = n-1;
	cin >> m;
	for (int i=0;i<m;++i) {
		cin >> order >> op;
		for (list<int>::iterator iter=l.begin();iter!=l.end();++iter) {
			if (*iter == order) {
//				cout << "before=" << before << " after="<<after<<endl;
				if (op>=after) {
					l.insert(l.end(), order);
					l.erase(iter);
				} else if (op+before<=0) {
					l.insert(l.begin(), order);
					l.erase(iter);
				} else {
					if (op < 0) {
						list<int>::iterator temp = iter;
						for (int t=0;t<-op;++t) --iter;
						l.insert(iter, order);
						l.erase(temp);
					} else {
						list<int>::iterator temp = iter;
						for (int t=0;t<=op;++t) ++iter;
//						cout << "before insert, iter="<<*iter<<endl;
						l.insert(iter, order);
						l.erase(temp);
					}
					
				}
//				for (list<int>::iterator iter2=l.begin();iter2!=l.end();++iter2) {
//					cout << *iter2 << ' ';
//				}
//				cout << endl;
				before =0;
				after= n-1;
				break;
			}
			++before;
			--after;
		}
	}
	for (list<int>::iterator iter=l.begin();iter!=l.end();++iter) {
		cout << *iter << ' ';
	}
	return 0;
}
