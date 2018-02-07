/**
Name: Pavan Kamra
Course: BTP100-F14
Purpose: Roll to dice and find sum until you reach the users wanted sum. 
**/

#include <stdlib.h> 
#include <stdio.h> 
#include <time.h>

int roll(int s); //function prototype

// main function that promps the user and checks the sum
int main(void) {
  srand(time(NULL));
  int inquiredSum = 0;
  printf("\nGame of Dice\n============\n");
  do {
    printf("Enter total sought : ");
    scanf(" %d", & inquiredSum);

    if (inquiredSum > 12 || inquiredSum < 2)
      printf("** Invalid Input! Try Again! **\n");
    else {
      roll(inquiredSum);
    }
  } while (inquiredSum > 12 || inquiredSum < 2);
}

// function that rolls the two dice
int roll(int s) {
  int dice1, dice2, dice, diceCounter = 0;
  while (dice != s) {
    dice1 = 1 + (rand() % (6 + 1 - 1));
    dice2 = 1 + (rand() % (6 + 1 - 1));
    dice = dice1 + dice2;
    diceCounter = diceCounter + 1;
    printf("Result of throw %d : %d + %d\n", diceCounter, dice1, dice2);
  }
  printf("You got your total in %d throws!\n", diceCounter);
  return 0;
}
