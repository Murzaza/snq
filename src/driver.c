#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Stack.h"
#include "RetCodes.h"

//Create an array of nodes to populate the stack/queue
void nodeFactory(Node **n, int size){
  *n = (Node *) calloc(size, sizeof(Node));
  int i;
  for(i = 0; i < size; ++i){
    (*n)[i].data = rand()%size;
    (*n)[i].next = NULL;
  }
}

//Fill the stack with a node array.
int fillStack(Stack **stk, Node **n, int size){
  int i;
  for(i = 0; i < size; ++i){
    Node *toN = &(*n)[i];       //This looks nasty but I love it!
    if(push(stk, &toN) != 0){
      return RET_FAIL;
    }
  }
  return RET_OK;
}

//Emptying the stack and printing out the contents
int emptyStack(Stack **stk){
  int rc = RET_OK;
  while((*stk)->head != NULL && rc == RET_OK){
    Node *n = NULL;
    rc = pop(stk, &n);
    printf("From the stack we got %d\n", n->data);
  }
  return rc;
}

//Function for freeing the allocated data.
void freeData(Stack **stk, Node **n){
  free(*stk);
  free(*n);
}

int main(void){
  Stack *stk = NULL;
  srand(time(NULL));
  Node *n;
  int rc = RET_OK;
  stk = (Stack *) malloc(sizeof(Stack));
  stk->head = NULL;
  nodeFactory(&n, 10);
  printf("Nodes built\n");
  rc = fillStack(&stk, &n, 10);
  printf("fillStack returned: %d\n", rc);
  rc = emptyStack(&stk);
  printf("emptyStack returned: %d\n", rc);
  freeData(&stk, &n);
  return 0;
}
