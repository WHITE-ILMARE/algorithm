//
// Created by 章哲源 on 2021/1/18.
//

#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Stu {
    char num[13];
    int score, localrank, finalrank, group;
};

bool cmp (Stu a, Stu b) {
    if (a.score!=b.score) return a.score > b.score;
    else return strcmp(a.num, b.num) < 0;
}

int main() {
//    FILE* f = fopen("test.txt", "r");
    int n,k,inputs,begin = 0;
    char inputn[13];
    scanf("%d", &n);
//    fscanf(f, "%d", &n);
    Stu stu[300*n];
    for(int i=0;i<n;++i) {
        scanf("%d", &k);
//        fscanf(f, "%d", &k);
        for (int j=0;j<k;++j) {
            scanf("%s %d", inputn, &inputs);
//            fscanf(f, "%s %d", inputn, &inputs);
            strcpy(stu[begin+j].num, inputn);
            stu[begin+j].score = inputs;
            stu[begin+j].group = i+1;
        }
        sort(stu+begin, stu+begin+k, cmp);
        for (int m = 0;m<k;++m) {
            if (m>0 && stu[begin+m].score == stu[begin+m-1].score)
                stu[begin+m].localrank = stu[begin+m-1].localrank;
            else stu[begin+m].localrank = m+1;
        }
        begin = begin + k;
    }
    sort(stu, stu+begin, cmp);
    for (int i=0;i<begin;++i) {
        if (i>0 && stu[i].score == stu[i-1].score)
            stu[i].finalrank = stu[i-1].finalrank;
        else stu[i].finalrank = i+1;
    }
    printf("%d\n", begin);
    for(int i=0;i<begin;++i) {
        printf("%s %d %d %d\n", stu[i].num, stu[i].finalrank, stu[i].group, stu[i].localrank);
    }
    return 0;
}