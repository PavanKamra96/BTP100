/** 
    Name: Pavan Kumar Kamra
    Date: 9/17/2014
    Course: BTP100 
    I declare that this is wholly my own work in accordance with Seneca Academic Policy. No part of this work has been copied manually or 
    electronically from any other source (including web sites) or distributed to other students. 
**/

#include < stdio.h >
  main() {
    // variable declaration 
    float x1, x2, x3, y1, y2, y3;

    printf("Enter coordinate x1 for point 1: ");
    scanf("%f", & x1);
    printf("Enter coordinate y1 for point 1: ");
    scanf("%f", & y1);
    printf("Enter coordinate x2 for point 2: ");
    scanf("%f", & x2);

    if (x2 == x1) {
      printf("x2 and x1 are not parallel, please enter a different x2 value ");
      scanf("%f", & x2);
    } else {
      printf("Enter coordinate y2 for point 2: ");
      scanf("%f", & y2);
    }

    if (y2 == y1) {
      printf("y2 and y1 are not parallel, please enter a different y2 value ");
      scanf("%f", & y2);
    } else {
      printf("Enter coordinate x3 for point 3: ");
      scanf("%f", & x3);
    }

    /* finding the slope */
    float slope;
    slope = (y2 - y1) / (x2 - x1);

    /* finding the slope equation */
    float b;
    b = (y2 - (slope * x2));

    /* finding the coordinates of the third point. */
    y3 = (slope * x3) + (b);
    printf("Point 3 is: (%.2f, %.2f)\n", x3, y3);

  }