//
// Created by gaosiqi on 2025/2/18.
//
//输入一个整数，输出这个整数有多少位数。

#include <stdio.h>
int main() {
  int number = 0;
  scanf("%d", &number);
  int numberOfDigits = 0;
  if (number == 0) {
    numberOfDigits = 1;
  } else {
      while (number > 0) {
          numberOfDigits++;
          number /= 10;
      }
  }
  printf("%d\n", numberOfDigits);
  return 0;
}
