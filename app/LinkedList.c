#include "LinkedList.h"
#include "tlv.h"
#include <stdio.h>
#include <assert.h>

void linkedListInit(LinkedList *list){

  list -> head   = NULL;
  list -> tail   = NULL;
  list -> length = 0;
}

void queueTlv(ListElement *NewEle,LinkedList *List ){

  if(List -> head == NULL && List -> tail == NULL){
    List -> head = NewEle;
    List -> tail = List -> head;
    (List->length)++;
  }
  else if(NewEle==NULL){}

  else {
    List -> tail->next=NewEle;
    List -> tail =List -> tail->next;
    (List->length)++;
  }
}

// void AddFirst(LinkedList *stack,ListElement *NewElem){


  // if(stack->head==NULL && stack->tail==NULL){
    // stack->head=NewElem;
    // stack->tail=stack->head;
    // (stack->length)++;
  // }
  // else if(NewElem==NULL){}


  // else{
    // NewElem->next=stack->head;
    // stack->head=NewElem;
    // (stack->length)++;
  // }
// }

// ListElement *RemoveFirst(LinkedList *stack){
  // ListElement *ptr;

  // if(stack->head==NULL && stack->tail==NULL){
    // return NULL;
  // }
  // else if(stack->head->next==NULL){
    // ptr=stack->head;
    // stack->head=NULL;
    // stack->tail=NULL;
    // (stack->length)--;
  // }
  // else{
    // ptr=stack->head;
    // stack->head=stack->head->next;
    // (stack->length)--;
  // }

  // ptr->next=NULL;
  // return ptr;
// }

// ListElement *RemoveLast(LinkedList *List){
  // ListElement *RemoveEle;
  // ListElement *travel;

  // if(List->head==NULL && List->tail==NULL){
    // return NULL;
  // }
  // else if(List->head->next==NULL){
    // RemoveEle=List->head;
    // List->head=NULL;
    // List->tail=NULL;
    // (List->length)--;
  // }
  // else{
    // travel=List->head;
    // while (travel->next!=NULL){
      // List->tail=travel;
      // travel=travel->next;
    // }
    // RemoveEle=travel;
    // List->tail->next=NULL;

    // (List->length)--;
  // }
  // return RemoveEle;
// }






