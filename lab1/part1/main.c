#include <stdio.h>

#include "gcd.h"
#include "prime.h"

int main( ) {
   int num1;
   int num2;

   printf( "Enter first number:");
   scanf("%d", &num1);
    printf( "Enter second number:");
   scanf("%d", &num2);

   printf("You typed in %d and %d\n", num1, num2);

   //average
    float avg=(num1+num2)/2;
    printf("The average is: %f\n", avg);

    //prime or not
    prime(num1);
    prime(num2);

    //relatively prime or not
    gcd(num1, num2);
   return 0;

}


