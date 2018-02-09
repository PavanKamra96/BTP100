/*
    Name: Pavan Kumar Kamra
    Course: BTP100
    Policy: I declare that the assignment is wholly my own work in accordance with Seneca Academic Policy. No Part of this assignment has 
         been copied manually or electronically from any other source (including web sites) or distributed to other students.
*/

#include <stdio.h>

int Decreasing(int a2[4]);
int Increasing(int a[4]);
int equation(int a3[4]);

main() {
  int num, a, b, c, d, e, f, g, h, x, y, point = 0; // variables 

  while (point == 0) {
    printf("\nEnter a four digit number that at least 2 digits are different:"); // ask users input
    scanf("%d", & num);
    e = (num / 1000) % 10;
    f = (num / 100) % 10;
    g = (num / 10) % 10;
    h = (num / 1) % 10;

    // if statement that checks if num is 6174, all same digits, and more then 4 digits
    if (num == 6174) {
      point = 1;
    } else if (e == f && e == g && e == h) {
      printf("All 4 digits are the same. \nInput a four digit number with at least 2 digits different.");
    } else if (num < 1000) {
      printf("Need a four digit number with at least 2 digits different");
    } else {
      printf("%d    ", num);
      do {
        a = (num / 1000) % 10;
        b = (num / 100) % 10;
        c = (num / 10) % 10;
        d = (num / 1) % 10;
        int array[4] = {a,b,c,d};
        int array2[4] = {a,b,c,d};

        // function call
        Decreasing(array2);
        y = equation(array2);

        // function call
        Increasing(array);
        x = equation(array);

        num = y - x; // subtracts the numbers  
        printf("%d    ", num); //displays the results
      } while (num != 6174);
    }
  }
}

// arranged decreasing order 
int Decreasing(int a2[4]) {
  int m, n, tmp2;
  for (m = 0; m < 4; ++m) {
    for (n = m + 1; n < 4; ++n) {
      if (a2[m] < a2[n]) {
        tmp2 = a2[m];
        a2[m] = a2[n];
        a2[n] = tmp2;
      }
    }
  }
}

// arranged increasing order
int Increasing(int a[4]) {
    int i, j, tmp;
    for (i = 0; i < 4; ++i) {
      for (j = i + 1; j < 4; ++j) {
        if (a[i] > a[j]) {
          tmp = a[i];
          a[i] = a[j];
          a[j] = tmp;
        }
      }
    }
  }
// equation to change array to a integer number, so its easier to subtract.
    int equation(int a3[4]) {
    int eq;
    eq = (((a3[0] * 10 + a3[1]) * 10 + a3[2]) * 10 + a3[3]);
    return eq;
}
