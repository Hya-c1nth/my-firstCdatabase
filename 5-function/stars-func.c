//
// Created by gaosiqi on 2025/2/17.
//
#include <stdio.h>

void Print(char ch, int count);

int main() {
  int lines = 0;
  scanf("%d", &lines);
  for (int i = 0; i < lines; i++) {
    /*for (int j = 0; j < lines - 1 - i; j++) {
      printf(" ");
    }
    for (int j = 0; j < 2 * i + 1; j++) {
      printf("*");
    }
    */
    Print(" ", lines - 1 - i);
    Print("*", 2 * i + 1);
    if (i != lines - 1) {
      printf("\n");
    }
  }
  return 0;
}

void Print(char ch, int count) {
  for (int i = 0; i < count; i++) {
    printf("%c", ch);
  }
}

