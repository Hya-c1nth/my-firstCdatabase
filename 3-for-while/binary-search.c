//
// Created by gaosiqi on 2025/2/18.
//
//important

#include <stdio.h>
#define LEN 10
int dict[LEN] = {1,1,2,3,5,8,13,21,34,55};
/*int main(void) {
    int target = 0;
    scanf("%d", &target);
    int low = 0;
    int high = LEN - 1;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (target < dict[mid]) {
            high = mid - 1;
        } else if (target > dict[mid]) {
            low = mid + 1;
        } else {
            index = mid;
            break;
        }
    }
    printf("%d\n", index);
    return 0;
}
*/
//如果是数列里面有多个要找的数，返回最左边的下标。
int main(void) {
    int target = 0;
    scanf("%d", &target);
    int low = 0;
    int high = LEN - 1;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (target < dict[mid]) {
            high = mid - 1;
        } else if (target > dict[mid]) {
            low = mid + 1;
        } else {
            index = mid;
            high = mid - 1;
        }
    }
    printf("%d\n", index);
    return 0;
}