/** 
	Name: Pavan Kamra 
  Date: Sept 29 2014
	Policy: I declare that this is wholly my own work in accordance with Seneca 
	Academic Policy. No part of this work has been copied manually or 
	electtronically from any other source (including web sites) or distributed 
	to other students. 
**/

#include <stdio.h>

  main() {
    int sinNum;
    int exit = 1;

    while (exit == 1) {
      printf("SIN VALIDATOR");
      printf("SIN (0 to quit)");
      scanf("%d", & sinNum);

      if (sinNum == 0) {
        exit = 0;
        if (exit == 0) {
          printf("Have a nice day!\n");
        }
      } else {
        exit = 1;
      }

      //separating the digits to different variables.  
      int a, b, c, d, e, f, g, h, i;
      a = (sinNum / 100000000) % 10;
      b = (sinNum / 10000000) % 10;
      c = (sinNum / 1000000) % 10;
      d = (sinNum / 100000) % 10;
      e = (sinNum / 10000) % 10;
      f = (sinNum / 1000) % 10;
      g = (sinNum / 100) % 10;
      h = (sinNum / 10) % 10;
      i = (sinNum / 1) % 10;

      //adding the even digits by themselves. 
      b = b + b;
      d = d + d;
      f = f + f;
      h = h + h;

      // separating the even digits after doubling them. 
      int r, s, t, u;
      r = b / 10;
      b = b % 10;
      s = d / 10;
      d = d % 10;
      t = f / 10;
      f = f % 10;
      u = h / 10;
      h = h % 10;

      // calculating the even digits sum and odd digits sum. 
      int evenSum, oddSum, totalSum, totalSum1, diffSum;
      evenSum = r + b + s + d + t + f + u + h;
      oddSum = a + c + e + g;

      // Calculating the total sum. 
      totalSum = evenSum + oddSum;

      //finding the next highest integer multiple of 10. 
      totalSum1 = totalSum;
      totalSum1 = totalSum1 + 10;
      totalSum1 = totalSum1 - (totalSum % 10);
      diffSum = totalSum1 - totalSum;

      // if the sum equals the check then its a valid sin or else its not. 
      if (diffSum == i) {
        printf("This is a valid SIN\n");
      } else if (diffSum != i && sinNum != 0) {
        printf("This is not a valid SIN\n");
      }
    }
  }
