//
// Created by gaosiqi on 2025/2/17.
//
#include <stdio.h>
#define NUM 5
int main() {
  int numbers[NUM] = {1968, 1961, 1969, 1954, 1969};
  //int numbers[5] = {1968, 1961, 1969, 1954, 1969};下面把NUM换成5，也可以。
  //int[5](5 is length)(not int[]): array 数组包含长度，如：int[3]和int[5]不是一个类型
  int min = numbers[0];//不要初始化为0
  //[0]:array subscripting operator/indexing operator
  //for(init clause; condition expression; interation expression(';'不能省略)) {loop-body}
  for (int i = 1; i < NUM; i++) {
    if (numbers[i] < min) {
      min = numbers[i];
    }
  }
  printf("The minimum is %d\n", min);
  return 0;
}
//如果想要通过用户输入来确定一个数组的长度，可以用VLA(variable-length array)。即const int NUM = 5; int numbers[NUM] = ...;
//但是VLA最好不要用，因为不是所有的编译器都支持VLA。可以用vector容器？
