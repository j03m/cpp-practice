#include<iostream>
#include<stdexcept>
using namespace std;
class LinkedListNode
{
public:
    int value_;
    LinkedListNode* next_;

    LinkedListNode(int value) :
        value_(value),
        next_(nullptr)
    {
    }
};


bool containsCycle(LinkedListNode* input){
    LinkedListNode* fast = input;
    LinkedListNode* slow = input;
    while (fast != nullptr && fast->next_){
        fast = fast->next_->next_;
        slow = slow->next_;
        if (fast == slow){
            return true;
        }
    }

    return false;
}

LinkedListNode* findFirstNodeInCycle(LinkedListNode* input){
    LinkedListNode* fast = input;
    LinkedListNode* slow = input;

    while (fast != nullptr && fast->next_){
        fast = fast->next_->next_;
        slow = slow->next_;
        if (fast == slow){
            break;
        }
    }

    if (fast != slow){
        return nullptr;
    }

    slow = input;
    while(fast != slow){
        fast = fast->next_;
        slow = slow->next_;
    }
    return fast;
}


int main(){

    //cycle
    LinkedListNode* a = new LinkedListNode(1);
    LinkedListNode* b = new LinkedListNode(2);
    LinkedListNode* c = new LinkedListNode(3);
    LinkedListNode* d = new LinkedListNode(4);
    LinkedListNode* e = new LinkedListNode(5);
    LinkedListNode* f = new LinkedListNode(6);

//    a->next_ = b;
//    b->next_ = c;
//    c->next_ = a;
//
//    cout << containsCycle(a) << "\n";
//
//    //no cycle
//    a->next_ = b;
//    b->next_ = c;
//    c->next_ = nullptr;
//
//    cout << containsCycle(a) << "\n";
//
//    a->next_ = b;
//    b->next_ = a;
//
//    cout << containsCycle(a) << "\n";

    a->next_ = b;
    b->next_ = c;
    c->next_ = d;
    d->next_ = e;
    e->next_ = c;

    cout << (findFirstNodeInCycle(a) == c) << "\n";

}

