//
// Created by gaosiqi on 2025/2/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int high = 100;
    int chance = 7;

    //print the rule of the game
    printf("the computer will generate a random number between 1 and %d\n"
    "you have %d changes.\n",
    high,chance);



    //generate a random number
    srand(time(NULL)); //use current time as seed for random generator
    int secret = rand() % high + 1;
    printf("secret = %d\n",secret);

    while (chance > 0) {
      //let the player enter his/her number
      printf("enter your guess between 1 and %d\n",high);


      int guess;
      //store the guess number
      //compare it with the random number
      //imform the player of the result
      scanf("%d",&guess);

      //loop:reapt until the player win or lose
      if(guess == secret) {
        printf("you win!\n");
        break;
      } else if(guess > secret) {
        printf("guess > secret\n");
      } else {
        printf("guess < secret\n");
      }
    chance--;
    }

    return 0;
}
