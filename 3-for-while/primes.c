//
// Created by gaosiqi on 2025/2/17.
//
#include <stdbool.h>
#include <stdio.h>
int main() {
  int max = 0;
  scanf("%d", &max);
  //test all number < max
  for (int number = 2; number <= max; number++) {
    //test if number is prime
    bool isPrime = true;//bool is also good to use
    for (int factor = 2; factor * factor <= number; factor++) {//there is no need to test more than sqrt(number)
      if (number % factor == 0) {
        isPrime = false;//number is not prime,0 is usable,too.
        //for bool:bool b = 5;is also acceptable,but not good.it is sames as bool b = true;
        //int c = b + 8;  c is 9,not 13.
        break;//find 1 factor, break the loop
      }
    }
    if (isPrime) {
      printf("%d\n", number);
    }
  }
  return 0;
}