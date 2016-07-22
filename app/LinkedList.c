#include "LinkedList.h"
#include "tlv.h"
#include <stdio.h>
#include <assert.h>

void linkedListInit(LinkedList *list){

  list -> head   = NULL;
  list -> tail   = NULL;
  list -> length = 0;
}

void enQueueTlv(LinkedList *list,ListElement *NewElem){


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

ListElement *deQueue(LinkedList *List){
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






