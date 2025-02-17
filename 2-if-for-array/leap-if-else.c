//
// Created by gaosiqi on 2025/2/7.
//

/*
#include <stdio.h>
int main(){
  int leap = 0;
  int year = 0;
  printf("Enter a year: ");
  scanf("%d", &year);
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        leap = 1;
      } else {
        leap = 0;
      }
    } else {
      leap = 1;
    }
  } else {
    leap = 0;
  }
  if (leap == 1) {
    printf("%d is a leap year.\n", year);
  } else {
    printf("%d is not a leap year.\n", year);
  }
  return 0;
}
当else处理的内容比较简单时，可以先将else中的内容写好。
该代码头重脚轻，被称为箭头代码，可以优化。即将if和else交换，先处理else中的内容。

#include <stdio.h>
int main(){
  int leap = 0;
  int year = 0;
  printf("Enter a year: ");
  scanf("%d", &year);
  if (year % 4 != 0) {
    leap = 0;
  } else  {
    if(year % 100 != 0){
    leap = 1;
    } else {
      if (year % 400 != 0) {
        leap = 0;
      } else {
        leap = 1;
      }
    }
  }
  if (leap == 1) {
    printf("%d is a leap year.\n", year);
  } else {
    printf("%d is not a leap year.\n", year);
  }
  return 0;
}
该代码看起来很冗杂，所以可以将一些不必要的括号删去。
*/

/*#include <stdio.h>
int main(){
  int leap = 0;
  int year = 0;
  printf("Enter a year: ");
  scanf("%d", &year);
  if (year % 4 != 0) {
    leap = 0;
  } else if (year % 100 != 0) {
    leap = 1;
  } else if (year % 400 != 0) {
    leap = 0;
  } else {
    leap = 1;
  }
  if (leap == 1) {
    printf("%d is a leap year.\n", year);
  } else {
    printf("%d is not a leap year.\n", year);
  }
  return 0;
}
*/

//一般不这样写，因为这样不好看明白。
#include <stdio.h>
int main(){
  int leap = 0;
  int year = 0;
  printf("Enter a year: ");
  scanf("%d", &year);
  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
    leap = 1;
  } else {
    leap = 0;
  }
  if (leap == 1) {
    printf("%d is a leap year.\n", year);
  } else {
    printf("%d is not a leap year.\n", year);
  }
  return 0;
}
//&&: and
//||: or
//!: not
//&& 优先级高于 ||
//短路：如果一个表达式为假，则不再计算后面的表达式。and看第一个，为0不再计算；or看第一个，为1不再计算。

