//
// Created by gaosiqi on 2025/2/18.
//
//算法中最重要的两个模块：排序和查找。
//这个是选择排序，是排序中最简单的。
//Ubuntu是什么:虚拟机，能够模拟Linux运行环境
#include <stdio.h>
#define LEN 20
int numbers[LEN] = {0};
void SelectionSort(int arr[], int len);
int GetMainIndex(const int arr[], int begin, int end);
void swap(int left, int right);
void PrintArray(const int arr[], int len);
int main() {
  /*一、因为用户输入的位数是不定的，所以无法用for循环。并且scanf中的%d会忽略前导空白符（换行、空格、制表符都是空白符），
   *直到读取到非空白字符为止。所以在本代码运行时输入的回车会被“吞掉”，导致始终无法终止输入。
   *二、如遇到非数字字符（如字母或符号），scanf会停止读取，并将已读取部分作为整数返回，如输入42.5，会得到42，“.5”会留在缓冲区。
   *三、scanf是有返回值的，可以用返回值控制用户输入是否结束。scanf返回值有不同情况：1.input failure:return EOF(end of file),
   *在C语言中常被表现为-1。scanf从数据流中读取数据，有两种情况会发生该状况，一是数据流中没有数据，或流"broken"。
   *通常发生第一种情况。所以可以利用这个特点，当不要继续输入时从控制台发送一个EOF信号给scanf，让它终止读取。
   *正常输入数据时，回车之后才能把输入的数发送给scanf，因为存在缓冲区，回车会把缓冲区里面的发送出去。
   *2.number of matched items：读数据时确实读到了数据，也有匹配和不匹配的情况。如想要整数却读到了字符串，会出现match failure，
   *scanf也会终止，返回的是出现match failure之前已经读到的数（如第一个都不匹配，则返回0）。如果一直都匹配，
   *那么会把要求的百分号（即数）消耗完了，才返回总共匹配了多少个。
   *alt + f12 打开terminal之后
   *在mac/linux系统下：换行之后按ctrl + D（作用是强制把缓冲区的内容发送出去，不换行就会把该行的内容发送给scanf，
   *再按一次则发送空，就可以了。换行后直接发送空，所以直接就可以）
   *windows系统下是 crtl + z：即使按这个也可能没效果，因为windows下有多种多样的终端
   *四、另外一种控制的方法：input/output redirection
   *控制台称为标准输入设备，从控制台输入称为stdin。不再从控制台读取数据，而是从写好的文件中读取数据
   */
  int len = -1;
  while (scanf("%d", &numbers[++len]) != EOF);
  /*这个本质上是while(...) {
   *;},但是语句过于简单，所以省略了大括号。
   *另外 for( ; ; );
   *会出现无限循环，因为条件不能为0，所以会自己在中间添加一个整数，所以恒为1，不会终止。
   */


  //i++和++i不同，一个是前置递增，一个是后置递增。如int a = 5;
  //int b = ++a; a先递增为6，然后b被赋值为6
  //int a = 5;
  //int b = a++; b 被赋值为 5，然后 a 递增为 6
  //selection sort

  return 0;
}
int GetMainIndex(const int arr[], int begin, int end){//设置形参的时候不是一定要设置长度为参数，比如这个设置的就是开始和结束的下标
  int min_index = begin;
  int min = arr[begin];
  for (int j = begin + 1; j < end; j++) {
    if (arr[j] < min) {
      min = arr[j];
      min_index = j;
    }
  }
  return min_index;
}
//既然是传递值，那为什么这个函数就可以正常使用呢？
//因为传值机制不变，但原始数组的地址被copy给了形参，所以可以通过地址找到数组，然后通过下标找到数组的元素，并进行修改。
void SelectionSort(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    int min_index = GetMainIndex(arr, i, len);
    //swap numbersp[i] and numbers[min_index]
    int temp = arr[min_index];
    arr[min_index] = arr[i];
    arr[i] = temp;
    swap(arr[min_index], arr[i]);
  }
}
//会出现没有成功交换的情况，因为实参传递给形参的时候出现了问题。c语言中，函数的参数是传递的是值，而不是引用，即直接把实参的值
//复制给形参，所以形参的改变不会影响到实参。
//所以要想实现交换，要把实参的地址传递给形参，即引用传递。
//void swap(int left, int right) {
//  int temp = left;
//  left = right;
//  right = temp;
//}
void PrintArray(const int arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
