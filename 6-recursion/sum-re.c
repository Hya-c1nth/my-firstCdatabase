//
// Created by gaosiqi on 2025/2/23.
//
#include <stdio.h>

int SUM(const int nums[], int len);
int main(){
  const int numbers[] = {5,9,6,7,8};
  int Sum = SUM(numbers, sizeof(numbers)/sizeof(int));//sizeof函数：sizeof(array) = sizeof(array[0]) * len(array)
  //既可以sizeof数组，也可以sizeof数组的元素。
  printf("Sum = %d\n", Sum);
  return 0;

}

int SUM(const int nums[], int len){
  if(len == 1){
    return nums[0];
  }
  int partial_sum = SUM(nums, len - 1);
  return partial_sum + nums[len - 1];
}