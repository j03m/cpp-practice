#include<iostream>
#include<stdexcept>
using namespace std;

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


int kthToLastNode(int position, LinkedListNode *node){
    LinkedListNode *walker = node;
    LinkedListNode *trailer = node;
    int count = 0;

    if (!walker->next_){
        throw invalid_argument("node doesn't exist");
    }

    if (position <= 0){
        throw invalid_argument("invalid position");
    }

    while (walker->next_){
        if (count >= position-1){
            trailer = trailer->next_;
        }
        walker = walker->next_;
        count++;
    }

    if (count <= position){
        throw new invalid_argument("list not long enough");
    }

    return trailer->intValue_;
}

int main(){
    LinkedListNode* a = new LinkedListNode(1);
    LinkedListNode* b = new LinkedListNode(2);
    LinkedListNode* c = new LinkedListNode(3);
    LinkedListNode* d = new LinkedListNode(4);
    LinkedListNode* e = new LinkedListNode(5);

    a->next_ = b;
    b->next_ = c;
    c->next_ = d;
    d->next_ = e;

    cout << kthToLastNode(2, a);
    cout << kthToLastNode(1, a);
    cout << kthToLastNode(10, a);

}
