//
// Created by gaosiqi on 2025/2/21.
//
//
// Created by gaosiqi on 2025/2/19.
//
//对两个有序数组进行合并
#include <stdio.h>
#define LEN_L 5
#define LEN_R 6
int L[LEN_L] = {1, 3, 5, 7, 9};
int R[LEN_R] = {0, 2, 4, 6, 8, 10};
void Merge(const int left[],int len_L,
           const int right[], int len_R);
int main() {
    Merge(L, LEN_L, R, LEN_R);
    return 0;
}
void Merge(const int left[],int len_L,
           const int right[], int len_R) {
    int l = 0;
    int r = 0;
    //TODO:l < LEN_L && r < LEN_R 两个数组都没有输出完毕
    while (l < len_L && r < len_R) {
        //不是恒成立，因为l和r其中之一会在最后运算时加1，与LEN_L或LEN_R相等。
        if (left[l] < right[r]) {
            printf("%d", left[l]);
            l++;
        } else {
            printf("%d", right[r]);
            r++;
        }
    }
    //TODO:l >= LEN_L || r >= LEN_R 其中一个输出完毕
    while (l < len_L) {
        printf("%d", left[l]);
        l++;
    }
    while (r < len_R) {
        printf("%d", right[r]);
        r++;
    }
}