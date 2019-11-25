#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char esc = '\033';
  printf("\\x%x\n", esc+1-1);
  system("pause");
  return 0;
}