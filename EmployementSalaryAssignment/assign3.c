/**
  Name: Pavan Kumar Kamra 
  Course: BTP100
  Policy: I declare that the attached assignment is wholly my own work in accordance with Seneca Academic Policy. No part
  of this assignment has been copied manually or electronically from any other source (including web sites) or 
  distributed to other students. 
**/
 
#include <stdio.h> 
#include "sales.h"
#include <stdlib.h> 
#define MAX 1000

// functions used. 
FILE * openRead(char fName[]);
FILE * openWrite(char fName[]);
int setArray(FILE * fp, struct salesPerson sRec[]);
void calcPay(struct salesPerson sRec[], float lvl[], int rNum);
void sortPay(struct salesPerson sRec[], int recNum);
void writePay(struct salesPerson sRec[], int rNum, FILE * fp);

void main() {
  int records, totalPay, i;
  float level[5] = {0.02,0.04,0.06,0.08,0.10};
  struct salesPerson employees[MAX];
 
 
  FILE * fpin = NULL;
  FILE * fpout = NULL;
  fpin = openRead("sales.dat");
  fpout = openWrite("pay.txt");
  records = setArray(fpin, employees);
  calcPay(employees, level, records);
  sortPay(employees, records);
  writePay(employees, records, fpout);
  fclose(fpin);
  fclose(fpout);
}

// a function that makes sure it can read the file.
FILE * openRead(char fName[]) {
  FILE * fpin = NULL;
  fpin = fopen(fName, "r");
  if (fpin == NULL) {
    printf("Cannot open the file. \n");
    exit(1);
  } else
    return fpin;
}

// a function that makes sure it can write in a file.
FILE * openWrite(char fName[]) {
  FILE * fpout = NULL;
  fpout = fopen(fName, "w");
  if (fpout == NULL) {
    printf("Cannot open the file. \n");
    exit(1);
  } else
    return fpout;
}

// a function that calculates the amount of records in a file. 
int setArray(FILE * fp, struct salesPerson sRec[]) {
  int i = 0, counter = 0;
  while (fscanf(fp, "%d:%[^:]:%[^:]:%d:%lf[\n]%*c", & sRec[i].salesNum, sRec[i].lastName, sRec[i].firstName, & sRec[i].salesLevel, & sRec[i].salesAmount) == 5) {
    i++;
  }
  return i;
}

// a function that calculates the sales Pay for each employee
void calcPay(struct salesPerson sRec[], float lvl[], int rNum) {
  int i = 0;
  while (rNum != i) {
    if (sRec[i].salesLevel == 1)
      sRec[i].salesPay = (200 + (sRec[i].salesAmount * 0.02));
    else if (sRec[i].salesLevel == 2)
      sRec[i].salesPay = (200 + (sRec[i].salesAmount * 0.04));
    else if (sRec[i].salesLevel == 3)
      sRec[i].salesPay = 200 + ((sRec[i].salesAmount * 0.06));
    else if (sRec[i].salesLevel == 4)
      sRec[i].salesPay = 200 + ((sRec[i].salesAmount * 0.08));
    else
      sRec[i].salesPay = 200 + ((sRec[i].salesAmount * 0.10));

    i = i + 1;
  }
}

// a function that sorts the pays in decending order
void sortPay(struct salesPerson sRec[], int recNum) {
  int i, j;
  struct salesPerson temp;

  for (i = recNum - 1; i > 0; i--) {
    for (j = 0; j < i; j++) {
      if (sRec[j].salesPay < sRec[j + 1].salesPay) {
        temp = sRec[j];
        sRec[j] = sRec[j + 1];
        sRec[j + 1] = temp;
      }
    }
  }
}

// a function that prints out all the information. 
void writePay(struct salesPerson sRec[], int rNum, FILE * fp) {
  int i;
  fprintf(fp, "                          Weekly Payment Report                        \n");
  fprintf(fp, "---------------------------------------------------------------------------------\n");
  fprintf(fp, "| SNum  | Last Name          | First Name         | Lvl | Sales Amt | Week.Pay  |\n");
  fprintf(fp, "=================================================================================\n");
  for (i = 0; i < rNum; i++) {
    fprintf(fp, "| %4d  | %-18s | %-18s | %d   | $%7.2lf   | $%7.2lf |\n",
      sRec[i].salesNum, sRec[i].lastName, sRec[i].firstName, sRec[i].salesLevel, sRec[i].salesAmount, sRec[i].salesPay);
    fprintf(fp, "---------------------------------------------------------------------------------\n");
  }
}
