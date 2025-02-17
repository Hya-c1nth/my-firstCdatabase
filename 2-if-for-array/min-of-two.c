//
// Created by gaosiqi on 2025/2/7.
//
#include <stdio.h>
int main(){
  int a = 0;
  int b = 0;
  int min = 0;
  printf("Enter two integers: ");
  scanf("%d %d", &a, &b);
  if (a < b) {
    min = a;
  } else {
    min = b;
  }
  //or 可用:min = a < b ? a : b;条件成立为a，不成立为b。少用，因为不够清晰。
  //写代码不要表现得太聪明。
  printf("The minimum is %d\n", min);
  return 0;
}