//
// Created by gaosiqi on 2025/2/23.
//
#include <stdio.h>

int GCD(int a, int b);
int main() {
  int a = 25;
  int b = 37;

  int gcd = GCD(a, b);
  printf("GCD = %d\n", gcd);

  return 0;
}

int GCD(int a, int b) {
  if (b == 0) {
    return a;
  }
  return GCD(b, a % b);
}