#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *foo(int x){
    int *p = malloc(x*sizeof(int));
    return p;
}

int intcpy(int *x, int *y){
    while((*x = *y)!=0){
        x++;
        y++;
    }
    return 0;
}

void sort_integer_array(int *begin, int *end, int ascending){
       
        int size = (end - begin);
       
     // end points to one past last element so end - 1 points to last element
     
      if(ascending == 1){
            int s1, s2, temp;
         for (s1 = 0; s1 < size; ++s1){
            for(s2 = s1 + 1; s2 < size; ++s2){
                if(begin[s1]>begin[s2]){
                
                temp = begin[s1];
                begin[s1] = begin[s2];
                begin[s2] = temp;
                }
            }
         }
       }
         
        else if(ascending == 0){
            int s1, s2, temp;
        for (s1 = 0; s1 < size; ++s1){
        for(s2 = s1 + 1; s2 < size; ++s2){
            
             if(begin[s1]<begin[s2]){
                
                temp = begin[s1];
                begin[s1] = begin[s2];
                begin[s2] = temp;
              }
            }
          }
        }
         
    }

int main(){
    srandom(time(NULL));
    int size;
    printf("enter size of array: ");
    scanf("%d", &size);
    int array1[size];
    int i;
    
    for(i = 0; i < size; ++i){
        array1[i]=random()%100; // numbers in range 0 - 99
    }

    
    //pointer for array 1
    int *ptr_1 = foo(size); 
    
    //dynamic memory allocation of array 1
    for(i = 0; i < size; ++i){
        ptr_1[i] = array1[i];
    }
    
    //check if malloc was successful
    if (ptr_1 == NULL) {
        perror("malloc returned NULL");
    }
   /* else { 
        printf("\npointer 1 points to: %p \n", ptr_1); }
    */
    
    //array 2 in the making
    int array2[size]; //empty array 
    
    intcpy(array2, array1); //copy array1 to array2
   
    
    sort_integer_array(array2, &array2[size], 1);

   
    //set pointer 2 for array 2
    
    int *ptr_2 = foo(size); //pointer to array 2 location
    
    //dynamic memory allocation of array 2
    for(i = 0; i < size; ++i){
        ptr_2[i] = array2[i];
    }
    
    //check if malloc was successful
     if (ptr_2 == NULL) {
        perror("malloc returned NULL");
    }
    /* else { 
        printf("\npointer 2 points to: %p \n", ptr_2); }
   */
   
     int array3[size]; //empty array 
    
    intcpy(array3, array1); //copy array1 to array2
    
    
    sort_integer_array(array3,&array3[size], 0);
   
    
    int *ptr_3 = foo(size); //pointer to array 3 location
    
    //dynamic memory allocation of array 3
    for(i = 0; i < size; ++i){
        ptr_3[i] = array3[i];
    }
    
     if (ptr_3 == NULL) {
        perror("malloc returned NULL");
    } 
     /*else { 
        printf("\npointer 3 points to: %p \n", ptr_3); }
   */

    //original
    printf("original: ");
    for(i = 0; i < size; ++i){
        printf("%d ", ptr_1[i]);
    }
    
    //ascending
    printf("\nascending: ");
    for(i = 0; i < size; ++i){
        printf("%d ", ptr_2[i]);
    }
    
    //descending
    printf("\ndescending: ");
    for(i = 0; i < size; ++i){
        printf("%d ", ptr_3[i]);
    }
    printf("\n");
    
    free(ptr_1);
    free(ptr_2);
    free(ptr_3);
    
    
    
    return 0;
}

