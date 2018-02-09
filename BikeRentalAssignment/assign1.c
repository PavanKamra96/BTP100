/*
  Name: Pavan Kamra
  Course: BTP100
  Policy: I declare that the assignment is wholly my own work in accordance with Seneca Academic Policy. No part of this
  assignment has been copied manually or electronically from any other source (including web sites) or distributed to
  other students.
*/

#include < stdio.h >

int monthday(int m, int y);
int leapyear(int year);

main() {
  
  // general input required to start the program. Inputting time it was rented & returned.
  int month, day, year, minute, hour;
  int monthr, dayr, yearR, minuter, hourR;
  int sum = 0, sum1;
  printf("Big Bike Company Bike Rental System\n");
  printf("==================================\n");
  printf("Enter the date the bike was rented out [mm/dd/yyyy] - ");
  scanf("%d/%d/%d", & month, & day, & year);
  printf("Enter the time the bike was rented out [hh:mm] - ");
  scanf("%d:%d", & hour, & minute);
  printf("\nEnter the date the bike was returned [mm/dd/yyyy] - ");
  scanf("%d/%d/%d", & monthr, & dayr, & yearR);
  printf("Enter the time the bike was returned [hh:mm] - ");
  scanf("%d:%d", & hourR, & minuter);
  int i;

  int finalMin = 0, finalHour = 0, finalDay = 0; // variables used to calculate the difference between both times.

  // a loop to find the difference in minutes between rented & returned.
  if (minute <= minuter)
    finalMin = minuter - minute;
  else
    finalMin = (60 - minute) + minuter;

  // a loop to find the difference in hours between rented & returned.
  if (hour < hourR)
    finalHour = hourR - hour;
  else
    finalHour = (24 - hour) + hourR;

  finalDay = monthday(month, year);

  // a loop to find the difference in days between rented & returned.
  if (dayr - day > 1)
    finalHour = finalHour + (((dayr - day) - 1) * 24);

  sum1 = leapyear(year);
  if (month == 2 && day > dayr) {
    if (sum1 == 1) {
      finalHour = finalHour + 24;
    }
  }
  printf("\nHour: %d, Minute: %d\n", finalHour, finalMin);

  float cost = 0;
  if (finalHour <= 5) {
    cost = 5;
  } else if (finalHour <= 24 && finalHour > 5) {
    cost = 12;
  } else if (finalMin < 1) {
    cost = (finalHour - 24) * 0.5 + 12;
  } else {
    cost = (finalHour + 1 - 24) * 0.5 + 12;
  }
  printf("Cost of Rental: $ %.2f\n", cost);
}

// function to determine if the year is a leap year or not.
int leapyear(int year) {
  if ((year % 4 == 0) && (year % 100 != 0))
    return 1;
  else if ((year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0))
    return 1;
  else if ((year % 4 == 0) && (year % 100 == 0) && (year % 400 != 0))
    return 0;
  else
    return 0;
}

// this method uses cases to represents the days of the months. 
int monthday(int m, int y) {
  switch (m) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    return 31;
  case 2:
    return 28 + leapyear(y);
  case 4:
  case 6:
  case 9:
  case 11:
    return 30;

  default:
    return -1;
  }

}
