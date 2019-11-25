#include <stdio.h>

int main() {
  int n, m, operate, i=0, j=0,now,all=0,DAIndex=0,tripleCou=0;
  scanf("%d", &n);
  int dropArr[n];
  for (i;i<n;i++) {
    scanf("%d", &m);
    for(j;j<m;j++) {
      if(j==0) {
        scanf("%d", &now);
      } else {
        scanf("%d", &operate);
        if(operate>0){
          if(now!=operate && (DAIndex==0 || dropArr[DAIndex-1]!=i+1)) {
            dropArr[DAIndex++] = i+1;
          }
          now=operate;
        } else {
          now+=operate;
        }
      }
    }
    all+=now;
    j=0;
  }
  if(DAIndex<2){
    printf("%d %d %d", all, DAIndex, 0);
  } else {
    i=0;
    for(i;i<=DAIndex-1;i++){
      // printf("%d,", dropArr[i]);
      if((dropArr[(i-1)%DAIndex]+1)%n==dropArr[i]%n && (dropArr[i]+1)%n==dropArr[(i+1)%DAIndex]%n){
        tripleCou++;
      }
    }
    // printf("-------\n");    
    printf("%d %d %d", all, DAIndex,tripleCou);
  }
  // scanf("%d", &i);
  return 0;
}