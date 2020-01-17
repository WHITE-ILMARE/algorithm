#include <iostream>

using namespace std;

struct summon {
	int hp, attack;
};

struct player {
	summon ss[8];
};

void init(player *p) {
	p->ss[0].hp = 30; p->ss[0].attack=0;
	for(int i=1;i<8;++i){
		p->ss[i].hp=0;
		p->ss[i].attack=0;	
	}
}

void summ(player *p, summon *s, int po) { // single summon operation
	for (int start = 6;start>po;--start) {
		p->ss[start] = p->ss[start-1];
	}
	p->ss[po]=(*s);
}

void attack(player *pre, player *aft, int prev, int afte) {
	pre->ss[prev].hp -= aft->ss[afte].attack;
	aft->ss[afte].hp -= pre->ss[prev].attack;
	if (pre->ss[prev].hp <= 0 && prev!=0) // dead
	{
		for (int i=prev;i<7;++i) pre->ss[i]=pre->ss[i+1];
		pre->ss[7].hp=0;pre->ss[7].attack=0;
	}
	if (aft->ss[afte].hp<=0 && afte!=0) {
		for (int i=afte;i<7;++i) aft->ss[i]=aft->ss[i+1];
		aft->ss[7].hp=0;aft->ss[7].attack=0;
	}
}

int main () {
	int n, p, at, hp,attacker,defender,i=0,count=0; string op; player p0, p1;
	init(&p0); init(&p1);
	cin >> n;
	for (int j=0;j<n;++j) {
		cin >> op;
		if (op[0] == 's') { // summon
			cin >> p >> at >> hp;
			summon su{hp, at};
			summ(i%2==0?(&p0):(&p1), &su, p); 
		} else if (op[0] == 'a') { // attack
			cin >> attacker >> defender;
			attack(i%2==0?(&p0):(&p1),i%2==0?(&p1):(&p0),attacker,defender);
		} else { // end
			++i;
		}
//		cout << "-----after " << i <<' '<<op<<"-----"<<endl;
//		cout << "p0= ";
//		for (int l=0;l<7;++l) cout << p0.ss[l].hp << ' '; cout << endl;
//		cout << "p1= ";
//		for (int l=0;l<7;++l) cout << p1.ss[l].hp << ' '; cout << endl;
	}
	if (p0.ss[0].hp >0 &&p1.ss[0].hp>0) cout << "0" << endl;
	else if (p0.ss[0].hp<=0) cout << "-1" <<endl;
	else cout << "1" << endl;
	cout << p0.ss[0].hp << endl;
	for (int k=1;k<8;++k) if (p0.ss[k].hp>0) ++count;
	cout << count << ' ';
	for (int k=1;k<=count;++k) cout << p0.ss[k].hp<<' ';
	cout << endl;
	count = 0;
	cout << p1.ss[0].hp << endl;
	for (int k=1;k<8;++k) if (p1.ss[k].hp>0) ++count;
	cout << count << ' ';
	for (int k=1;k<=count;++k) cout << p1.ss[k].hp<<' ';
	cout << endl;
	return 0;
}
