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

//*** Adding Element function start here ***

void addLast(ListElement *NewEle,LinkedList *List );
void addFirst(LinkedList *list,ListElement *NewElem);
ListElement *removeLast(LinkedList *List);
ListElement *removeFirst(LinkedList *stack);





#endif // LinkedList_H
