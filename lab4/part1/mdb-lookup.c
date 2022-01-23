#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mylist.h"
#include "mdb.h"

int main(int argc, char **argv){

	char *file = argv[1];
	FILE *fp;
	fp = fopen(file, "rb");
	if(fp == NULL){
	perror(file);
	exit(1);
	}


	struct List mdb;
	initList(&mdb);

	struct Node *prev = NULL;
	char buffer[40];
	
	
	while(fread(buffer, sizeof(struct MdbRec), 1, fp)){
	struct MdbRec *record=(struct MdbRec *)malloc(sizeof(struct MdbRec));
	if(record == NULL){
	perror("malloc failed");
	exit(1);
	}
	memcpy(record, &buffer, sizeof(struct MdbRec));
	prev = addAfter(&mdb, prev, (struct MdbRec *)record);
	 if (prev == NULL){
        perror("addAfter() failed");    
	}
	}

	//lookup string from input
		
	char c[1000]; //input array characters
	printf("lookup: ");
	char look[6];
	char *name = NULL;
	char *msg = NULL;
	while(fgets(c, sizeof(c), stdin)!=NULL){
		look[5]='\0';
		strncpy(look, c, 5);		
		size_t len = strlen(look)-1;
		if(look[len] == '\n'){
		   look[len] = '\0';
		}
		int num = 0;	

                

		struct Node *n = mdb.head;
		while(n!=NULL){
		num++;
		struct MdbRec *r = (struct MdbRec *)n->data;
		name = strstr(r->name, look);
		msg = strstr(r->msg, look);
			if(name || msg){
			printf("%2d: {%s} said {%s} \n", num, r->name, r->msg);
		  	}
		n=n->next;
		}

		printf("\nlookup: ");
		fflush(stdout);
	}

	struct Node *node = mdb.head;
	while(node!=NULL){
		free(node->data);
		node=node->next;
	}
	removeAllNodes(&mdb);
	fclose(fp);
	return 0;
}
