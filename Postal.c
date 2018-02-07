/**
Name: Pavan Kamra
Date: November 20, 2014
Course: BTP100
Purpose: To validate a postal code
**/

#include <stdio.h> 
#include <string.h> 
#include <ctype.h>

void toUpper(char c[]); // function prototype 
void Validation(char c[], int * num); // function prototype 

void main(void) {

  // variable declaration
  int length, x = 0;
  char Postal[31];

  //while statement to contuinily run the program till the postal code is validated. 
  while (x == 0) {
    printf("Enter a Postal Code [LNL NLN], L: alphabet letters, N= Number: ");
    scanf("%[^\n]%*c", Postal);
    length = strlen(Postal);
    toUpper(Postal);
    Validation(Postal, & x);
    if (x == 1) {
      printf("Yes, %s is a valid Canadian postal code. Good bye. \n", Postal);
      break;
    }
  }
}

// this makes the string uppercase
void toUpper(char c[]) {
  int i;
  for (i = 0; c[i] != '\0'; i++) {
    c[i] = toupper(c[i]);
  }
}

// This checks the validation of the program 
void Validation(char c[], int * num) {
  int i;
  for (i = 0; c[i] != '\0'; i++) {
    if (c[7] != '\0') {
      printf("Error! It requires 7 positions in a postal code.\n"); * num = 0;
      break;
    } else if (!isalpha(c[0]) || !isalpha(c[2]) || !isalpha(c[5])) {
      printf("Error! Position 1, 3, 6 should be alphabet letters.\n"); * num = 0;
      break;
    } else if (!isdigit(c[1]) || !isdigit(c[4]) || !isdigit(c[6])) {
      printf("Error!Position 2, 5, 7 should be digits.\n"); * num = 0;
      break;
    } else if (!(isspace(c[3])) && isdigit(c[1]) && isdigit(c[4]) && isdigit(c[4]) && isalpha(c[0]) && isalpha(c[2]) && isalpha(c[5])) {
      printf("Error! Position 4 should be a white space\n");
      break; * num = 0;
    } else { * num = 1;
    }
  }
}