//
// Created by gaosiqi on 2025/2/19.
//
//对两个有序数组进行合并
#include <stdio.h>
#define LEN_L 5
#define LEN_R 6
int L[LEN_L] = {1, 3, 5, 7, 9};
int R[LEN_R] = {0, 2, 4, 6, 8, 10};

int main() {
  int l = 0;
  int r = 0;
  //TODO:l < LEN_L && r < LEN_R 两个数组都没有输出完毕
  while (l < LEN_L && r < LEN_R) {
    //不是恒成立，因为l和r其中之一会在最后运算时加1，与LEN_L或LEN_R相等。
    if (L[l] < R[r]) {
      printf("%d", L[l]);
      l++;
    } else {
      printf("%d", R[r]);
      r++;
    }
  }
  //TODO:l >= LEN_L || r >= LEN_R 其中一个输出完毕
  while (l < LEN_L) {
    printf("%d", L[l]);
    l++;
  }
  while (r < LEN_R) {
    printf("%d", R[r]);
    r++;
  }
  //TODO:l >= LEN_L || r >= LEN_R
}

/*对于一个数组，如何实现排序？
1.合并排序：如本代码显示，将数组完全拆分成单个元素，看成一个个数组，然后merge。
再对merge后的数组继续merge，直到只有一个数组。
#include <stdio.h>
#include <stdlib.h>

// 合并两个有序数组
void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1; // 左子数组的长度
  int n2 = right - mid; // 右子数组的长度

  // 创建临时数组
  int *L = (int *) malloc(n1 * sizeof(int));
  int *R = (int *) malloc(n2 * sizeof(int));

  // 将数据复制到临时数组
  for (int i = 0; i < n1; i++) {
    L[i] = arr[left + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[mid + 1 + j];
  }

  // 合并两个有序数组
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // 将左子数组剩余的元素复制到原数组
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // 将右子数组剩余的元素复制到原数组
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }

  // 释放临时数组的内存
  free(L);
  free(R);
}

// 合并排序
void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2; // 计算中间位置

    // 递归地对左子数组和右子数组进行排序
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // 合并两个有序子数组
    merge(arr, left, mid, right);
  }
}

// 打印数组
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  printf("原始数组: \n");
  printArray(arr, arr_size);

  mergeSort(arr, 0, arr_size - 1);

  printf("排序后的数组: \n");
  printArray(arr, arr_size);

  return 0;
}


2.快速排序：
#include <stdio.h>

// 快速排序
void quickSort(int arr[], int left, int right) {
  if (left < right) {
    int i = left, j = right;
    int tmp = arr[left]; // 取第一个元素为基准

    while (i < j) {
      // 从右向左找到第一个小于基准的元素
      while (i < j && arr[j] >= tmp) {
        j--;
      }
      if (i < j) {
        arr[i] = arr[j];
        i++;
      }

      // 从左向右找到第一个大于基准的元素
      while (i < j && arr[i] < tmp) {
        i++;
      }
      if (i < j) {
        arr[j] = arr[i];
        j--;
      }
    }

    arr[i] = tmp; // 将基准元素放到正确的位置

    quickSort(arr, left, i - 1); // 递归地对左子数组进行排序
    quickSort(arr, i + 1, right); // 递归地对右子数组进行排序
  }
}
// 打印数组
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
int main() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  printf("原始数组: \n");
  printArray(arr, arr_size);

  quickSort(arr, 0, arr_size - 1);

  printf("排序后的数组: \n");
  printArray(arr, arr_size);

  return 0;
}

3.插入排序：
#include <stdio.h>

// 插入排序
void insertSort(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    int tmp = arr[i]; // 保存当前元素
    int j = i - 1; // 初始化比较元素的下标

    // 将当前元素插入到合适的位置
    while (j >= 0 && arr[j] > tmp) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = tmp;
  }
}

// 打印数组
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  printf("原始数组: \n");
  printArray(arr, arr_size);

  insertSort(arr, arr_size);

  printf("排序后的数组: \n");
  printArray(arr, arr_size);

  return 0;
}
4.冒泡排序：
#include <stdio.h>

// 冒泡排序
void bubbleSort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
}

// 打印数组
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  printf("原始数组: \n");
  printArray(arr, arr_size);

  bubbleSort(arr, arr_size);

  printf("排序后的数组: \n");
  printArray(arr, arr_size);

  return 0;
}

5.选择排序：
#include <stdio.h>

// 选择排序
void selectionSort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int min = i; // 记录最小元素的下标

    // 找到最小元素
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }

    // 将最小元素放到当前位置
    int tmp = arr[i];
    arr[i] = arr[min];
    arr[min] = tmp;
  }
}

// 打印数组
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  printf("原始数组: \n");
  printArray(arr, arr_size);

  selectionSort(arr, arr_size);

  printf("排序后的数组: \n");
  printArray(arr, arr_size);

  return 0;
}

6.希尔排序：
#include <stdio.h>

// 希尔排序
void shellSort(int arr[], int size) {
  // 初始增量
  int gap = size / 2;

  while (gap > 0) {
    // 对增量为gap的序列进行插入排序
    for (int i = gap; i < size; i++) {
      int tmp = arr[i]; // 保存当前元素
      int j = i - gap; // 初始化比较元素的下标

      // 将当前元素插入到合适的位置
      while (j >= 0 && arr[j] > tmp) {
        arr[j + gap] = arr[j];
        j -= gap;
      }
      arr[j + gap] = tmp;
    }

    // 减小增量
    gap /= 2;
  }
}

// 打印数组
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  printf("原始数组: \n");
  printArray(arr, arr_size);

  shellSort(arr, arr_size);

  printf("排序后的数组: \n");
  printArray(arr, arr_size);

  return 0;
}

7.堆排序：
#include <stdio.h>

// 堆排序
void heapSort(int arr[], int size) {
  // 构建大顶堆
  for (int i = size / 2 - 1; i >= 0; i--) {
    adjustHeap(arr, i, size);
  }

  // 交换堆顶元素与末尾元素，使末尾元素最大
  for (int i = size - 1; i >= 0; i--) {
    int tmp = arr[0];
    arr[0] = arr[i];
    arr[i] = tmp;

    // 重新对堆进行调整
    adjustHeap(arr, 0, i);
  }
}

// 调整大顶堆
void adjustHeap(int arr[], int i, int size) {
  int tmp = arr[i]; // 保存当前元素
  int j = i * 2 + 1; // 左子节点下标

  // 如果左子节点存在且大于当前元素，将左子节点与当前元素交换
  while (j < size && arr[j] > tmp) {
    arr[i] = arr[j];
    i = j;
    j = i * 2 + 1;
  }

  // 将当前元素放到正确的位置
  arr[i] = tmp;
}

// 打印数组
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  printf("原始数组: \n");
  printArray(arr, arr_size);

  heapSort(arr, arr_size);

  printf("排序后的数组: \n");
  printArray(arr, arr_size);

  return 0;
}

8.归并排序：
#include <stdio.h>
#include <stdlib.h>

// 归并排序
void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2; // 计算中间位置

    // 递归地对左子数组和右子数组进行排序
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // 合并两个有序子数组
    merge(arr, left, mid, right);
  }
}

// 合并两个有序数组
void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1; // 左子数组的长度
  int n2 = right - mid; // 右子数组的长度

  // 创建临时数组
  int *L = (int *) malloc(n1 * sizeof(int));
  int *R = (int *) malloc(n2 * sizeof(int));

  // 将数据复制到临时数组
  for (int i = 0; i < n1; i++) {
    L[i] = arr[left + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[mid + 1 + j];
  }

  // 合并两个有序数组
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // 将左子数组剩余的元素复制到原数组
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // 将右子数组剩余的元素复制到原数组
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }

  // 释放临时数组的内存
  free(L);
  free(R);
}

// 打印数组
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  printf("原始数组: \n");
  printArray(arr, arr_size);
  mergeSort(arr, 0, arr_size - 1);
  printf("排序后的数组: \n");
  printArray(arr, arr_size);
  return 0;
}
*/

















