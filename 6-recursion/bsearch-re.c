//
// Created by gaosiqi on 2025/2/23.
//
#include <stdio.h>
#include <stdlib.h>

int BSEARCH(int key, const int dict[], int low, int high);
int main() {
  const int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int target = 5;
  int index = BSEARCH(target, numbers, 0, sizeof(numbers) / sizeof(int) - 1);
  printf("index = %d\n", index);
  return 0;
}
/*
int BSEARCH(const int nums[], int len, int target) {
  if (len == 1) {
    return nums[0] == target ? 0 : -1;
  }
  int mid = len / 2;
  if (nums[mid] == target) {
    return mid;
  } else if (nums[mid] > target) {
    return BSEARCH(nums, mid, target);
  } else {
    return BSEARCH(nums + mid, len - mid, target) + mid;
  }
}
*/

int BSEARCH(int key, const int dict[], int low, int high) {
//  if (low = high) {
//    if (dict[low] == key) {
//      return low;
//    }
//    return -1;
//  }
  if (low > high) {
    return -1;
  }
  int mid = (low + high) / 2;
  if (dict[mid] == key) {
    return mid;
  } else if (dict[mid] > key) {
    return BSEARCH(key, dict, low, mid - 1);
  } else {
    return BSEARCH(key, dict, mid + 1, high);
  }
}
