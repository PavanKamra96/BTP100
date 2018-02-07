/**
Name: Pavan Kamra
Date: 12/6/2014
Course: BTP100
Purpose: Changing file text from upper case to lower case and vice versa. 
**/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

FILE * openRead(char fName[]);
FILE * openWrite(char fName[]);

void main() {
  // variable declaration 
  char file1[100], file2[100];
  char line[100];
  char character, upper, lower;
  char words[20];
  FILE * fpin = NULL;
  FILE * fpout = NULL;

  printf("Case (U for upper, L for lower) :");
  scanf("%c", & character);
  printf("Name of the original file :");
  scanf("%s", & file1);
  printf("Name of the updates file :");
  scanf("%s", & file2);
  fpin = openRead(file1);
  fpout = openWrite(file2);

  // changes lower case to upper case
  if (character == 'U' || character == 'u') {
    do {
      upper = fgetc(fpin);
      upper = toupper(upper);
      fputc(upper, fpout);
    } while (upper != EOF);
  }

  // changes uppercase to lower case
  if (character == 'L' || character == 'l') {
    do {
      lower = fgetc(fpin);
      lower = tolower(lower);
      fputc(lower, fpout);
    } while (lower != EOF);
  }

  printf("Text has been updated and stored in updated.dat\n");
}

//function that reads the file and makes sure its readable. 
FILE * openRead(char fName[]) {
  FILE * fpin = NULL;
  fpin = fopen(fName, "r");
  if (fpin == NULL) {
    printf("Cannot open the file. \n");
    exit(1);
  } else
    return fpin;
}

FILE * openWrite(char fName[]) {
  FILE * fpout = NULL;
  fpout = fopen(fName, "w");
  if (fpout == NULL) {
    printf("Cannot open the file. \n");
    exit(1);
  } else
    return fpout;
}