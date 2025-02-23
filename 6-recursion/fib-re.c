//
// Created by gaosiqi on 2025/2/23.
//
#include <stdio.h>
/*效率很慢，因为每次调用都要重新计算前两个数，出现很多重复计算，所以时间复杂度为O(2^n)
int Fib(int n);

int main() {
  int n = 0;
  scanf("%d", &n);
  printf("Fib(%d) = %lld\n", n, Fib(n));
  return 0;
}

int Fib(int n) {
  if (n == 0 || n == 1) {
    return n;
  }
  return Fib(n - 1) + Fib(n - 2);
}
*/


int main() {
  int n = 0;
  scanf("%d", &n);
  long long fib0 = 0L;
  long long fib1 = 1L;
  long long fib2 = 0L;
  for (int i = 0; i < n; i++) {
    fib2 = fib0 + fib1;
    fib0 = fib1;
    fib1 = fib2;
  }
  printf("Fib(%d) = %lld\n", n, fib2);
  return 0;
}

