#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylist.h"

int result = 1; //global variable

int compareString (const void *x, const void *y){

  result = strcmp((const char *)x, (const char *)y); //if == 0 means found
  return result;

}

int main(int argc, char **argv){

  
 // initialize list
  struct List list;
  initList (&list);
  
 //to skip program name
  int i = 1;
 

  // add arguments to list
  while(i < argc){
      addFront(&list, argv[i]);  
      i++;
  }

  //reverse order
  int r = argc - 1;
  while(r > 0){
     printf("%s \n", argv[r]);
     r--;
  }
  printf ("\n");
  

   //find dude
   findNode (&list, "dude", &compareString);
   
   if(result == 0){
     printf("dude found\n");
     }

   else if(result != 0){ 
      printf("dude not found\n");
   }

   //free all nodes
   removeAllNodes(&list);
 
   return 0;
}
