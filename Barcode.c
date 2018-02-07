/** 
	Name: Pavan Kamra 
    Date: October 3  2014
	Policy: I declare that this is wholly my own work in accordance with Seneca
		Academic Policy. No part of this work has been copied manually or
		electtronically from any other source (including web sites) or distributed
		to other students. 
**/
#include <stdio.h>

  main() {
    int exit = 1;
    long long UPC;
    long long a, b, c, d, e, f, g, h, i, j, k, l;
    long long sumodd, sumeven, totalSum = 0;
    long check;
    while (exit == 1) {
      // asking the user to input the UPC. 
      printf("UPC(0 to quit):");
      scanf("%lld", & UPC, "\n");

      // if the user inputs 0 for UPC #, then the program exits and outputs 
      //"Have a nice day" 
      if (UPC == 0) {
        exit = 0;
      }
      if (exit == 0) {
        printf("Have a nice day!\n");
      }

      // I separate each digit of the UPC code. 
      a = (UPC / 100000000000) % 10;
      b = (UPC / 10000000000) % 10;
      c = (UPC / 1000000000) % 10;
      d = (UPC / 100000000) % 10;
      e = (UPC / 10000000) % 10;
      f = (UPC / 1000000) % 10;
      g = (UPC / 100000) % 10;
      h = (UPC / 10000) % 10;
      i = (UPC / 1000) % 10;
      j = (UPC / 100) % 10;
      k = (UPC / 10) % 10;
      l = (UPC / 1) % 10;
      // I add all the sum of the odd elements and multiple by 3. 
      sumodd = (a + c + e + g + i + k) * 3;
      // I add all the sum of the even elements.
      sumeven = b + d + f + h + j;
      // I add the odd elements + even elements to make the total sum.
      totalSum = sumodd + sumeven + l;

      // if the remainder of the totalsum % by 10 is 0 then its a valid UPC
      // or else its not a valid UPC code. 
      if (totalSum % 10 == 0 && exit == 1) {
        printf("This is a valid UPC\n");
        printf("The company code is: %lld%lld%lld%lld%lld%lld.\n", a, b, c, d, e, f);
        printf("The produce code is: %lld%lld%lld%lld%lld.\n", g, h, i, j, k);
      } else if (totalSum % 10 != 0 && exit == 1) {
        printf("This is not a valid UPC\n");
      }
    }
  }