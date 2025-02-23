//
// Created by gaosiqi on 2025/2/18.
//
//important

#include <stdio.h>
#define LEN 10
//少使用全局变量，不好维护。int dict[LEN] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
//如果在函数声明和实现的时候没有加const，main函数可能会为了防止修改dict，而在定义数组时前加上const，
//就会出现dictinary(actual argument):const int dict[],dictionary(formal parameter):int dict[],c中允许运行，会把const pass掉，但可能发生危险
//c++中不允许运行，不允许这种转化。
//int dict[]: deliver the address of the first element of the array.
//全局变量会被用到整个文件结束，所以假如有别的人使用这个文件，且另外写了一个函数，里面可以对全局变量进行修改，很危险。
//全局变量不设初值，会被初始化为0。局部变量不设初值，会被编译器给一个垃圾值。

int BinarySearch(int target, const int dict[], int len); //dict[] is a sorted array,方括号里面不能写参数，和定义数组的时候不同（必须写参数分配大小）
int main(void) {
    int dict[LEN] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    int target = 0;
    scanf("%d", &target);
    printf("%d", BinarySearch(target, dict, LEN));
    return 0;
}

//todo:为什么要加const：1.函数实现者和函数调用者的一个契约，防止被修改。
//2.防止出现危险（上面c和c++那个）
//另外：如果是数组，要给一个formal argument，如果是字符串，可以不用。因为字符串以\0结尾，所以可以知道字符串的长度。
int BinarySearch(int target, const int dict[], int len) {
    //dict[0] = 100;Cannot assign to readonly type const int.array变成了只读的，不能修改。
    //如果不再加一个参数，编辑器就不知道数组有多大，会出现未定义行为。所以加了参数len。
    int low = 0;
    int high = len - 1;
    //int index = -1;useless
    while (low <= high) {
        int mid = (low + high) / 2;
        if (target < dict[mid]) {
            high = mid - 1;
        } else if (target > dict[mid]) {
            low = mid + 1;
        } else {
            //index = mid;
            return mid; //equal to break;
        }
    }
    //printf("%d\n", index);
    return -1; //定义了int类型的函数，所以要有返回值。如果定义void类型，可以return 0
}


/*如果是数列里面有多个要找的数，返回最左边的下标。
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
            high = mid - 1;//寻找最左边的数
        }
    }
    printf("%d\n", index);
    return 0;
}
*/
