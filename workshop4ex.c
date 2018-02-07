/** 
Name: Pavan Kumar Kamra
Date: October-24-2014
Purpose: A average calculator based on student numbers
**/
#include <stdio.h>

float getFloat(float min, float max);
void clear(void);#
define MIN 0# define MAX 100

//main: calculates sum and finds average of numbers.
float main() {
    float input, average, sum;
    int counter = 0, s = 1;
    while (s == 1) { // a while loop that will keep contuining till 0 is entered.
      input = getFloat(MIN, MAX);
      if (input != 0) {
        sum = sum + input; // find the sum of all the marks submitted 
        counter = counter + 1; // counts the amount of people the marks are for
      } else {
        s = 0;
        average = sum / counter; // calculates the average of the marks 
        printf("Entered %d students, Average is %.2f\n", counter, average);
      }
    }
  }
  // a loop that programs if the number is acceptable and does not allow any characters.
float getFloat(float min, float max) {
  float number, kt = 1, rc;
  char a;
  do {
    printf("Enter a student mark [%.2f,%.2f] : ", min, max);
    rc = scanf("%f%c", & number, & a);
    if (rc == 0) {
      printf("**No input accepted!**\n\n");
      clear();
    } else if (a != '\n') {
      printf("**Trailing characters!**\n\n");
      clear();
    } else if (number < min || number > max) {
      printf("**Out of range!**\n\n");
    } else
      kt = 0;
  } while (kt == 1);
  return number;
}

// clears input buffer of characters
void clear(void) {
  while (getchar() != '\n')
  ;
}