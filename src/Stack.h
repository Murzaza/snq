#ifndef __STACK__
#define __STACK__
#include "Node.h"

typedef struct Stack{
  Node *head;
} Stack;

int pop(Stack **stk, Node **retN);
int push(Stack **stk, Node **n);
int peek(Stack **stk, Node **retN);
#endif
