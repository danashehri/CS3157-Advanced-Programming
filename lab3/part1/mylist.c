#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mylist.h"

struct Node *addFront (struct List *list, void *data)
{


  struct Node *n = malloc (sizeof (struct Node));

  n->data = data;
  n->next = list->head;
  list->head = n;


  return n;
}

void traverseList (struct List *list, void (*f) (void *))
{

  // list pointer to a list structure
  // void star pointer to a ptr function printdouble

  struct Node *temp;
  

  temp = list->head;
  while (temp != NULL)
    {
      f (temp->data);
      temp = temp->next;	// Move to next node
    }
}

void flipSignDouble (void *data)
{

  double num = *(double *) (data);	//pointer type double
  double flip = -1 * num;
  *(double *) data = flip;

}

struct Node *findNode (struct List *list, const void *dataSought,
	  int (*compar) (const void *, const void *))
{

  struct Node *temp;
  temp = list->head;
  int result;
  int i = 0;
  while (temp != NULL)
    {

      result = compar (temp->data, dataSought);
      if (result == 0)
	{
	  break;
	}
      i++;
      temp = temp->next;	// Move to next node


    }

  return temp;
}

int compareDouble (const void *data1, const void *data2)
{

  double x = *(double *) (data1);
  double y = *(double *) (data2);

  if (x == y)
    {
      return 0;
    }
  else
    {
      return -1;
    }
}

void *popFront(struct List *list){

    if(list->head == NULL){
        return NULL;
    }

    void *data;

    struct Node *temp = NULL;
    temp = list->head;//pointer to head node
    data = list->head->data;
    list->head = temp->next; //next node is new head

    free(temp);
    return data;
}

struct Node *addAfter(struct List *list,
        struct Node *prevNode, void *data){


        if(prevNode == NULL){
            return addFront(list, data);
        }
        struct Node *new = malloc (sizeof (struct Node));

        if(new == NULL){
            perror("malloc returned null");
            exit(1);
        }
        new->data = data;
        new->next = prevNode->next;
        prevNode->next = new;

        return new;
        }

void reverseList(struct List *list){
    struct Node *prv = NULL; //prev node
    struct Node *cur = list->head; //current node
    struct Node *nxt; //next node

    while(cur){
        nxt = cur->next;
        cur->next = prv;
        prv = cur;
        cur = nxt;

        if(nxt == NULL){
            list->head = prv;
            break;
        }
    }
}

void removeAllNodes(struct List *list){
    
    while(list->head != NULL){
        popFront(list);
    }
    
}
