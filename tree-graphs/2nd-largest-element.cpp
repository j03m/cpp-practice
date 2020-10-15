/**

    50
   / \
  10  100
        \
        150
        /
      120
      / \
    110  130

initially descend as far right as we can go

Then and only then descend left

repeat until leaf, then select parent

**/

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class BinaryTreeNode
{
public:
    int value_;
    BinaryTreeNode* left_;
    BinaryTreeNode* right_;

    BinaryTreeNode(int value) :
        value_(value),
        left_(nullptr),
        right_(nullptr)
    {
    }

    ~BinaryTreeNode()
    {
        delete left_;
        delete right_;
    }

    BinaryTreeNode * insertLeft(int value)
    {
        this->left_ = new BinaryTreeNode(value);
        return this->left_;
    }

    BinaryTreeNode * insertRight(int value)
    {
        this->right_ = new BinaryTreeNode(value);
        return this->right_;
    }
};


BinaryTreeNode* rightMostNode(BinaryTreeNode *root)
{
    BinaryTreeNode *node = root;
    while(node->right_ != nullptr){
        node = node->right_;
    }
    return node;
}

int main(){
    /**
          ( 50 )
        /     \
      (3)     (80)
     /  \     /  \
   (1)  (4) (70)  (120)
                 /
               (100)
               /  \
             (90)  (110)
                  /     \
                 105     115

    **/
    BinaryTreeNode* head = new BinaryTreeNode(5);
    BinaryTreeNode* left = head->insertLeft(3);
    left->insertLeft(1);
    left->insertRight(4);
    BinaryTreeNode* right = head->insertRight(8);
    right->insertLeft(7);
    right = right->insertRight(12);
//    left = right->insertLeft(10);
//    left->insertLeft(9);
//    left->insertLeft(11);

    BinaryTreeNode *node = head;
    BinaryTreeNode *parent = head;
    while(node->right_ != nullptr){
       parent = node;
       node = node->right_;
    }

    //lead right parent
    if (node->right_ == nullptr && node->left_ == nullptr){
        cout << "parent: " << parent->value_;
        return;
    }

    BinaryTreeNode *largest = node;
    while (largest->left_ != nullptr){
        largest = largest->left_;
        while(largest->right_ != nullptr){
            largest = largest->right_;
        }
    }
    cout << "left: " << largest->value_ << "\n";

}

