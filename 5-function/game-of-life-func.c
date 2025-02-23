//
// Created by gaosiqi on 2025/2/19.
//
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define SIZE 6
const int board[SIZE][SIZE] = {
  {0},
  {0, 1, 1, 0, 0, 0},
  {0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0},
  {0, 0, 0, 1, 1, 0},
  {0}
};
/*const int board[SIZE][SIZE] = {
         [1][1] = 1, [1][2] = 1
         [2][1] = 1, [2][2] = 1
         [3][3] = 1, [3][4] = 1
         [4][3] = 1, [4][4] = 1
};
 */
int main() {
  //TODO:play game of life
  //对于边缘的格子来说，周围没有八个格子，所以不适用规则。若单独把边缘的格子if出来，过于麻烦（因为四条边缘和四个角都不一样）。
  //有如下方法；1.扩充棋盘，让边缘的格子都有八个格子，即改为8*8的棋盘，并把最外的一层设置成0。
  int old_board[SIZE + 2][SIZE + 2] = {0}; //二维数组存储时本质上还是按照一维数组的处理方式，即按行存储，所以可以直接{0}
  for (int row = 1; row <= SIZE; row++) {
    for (int col = 1; col <= SIZE; col++) {
      old_board[row][col] = board[row - 1][col - 1];
    }
  }
  //TODO:print the board
  for (int row = 1; row <= SIZE; row++) {
    for (int col = 1; col <= SIZE; col++) {
      //? : 是三目运算符,用法是：condition ? expression1 : expression2
      //如果condition为真，则返回expression1的值，否则返回expression2的值
      //嵌套使用会降低代码可读性
      //printf("%d ", old_board[row][col]);
      printf("%c ", old_board[row][col] ? '*' : ' ');
    }
    printf("\n"); //换行
  }
  sleep(1);
  system("cls");
  //old_board apply the rules > new_board
  int new_board[SIZE + 2][SIZE + 2] = {0};
  //TODO:防止一轮结束
  for (int i = 0; i < 10; i++) {
    for (int row = 1; row <= SIZE; row++) {
      for (int col = 1; col <= SIZE; col++) {
        //counting live cells in the neighbor board[row][col]
        int neighbors =
            old_board[row - 1][col - 1] +
            old_board[row - 1][col] +
            old_board[row - 1][col + 1] +
            old_board[row][col - 1] +
            old_board[row][col + 1] +
            old_board[row + 1][col - 1] +
            old_board[row + 1][col] +
            old_board[row + 1][col + 1];


        //apply the rules
        if (old_board[row][col] == 1) {
          // if (neighbors == 2 || neighbors == 3) {
          //   new_board[row][col] = 1;
          // } else {
          //   new_board[row][col] = 0;
          //or new_board[row][col] = neighbors == 2 || neighbors == 3 ? 1 : 0;
          new_board[row][col] = (neighbors == 2 || neighbors == 3);
        } else {
          new_board[row][col] = (neighbors == 3);
        }
      }
    }
    //new_board -> old_board
    for (int row = 1; row <= SIZE; row++) {
      for (int col = 1; col <= SIZE; col++) {
        old_board[row][col] = new_board[row][col];
      }
    }
    sleep(1); //sleep 1s
    //Linux: unistd.h
    //Windows: windows.h Sleep(1000) 1000ms = 1s


    //Window: system("cls");
    //Linux: system("clear");
    system("cls"); //clear the screen

    for (int row = 1; row <= SIZE; row++) {
      for (int col = 1; col <= SIZE; col++) {
        printf("%c ", new_board[row][col] ? '*' : ' ');
      }
      printf("\n");
    }
  }
}

