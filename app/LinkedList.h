#ifndef LinkedList_H
#define LinkedList_H
#include "tlv.h"

typedef struct ListElement ListElement;
struct ListElement{
  ListElement *next;
  void        *value;
};

typedef struct {
  ListElement *head;
  ListElement *tail;
  int length;
}LinkedList;

void linkedListInit(LinkedList *list);
ListElement *createListElement(void *value);

//*** Adding Element function start here ***

void enQueueTlv(LinkedList *list,ListElement *NewElem);
ListElement *deQueue(LinkedList *List);


#endif // LinkedList_H
