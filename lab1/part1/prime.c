#include <stdio.h>
#include "prime.h"

int prime(int x){
    int i;
    int flag = 0;
      for (i = 2; i <= x/2; ++i) {
        // condition when number is even for non-prime
        if (x % i == 0) {
            flag = 1; // even
            break;
        }
    }

    if(x == 2){
        flag = 0;
                 }

        if (flag == 0) {
            if (x == 1){
        printf("The number %d is not a prime number\n", x);
        }
            else {
        printf("The number %d is a prime number\n", x);
        }
    }
        else {
        printf("The number %d is not a prime number\n", x);
    }
 return 0;
}
