#include <iostream>

using namespace std;

struct co {
    int x,y,grade;
};

void check(co *c, int n) {
    for (int i=0;i<n;++i) {
        int x = c[i].x; int y = c[i].y;
        for (int j=0;j<n;++j) {
            if ((c[j].x==x&&c[j].y==y+1)||(c[j].x==x&&c[j].y==y-1)||
                (c[j].x==x-1&&c[j].y==y)||(c[j].x==x+1&&c[j].y==y)) {
                ++c[i].grade;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    co c[n];
    for (int i=0;i<n;++i) {
        int x,y;
        cin >> x >> y;
        c[i].x = x; c[i].y = y; c[i].grade = 0;
    }
    check(c, n);
    for (int j=0;j<n;++j) {
        if (c[j].grade == 4) { // checked
            c[j].grade = 0;
            for (int i=0;i<n;++i) {
                if ((c[i].x == c[j].x-1 && c[i].y == c[j].y-1)||
                    (c[i].x == c[j].x-1 && c[i].y == c[j].y+1)||
                    (c[i].x == c[j].x+1 && c[i].y == c[j].y-1)||
                    (c[i].x == c[j].x+1 && c[i].y == c[j].y+1)) {
                    ++c[j].grade;
                }
            }
        } else {
            c[j].grade = -1;
        }
    }
    int result = 0;
    for (int s = 0; s<=4;++s) {
        for(int i=0;i<n;++i) {
            if (c[i].grade == s) ++result;
        }
        cout << result << endl;
        result = 0;
    }
    return 0;
}