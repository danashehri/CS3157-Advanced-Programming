#include <stdio.h>
#include "convert.h"

int convert(int x){

int i, y;
	printf("binary:         ");
    for(i=31; i>=0; --i){ //loop starts from 32th bit to print left to right
         if((i==27)|(i==23)|(i==19)|(i==15)|(i==11)|(i==7)|(i==3)){
            printf(" "); //space alignment to match desired binary output
        }
      	 y=(x>>i)&1; //shifts R by i, then gets the value of the ith bit with AND operator

        if(y==1){
            printf("1");
	} 
        else{
            printf("0");
        }
          
    }
    printf("\n");//to go to new line

	return 0;
}
