#include <iostream>
#include <list>
using namespace std;

struct window {
	int x1;
	int y1;
	int x2;
	int y2;
	int order;
	bool operator==(const window&);
} win;

bool window::operator==(const window& win){
	if (order == win.order) return true;
	return false;
}

int main() {
	int n, m, x1, y1, x2, y2,x,y;
	int flag = 0;
	cin >> n >> m;
	list <window> l;
	for (int i=0;i<n;i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		win.x1 = x1;win.y1=y1;
		win.x2=x2;win.y2=y2; win.order=i+1;
		l.push_back(win);
	}
	for (int i=0;i<m;i++) {
		cin >> x>>y;
		for (list<window>::reverse_iterator iter=l.rbegin();iter!=l.rend();++iter) {
			if (x>=iter->x1 && x<=iter->x2 && y>=iter->y1&&y<=iter->y2) {
				cout << iter->order << endl;
				struct window temp = {iter->x1,iter->y1,iter->x2,iter->y2,iter->order};
				l.remove(*iter);
				l.push_back(temp);
//				for (list<window>::iterator inner=l.begin();inner!=l.end();++inner)
//				cout << inner->x1 << ' ' << inner->y1 << ' ' << inner->x2 << ' ' << inner->y2 << ' ' << inner->order << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << "IGNORED" << endl;
		}
		flag = 0;
	}
}
