/**
Name: Pavan Kamra
Date: October-24-2014
Purpose: Prime numbers in rows!
**/

#include <stdio.h>
 
 int main() {
    int num1, num2, p, j, f, column, number = 0;
    // this collects the information
    printf("Table of Primes\n===================\n");
    printf("Enter the upper limit: ");
    scanf("%d", & num1);
    printf("# of columns: ");
    scanf("%d", & column);
    printf("\n");

    // a for loop to calculate the prime numbers
    for (p = 1 + 1; p < num1; p++) {
      f = 0;
      for (j = 2; j <= p / 2; ++j) {
        if (p % j == 0) {
          f = 1;
          break;
        }
      }
      if (f == 0) {
        number = number + 1;
        if (number % column == 0)
          printf("%d\n", p);
        else
          printf("%d\t", p);
      }
    }
    return 0;
  }
