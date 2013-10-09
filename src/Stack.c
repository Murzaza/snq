#include "Stack.h"
#include "RetCodes.h"
#include <stddef.h>
#include <stdio.h>

int pop(Stack **stk, Node **retN){
  int rc = RET_OK;
  if((*stk)->head != NULL){
    (*retN) = (*stk)->head;
    (*stk)->head = (*stk)->head->next;
  }else{
    rc = RET_FAIL;
  }
  return rc;
}

int push(Stack **stk, Node **n){
  int rc = RET_OK;
  if(n != NULL && (*n) != NULL){
    (*n)->next = (*stk)->head;
    (*stk)->head = *n;
  }else{
    rc = RET_FAIL;
  }
  return rc;
}

int peek(Stack **stk, Node **retN){
  int rc = RET_OK;
  if((*stk)->head != NULL){
    (*retN) = (*stk)->head;
  }else{
    rc = RET_FAIL;
  }
  return rc;
}
