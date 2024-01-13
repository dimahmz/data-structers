#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST
// a node in a singly list
class IntDLLNode
{
public:
  IntDLLNode()
  {
    next = prev = 0;
  }
  IntDLLNode(int el, IntDLLNode *next = 0, IntDLLNode *prev = 0)
  {
    info = el;
    next = next;
    prev = prev;
  }
  int info;
  IntDLLNode *next;
  IntDLLNode *prev;
};
// the singly list
class IntDLList
{
public:
  IntDLList()
  {
    head = tail = 0;
  }
  ~IntDLList();

  int isEmpty()
  {
    return head == 0;
  }
  // methods
  void addToHead(int);
  void addToTail(int);
  int deleteFromHead(); // delete the head and return its info;
  int deleteFromTail(); // delete the tail and return its info;
  void deleteNode(int);
  bool isInList(int) const;
  void insertElements(int); // insert n element to the linked list
  void dispalyElements();
  void ListInfo();

private:
  IntDLLNode *head, *tail;
};
#endif