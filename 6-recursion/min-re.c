//
// Created by gaosiqi on 2025/2/22.
//
#include <stdio.h>

#define NUM 3
const int numbers[NUM] = {65,28,37};
int MIN(const int nums[], int len);
int main(){
  int Min = MIN(numbers, NUM);
  printf("Min = %d\n", Min);
  return 0;

}

int MIN(const int nums[], int len){
  if(len == 1){
    return nums[0];
  }
  int partial_min = MIN(nums, len - 1);
  // 每次调用MIN函数都会创造一个新的栈帧，栈帧中的变量刚开始只知道len，一直向下创造，直到if情况，返回一个值，
  // 上一个栈帧的partial_min才知道了nums[len - 1]的值。然后进行比较，返回一个值，给上一个栈帧的partial_min赋值。
  // 这样就一直向上返回，直到最后一个栈帧，返回一个值，给main函数的Min赋值。
  return partial_min < nums[len - 1] ? partial_min : nums[len - 1];
}
