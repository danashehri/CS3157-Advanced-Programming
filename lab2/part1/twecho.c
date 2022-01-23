/*
 * twecho
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static char **duplicateArgs(int argc, char **argv)
{
	int i;
	char c, up;
	char **q = malloc((argc+1)*sizeof(char *)); //vertical array
	
 	 for(i = 0; i < argc; ++i){
		size_t len = strlen(argv[i])+1;
		q[i] = malloc(len); //allocate memory for string char
		
		while((*q = *argv) != 0){ //copy
		q++;
		argv++;
		}
               
	 while(q[i]){
		 c = *q[i];
		 up = toupper(c);
		 *q[i] = up;
		 q++;
		 i++;

  	 }
	//q[argc] = NULL; 
	 }
	 q[argc] = NULL;
	//recall: q[argc] = NULL; //null pointer
	return q;

}

static void freeDuplicatedArgs(char **copy)
{
	int i;
	for(i = 0; i < strlen(copy[i]+1); ++i)
    {
        free(copy[i]);
    }

    free(copy);

}

/*
 * DO NOT MODIFY main().
 */
int main(int argc, char **argv)
{
    if (argc <= 1)
        return 1;

    char **copy = duplicateArgs(argc, argv);
    char **p = copy;

    argv++;
    p++;
    while (*argv) {
        printf("%s %s\n", *argv++, *p++);
    }

    freeDuplicatedArgs(copy);

    return 0;
}
