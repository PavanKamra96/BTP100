/**
Name: Pavan Kamra
Date: 11/25/2014
Course: BTP100
Purpose: To find the largest number and its position. 
**/

#include < stdio.h > #define SIZE 11
void maxnum(int a[], int * m, int * element);

main() {
  int array[SIZE];
  int i = 0, max = 0;
  maxnum(array, & max, & i);
  printf("======================================\n");
  printf("The highest element is %d, position %d\n", max, i);
}

// fills in array, finds max and the index. 
void maxnum(int a[], int * m, int * element) {
  int i;
  for (i = 1; i < SIZE; i++) {
    printf("Enter a number %d:  ", i);
    scanf("%d", & a[i]);
    if (a[i] > * m) { * m = a[i]; * element = i;
    }
  }

}