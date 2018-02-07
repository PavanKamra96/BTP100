/* 
   Name: Pavan Kamra
   Course: BTP100
   Date: 2014-11-19
   Purpose: Fraction Simplifier, simplify's the user inputted numerator / denominator of fraction
*/

#include < stdio.h >
void simplify(int * numerator, int * denominator);

// main function
main() {
  int numerator, denominator; // variable declaration 
  printf("Fraction Simplifier\n==================\n");
  printf("Numerator: ");
  scanf("%d", & numerator); //input the users requested numerator  
  printf("Denominator: ");
  scanf("%d", & denominator); //input the users requested denominator
  printf("%d / %d", numerator, denominator);
  simplify( & numerator, & denominator); //inputting the pointer 
  printf(" = %d / %d\n", numerator, denominator); //displaying the result

}

//function that simplify's the users inputted numerator / denominator
void simplify(int * numerator, int * denominator) {
  int i;
  for (i = 2; i < 9; i++) {
    while ( * numerator % i == 0 && * denominator % i == 0 && * numerator != 0 && * denominator != 0) { * numerator = * numerator / i; * denominator = * denominator / i;
    }
  }
}
