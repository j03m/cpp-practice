#include <iostream>
#include <stack>
#include <limits>
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

class NodeBounds
{
public:
    const BinaryTreeNode* node_;
    int lowerBound_;
    int upperBound_;

    NodeBounds(const BinaryTreeNode* node = nullptr,
            int lowerBound = numeric_limits<int>::min(),
            int upperBound = numeric_limits<int>::max()) :
        node_(node),
        lowerBound_(lowerBound),
        upperBound_(upperBound)
    {
    }
};


bool WRONGISBST(const BinaryTreeNode * root){
      stack<const BinaryTreeNode *> nodes;
      nodes.push(root);
      while(!nodes.empty()){
        const BinaryTreeNode* node = nodes.top();
        nodes.pop();
        if (node->left_){
            if (node->left_->value_ > node->value_){
                return false;
            }
            else {
                nodes.push(node->left_);
            }
        }

        if (node->right_){
            if (node->right_->value_ < node->value_){
                return false;
            }
            else {
                nodes.push(node->right_);
            }
        }
      }
      return true;
}

bool isBST(const BinaryTreeNode* root){
    // start at the root, with an arbitrarily low lower bound
    // and an arbitrarily high upper bound
    stack<NodeBounds> nodeAndBoundsStack;
    nodeAndBoundsStack.push(NodeBounds(root));
    while(!nodeAndBoundsStack.empty()){
        const NodeBounds nodeBounds = nodeAndBoundsStack.top();
        nodeAndBoundsStack.pop();

        int nodeValue = nodeBounds.node_->value_;
        if (nodeValue <= nodeBounds.lowerBound_ || nodeValue >= nodeBounds.upperBound_){
            false;
        }

        if (nodeBounds.node_->left != nullptr){
            nodeAndBoundsStack.push(NodeBounds(nodeBounds.node_->left_, nodeBounds.lowerBound, nodeValue));
        }

       if (nodeBounds.node_->right_ != nullptr) {
            // this node must be greater than the current node
            nodeAndBoundsStack.push(NodeBounds(nodeBounds.node_->right_,
                nodeValue, nodeBounds.upperBound_));
        }

    }

    return true;
}

int main(){
    //good
    BinaryTreeNode* head = new BinaryTreeNode(50);
    BinaryTreeNode* left = head->insertLeft(17);
    left = left->insertLeft(12);
    BinaryTreeNode* right = left->insertRight(23);
    right->insertLeft(19);
    left->insertLeft(9);
    left->insertRight(14);
    right = head->insertRight(72);
    left = right->insertLeft(54);
    right->insertRight(76);
    left->insertRight(67);

    cout << isBST(head) << "\n";

    //bad
    head = new BinaryTreeNode(50);
    left = head->insertLeft(17);
    left = left->insertLeft(12);
    right = left->insertRight(23);
    right->insertLeft(19);
    left->insertLeft(9);
    left->insertRight(14);
    right = head->insertRight(72);
    left = right->insertLeft(54);
    right->insertRight(7);
    left->insertRight(67);

     cout << isBST(head) << "\n";
}