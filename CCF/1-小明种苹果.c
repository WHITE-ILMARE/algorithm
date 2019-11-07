#include <stdio.h>

int main() {
  int m, n;
  scanf("%d %d", &n, &m);
  int i = 0;
  int j = 0;
  int all,T,K,P, temp, around;
  all = 0;
  T=0;
  P=0;
  around=0;
  for(i;i<n;i++) {
    for (j;j<m+1;j++) {
      scanf("%d", &temp);
      if (j>0) {
        T-=temp;
        around-=temp;
      } else {
        all+=temp;
      }
    }
    if(around > P) {
      P = around;
      K = i+1;
    }
    around = 0;
    j = 0;
  }
  printf("%d %d %d", all-T,K,P);
  // scanf("%d", temp);
  return 0;
}