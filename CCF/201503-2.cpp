 #include <bits/stdc++.h>
 
 using namespace std;
 
 struct stu {
 	int key;
 	int val;
 	bool operator==(const stu& s) {
 		if (key == s.key) return true;
 		return false;
	 };
 };
 
 struct stu a[1000];
 
 bool comp(stu bef, stu aft) {
 	return bef.val > aft.val || (bef.val==aft.val && bef.key < aft.key);
 }
 
 int main() {
 	int n, temp,count=0;
 	cin >> n;
 	for (int i=0;i<n;i++) {
 		cin >> temp;
 		struct stu te ={temp,1};
 		stu* st = find(a, a+count, te);
 		if (st != a+count) {
 			st->val = st->val + 1;
		 } else {
		 	a[count++] = te;
		 }
	 }
	 sort(a, a+count, comp);
	 for (int i=0;i<count;++i) {
	 	cout << a[i].key << ' ' << a[i].val << endl;
	 }
 }
