//
// Created by gaosiqi on 2025/2/6.
//
#include <stdio.h>
int main(){
  const double PI = 3.14159;
  int radius = 100;

  double surface_area = 4 * PI * radius * radius;
  //如下语句算出答案为3141590.000000，出现错误。是因为4/3被限制在整数中，算出了1，可以如下下句修改。
  //double volume = 4/3 * PI * radius * radius * radius;
  double volume = 4.0/3 * PI * radius * radius * radius;
  //.4: precision
  //15: minimum width
  //- : flag(left justified)  general status is right justified
  printf("%-15.4f : surface_area\n%-15.4f : volume\n", surface_area,volume);
  return 0;
}