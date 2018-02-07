/**
Name: Pavan Kamra
Date: 12/6/2014
Course: BTP100
Purpose: calculates statistics from numerical information that is given in a file.
**/

#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

FILE * openRead(char fName[]);

void main(void) {
  // variable declaration 
  float numbers[40], total = 0, mean, squared[40], squaredsum, deviation, squarerooted;
  int i, counter = 0;
  char answer[1];
  FILE * fpin;

  printf("Enter the name of the data file :");
  scanf("%s", answer);
  fpin = openRead(answer);

  // puts all numbers in array   
  for (i = 0; i < 39; i++) {
    fscanf(fpin, "%f ", & numbers[i]);
    total = total + numbers[i];
    counter = counter + 1;
  }
  // adds all squared numbers in array for deviation 
  for (i = 0; i < 39; i++) {
    squared[i] = numbers[i] * numbers[i];
    squaredsum = squaredsum + squared[i];
  }

  mean = total / counter; // calculates mean 
  deviation = ((squaredsum / counter) - (mean * mean));
  squarerooted = sqrt(deviation);
  printf("\nThe number of data values read from this file was %d\n", counter);
  printf("Their statistical mean is %.2f\n", mean);
  printf("Their standard deviation is %.2f\n", squarerooted);
  fclose(fpin);
}

// function that checks if it can read the file. 
FILE * openRead(char fName[]) {
  FILE * fpin = NULL;
  fpin = fopen(fName, "r");
  if (fpin == NULL) {
    printf("Cannot open the file. \n");
    exit(1);
  } else
    return fpin;
}