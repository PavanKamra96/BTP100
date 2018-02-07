/**
Name: Pavan Kamra
Date: 11/29/2014
Course: BTP100
**/
#include < stdio.h > #define MAX 100
float Value(float p, int q); // this function is suppose to multiple price b quantity to get value of product. 
float totalValue(float a[], int element); // this gets the total value of money of all the purchases
void array(long long a[], int i); // this creates and validates the array so its not more/less then 10 digits 

int main() {
  // variable declaration
  int i, j, counter = 0;
  float totalVal1;
  long long item_ISBN[MAX];
  float item_Price[MAX];
  int item_Quantity[MAX];
  float item_Value[MAX];
  printf("BookStory Inventory\n======================\n");
  // takes all the input
  for (i = 0; i < MAX; i++) {
    array(item_ISBN, i);
    if (item_ISBN[i] == 0) {
      break;
    } else {
      printf("Price: ");
      scanf("%f", & item_Price[i]);
      printf("Quantity: ");
      scanf("%d", & item_Quantity[i]);
      item_Value[i] = Value(item_Price[i], item_Quantity[i]);
      counter = counter + 1;
    }
  }
  totalVal1 = totalValue(item_Value, counter);

  int k;
  for (k = 0; k < counter; k++) {
    totalVal1 = totalValue(item_Value, counter);
  }
  // prints all the data out. 
  printf("                   Books in Stock\n                 ==================\n");
  printf("       ISBN     Price     Quantity    Value\n");
  printf("       ---------------------------------------\n");

  for (j = 0; j < counter; j++) {
    printf("       %010lld   %.2f         %d       %.2f\n", item_ISBN[j], item_Price[j], item_Quantity[j], item_Value[j]);
  }
  printf("                                        -------\n");
  printf("       Total value goods in stock        %.2f\n", totalVal1);
  return 0;
}

// multiples the price by quantity.
// p is the price of the item. q is the quantity of the item that is being bought. 
float Value(float p, int q) {
  float val;
  val = p * q;
  return (val);
}

//finds total price of all purchases
// a[] takes in the Value array with all the purchases and adds them. element is the SIZE. 
float totalValue(float a[], int element) {
  int i;
  float sumL = 0;
  for (i = 0; i < element; i++) {
    sumL = sumL + a[i];
  }
  return (sumL);
}

// creates and validates array
//a[] is the array being created. i is the SIZE. 
void array(long long a[], int i) {
  int valid = 0;
  while (valid == 0) {
    printf("ISBN: ");
    scanf("%lld", & a[i]);
    if ((a[i] > 999999999 || a[i] < 100000000) && a[i] != 0)
      printf("The Barcode needs to be 10 digits\n");
    else
      valid = 1;
  }
}