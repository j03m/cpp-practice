#include<stdexcept>
#include<iostream>
using namespace std;

class LinkedListNode
{
public:
    int intValue_;
    LinkedListNode * next_;

    LinkedListNode(int value) :
        intValue_(value),
        next_(nullptr)
    {
    }
};

void deleteNode(LinkedListNode* input){
    LinkedListNode* nextNode = input->next_;
    if (nextNode) {
        input->intValue_ = nextNode->intValue_;
        input->next_ = nextNode->next_;
        delete nextNode;
        nextNode = NULL;
    }
    else {
        throw invalid_argument("can't ");
    }
}

int main(){
    LinkedListNode* a = new LinkedListNode(1);
    LinkedListNode* b = new LinkedListNode(2);
    LinkedListNode* c = new LinkedListNode(3);

    a->next_ = b;
    b->next_ = c;

    deleteNode(b);

    cout << c->intValue_ << "\n";
}