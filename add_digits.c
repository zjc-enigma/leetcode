#include<stdio.h>

int addDigits(int num) {
  int a;
  while((a = num % 10) != num) {
    num = num / 10;
    num = num + a;
  }
  return num;
}
int main() {
  printf("%d\n", addDigits(38));
  return 0;
}
