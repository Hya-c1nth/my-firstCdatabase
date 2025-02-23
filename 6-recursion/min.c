//
// Created by gaosiqi on 2025/2/22.
//
#include <stdio.h>
int MIN(int a, int b);
int main() {
  int a = 25;
  int b = 37;

  int Min = MIN(a, b);
  printf("Min = %d\n", Min);

  return 0;
}

int MIN(int a, int b) {
  return a < b ? a : b;
}