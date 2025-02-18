//
// Created by gaosiqi on 2025/2/18.
//
#include <stdio.h>
int main() {
   int number = 0;
   scanf("%d", &number);
   int numberOfDigits = 0;
   do {
     numberOfDigits++;
     number /= 10;
   } while (number > 0);
   //先做一遍循环体，再判断成不成立，多用于开始的项被排除在外的情况。
   printf("%d\n", numberOfDigits);
   return 0;
}

