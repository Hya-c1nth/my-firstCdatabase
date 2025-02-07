//
// Created by gaosiqi on 2025/2/6.
//
#include <stdio.h>
int main(){
  const double MOL = 6.02E23;
  const int GRAM_PER_MOL = 32;
  int mass = 6;
  double quantity = mass * 1.0 / GRAM_PER_MOL * MOL;
  //e: exponent
  //g: significant digits
  printf("quantity: %.3e\nQuantity = %.5g\n", quantity, quantity);
}