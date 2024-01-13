// #include <iostream.h>
#include "intDLList.h"
#include <iostream>

IntDLList::~IntDLList()
{
  for (IntDLLNode *p; !isEmpty();)
  {
    p = head->next;
    delete head;
    head = p;
  }
}
// add to the head
void IntDLList::addToHead(int el)
{
  head->prev = new IntDLLNode(el, head);
  head = head->prev;
  if (tail == 0)
    tail = head;
}
// add to the tail
void IntDLList::addToTail(int el)
{
  if (tail != 0)
  { // if list not empty;
    tail->next = new IntDLLNode(el, 0, tail);
    tail = tail->next;
  }
  else
    head = tail = new IntDLLNode(el);
}
// delete from the head
int IntDLList::deleteFromHead()
{
  int el = head->info;
  IntDLLNode *newHead = head->next;
  newHead->prev = 0;
  IntDLLNode *tmp = head;
  // if only one node in the list;
  if (head == tail)
    head = tail = 0;
  else
    head = newHead;
  delete tmp;
  return el;
}
int IntDLList::deleteFromTail()
{
  int el = tail->info;
  if (head == tail)
  { // if only one node in the list;
    delete head;
    head = tail = 0;
  }
  // if more than one node in the list,
  else
  {
    IntDLLNode *lastNode = tail;
    tail = tail->prev;
    tail->next = 0;
    delete lastNode;
  }
  return el;
}
void IntDLList::deleteNode(int el)
{
  if (head != 0) // if nonempty list;
  {
    // if only one node in the list;
    if (head == tail && el == head->info)
      delete head;
    head = tail = 0;
  }
  // if more than one node in the list
  else if (el == head->info)
  {
    IntDLLNode *tmp = head;
    head = head->next;
    delete tmp; // and old head is deleted;
  }
  else
  { // if more than one node in the list
    IntDLLNode *tmp = head->next;
    while (tmp->info != el)
    {
      tmp = tmp->next;
    }
    if (tmp != 0)
    {
      tmp->prev = tmp->next;
      delete tmp;
    }
  }
}

bool IntDLList::isInList(int el) const
{
  IntDLLNode *tmp;
  for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next)
    ;
  return tmp != 0;
}
