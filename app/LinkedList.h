#ifndef LinkedList_H
#define LinkedList_H

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

void addFirst(LinkedList *list,ListElement *NewElem);
ListElement *removeLast(LinkedList *List);




#endif // LinkedList_H
