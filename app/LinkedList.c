#include "LinkedList.h"
#include <stdio.h>
#include <assert.h>

void linkedListInit(LinkedList *list){

  list -> head   = NULL;
  list -> tail   = NULL;
  list -> length = 0;
}

void addLast(ListElement *NewEle,LinkedList *List ){

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

void addFirst(LinkedList *list,ListElement *NewElem){

  if(list->head==NULL && list->tail==NULL){
    list->head=NewElem;
    list->tail=list->head;
    (list->length)++;
  }
  else if(NewElem==NULL){}


  else{
    NewElem->next=list->head;
    list->head=NewElem;
    (list->length)++;
  }
}

ListElement *removeLast(LinkedList *List){
  ListElement *deQEle;
  ListElement *travel;

  if(List->head==NULL && List->tail==NULL){
    return NULL;
  }
  else if(List->head->next==NULL){
    deQEle=List->head;
    List->head=NULL;
    List->tail=NULL;
    (List->length)--;
  }
  else{
    travel=List->head;
    while (travel->next!=NULL){
      List->tail=travel;
      travel=travel->next;
    }
    deQEle=travel;
    List->tail->next=NULL;

    (List->length)--;
  }
  return deQEle;
}

ListElement *removeFirst(LinkedList *stack){
  ListElement *ptr;

  if(stack->head==NULL && stack->tail==NULL){
    return NULL;
  }
  else if(stack->head->next==NULL){
    ptr=stack->head;
    stack->head=NULL;
    stack->tail=NULL;
    (stack->length)--;
  }
  else{
    ptr=stack->head;
    stack->head=stack->head->next;
    (stack->length)--;
  }

  ptr->next=NULL;
  return ptr;
}




