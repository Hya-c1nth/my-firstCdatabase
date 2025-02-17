//
// Created by gaosiqi on 2025/2/7.
//
#include <stdio.h>
int main() {
  int a = 0;
  int b = 0;
  int c = 0;
  int min = 0;
  printf("Enter three integers: ");
  scanf("%d %d %d", &a, &b, &c);
  if (a < b) {
    min = a;
  } else {
    min = b;
  }
  if (c < min) {
    min = c;
  }
  printf("The minimum is %d\n", min);
  return 0;
}


/*#include <stdio.h>
int main() {
  int a = 0;
  int b = 0;
  int c = 0;
  int min = 0;
  if (a > b){
    if(b > c){
      min = c;
    } else {
      min = b;
    }
  } else {
    if(a > c){
      min = c;
    } else{
      min = a;
    }
  }
  printf("The minimum is %d\n", min);
  return 0;
  }
 */