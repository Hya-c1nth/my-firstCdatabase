//
// Created by gaosiqi on 2025/2/24.
//
//合并排序
//递归实现
#include <stdio.h>
#define LEN 7

//TODO:merge sort
void MERGE_SORT(int nums[], int left, int right);

//TODO:merge nums[left..mid] and nums[mid + 1..right]
void MERGE(int nums[], int left, int mid, int right);

int main() {
  int numbers[LEN] = {38, 27, 43, 3, 9, 82, 10};
  for (int i = 0; i < LEN; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");
  MERGE_SORT(numbers, 0, LEN - 1);
  for (int i = 0; i < LEN; i++) {
    printf("%d ", numbers[i]);
  }
}

void MERGE_SORT(int nums[], int left, int right) {
  if (left == right) {
    return;
  }
  int mid = (left + right) / 2;
  MERGE_SORT(nums, left, mid);
  MERGE_SORT(nums, mid + 1, right);
  MERGE(nums, left, mid, right);
}


void MERGE(int nums[], int left, int mid, int right) {
  int copy[LEN] = {0};
  int left_index = left;
  int right_index = mid + 1;
  int copy_index = left;
  while (left_index <= mid && right_index <= right) {
    if (nums[left_index] < nums[right_index]) {
      copy[copy_index] = nums[left_index];
      left_index++;
    } else {
      copy[copy_index] = nums[right_index];
      right_index++;
    }
    copy_index++;
  }
  while (left_index <= mid) {
    copy[copy_index] = nums[left_index];
    left_index++;
    copy_index++;
  }
  while (right_index <= right) {
    copy[copy_index] = nums[right_index];
    right_index++;
    copy_index++;
  }
  for (int i = left; i <= right; i++) {
    nums[i] = copy[i];
  }
}
