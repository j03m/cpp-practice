#include<iostream>
#include<stdexcept>
using namespace::std;

class LinkedListNode
{
public:
    int intValue_;
    LinkedListNode* next_;

    LinkedListNode(int intValue) :
        intValue_(intValue),
        next_(nullptr)
    {
    }
};


/**

  a->b

  b->c

  c->null

  cr = a
  pr = null
  nx = null

  while cr

  nx = b
  a-> pr = null

  pr = a
  cr = nx = b

  nx = c
  b->pr = a
  pr = b
  cr = nx = c

  nx = null
  c-pr = b
  pr = c
  cr = nx = null


  return pr
**/

LinkedListNode * reverseList(LinkedListNode* headOfList)
{
    LinkedListNode* currentNode = headOfList;
    LinkedListNode* previousNode = nullptr;
    LinkedListNode* nextNode = nullptr;

    // until we have 'fallen off' the end of the list
    while (currentNode) {

        // copy a pointer to the next element
        // before we overwrite currentNode.next
        nextNode = currentNode->next_;

        // reverse the 'next' pointer
        currentNode->next_ = previousNode;

        // step forward in the list
        previousNode = currentNode;
        currentNode = nextNode;
    }

    return previousNode;
}

int main(){
    LinkedListNode* a = new LinkedListNode(1);
    LinkedListNode* b = new LinkedListNode(2);
    LinkedListNode* c = new LinkedListNode(3);

    a->next_ = b;
    b->next_ = c;

    LinkedListNode* d = reverseList(a);
    cout << (d->intValue_) << "\n";
}