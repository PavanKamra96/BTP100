/**
Name: Pavan Kamra
Date: October-24-2014
Purpose: Investment calculator
**/

#include <stdio.h>
float Fvalue(int prin, int year, float annual);

main() {
  int principal, Yrs;
  float annualRate, futureval;

  // input of the principal value, annual rate, and Years.
  printf("Investment Calculator\n===================\n");
  printf("Principal: ");
  scanf("%d", & principal);
  printf("Annual Rate: ");
  scanf("%f", & annualRate);
  printf("No of Years: ");
  scanf("%d", & Yrs);
  futureval = Fvalue(principal, Yrs, annualRate); // call the function   
  printf("The future value is $%.2f\n", futureval); // print out the result
}

// Function that calculates your future investments amount. 
float Fvalue(int prin, int year, float annual) {
  int i;
  float x = 1 + annual, y = 1, fv;

  for (i = 0; i < year; i++) {
    y = y * x;
  }

  fv = prin * y;
  return fv; //return the future value. 

}