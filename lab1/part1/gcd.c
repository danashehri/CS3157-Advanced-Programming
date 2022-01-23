#include <stdio.h>
#include "gcd.h"

int gcd(int x, int y){
    int flag=0;
    int min=x;

    if (x>y){
        min=y;
    }

    int i;
    for(i=2; i<=min; ++i){
        if(x%i==0 && y%i==0){
            flag=1; //means not relatively prime
            break;
        }
    }
    if(flag == 1){
        printf("They are not relatively prime\n");
    }
    else {
         printf("They are relatively prime\n");
    }
  return 0;
}

