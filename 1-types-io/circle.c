//
// Created by gaosiqi on 2025/2/6.
//
#include <stdio.h>
int main(){
  int radius = 10;
  //const代表常量，只读不修改，一般用全大写字母表示
  //多次出现的数如本文件中的3.14159，要修改时很困难且易出错，成为magic number，一般用字母将其替换
  const double PI = 3.14159;
  double circumference = 2 * PI * radius;
  double area = PI * radius * radius;
  printf("radius =  %d\ncircumference = %.2f\narea = %f\n", radius,circumference,area);
  return 0;
}
