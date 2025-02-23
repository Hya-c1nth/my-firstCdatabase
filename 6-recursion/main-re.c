//
// Created by gaosiqi on 2025/2/22.
//
#include <stdio.h>
int main(int argc, char *argv[]) {
  if (argc == 1) {
      return 0;
  }
  printf("%s\n", argv[argc - 1]);
  main(argc - 1, argv);
  return 0;//在这一行才定义完，但是在上一行就调用了。编译原理课会讲。
}