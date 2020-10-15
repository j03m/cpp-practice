#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <stack>
#include <utility>
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

    BinaryTreeNode* insertLeft(int value)
    {
        this->left_ = new BinaryTreeNode(value);
        return this->left_;
    }

    bool hasChildren()
    {
        return this->right_ != nullptr || this->left_ != nullptr;
    }

    BinaryTreeNode* insertRight(int value)
    {
        this->right_ = new BinaryTreeNode(value);
        return this->right_;
    }
};


bool isBalanced(const BinaryTreeNode* treeRoot)
{

    // a tree with no nodes is super balanced, since there are no leaves!
    if (treeRoot == nullptr) {
        return true;
    }

    // will have up to 3 elements
    size_t depths[3];
    size_t depthCount = 0;

    // nodes will store pairs of a node and the node's depth
    stack<pair<const BinaryTreeNode*, size_t>> nodes;
    nodes.push(make_pair(treeRoot, 0));

    while (!nodes.empty()) {

        // get a node and its depth from the top of stack and pop it
        const BinaryTreeNode* node = nodes.top().first;
        size_t depth = nodes.top().second;
        nodes.pop();

        // case: we found a leaf
        if (!node->left_ && !node->right_) {
            cout << "Dc: " << depthCount << "\n";
            cout << "wtf: " << find(depths, depths + depthCount, depth) << " " << depths + depthCount << "\n";
            // we only care if it's a new depth
            if (depthCount == 0 ||
                find(depths, depths + depthCount, depth) == depths + depthCount) {
                depths[depthCount] = depth;
                ++depthCount;

                // two ways we might now have an unbalanced tree:
                //   1) more than 2 different leaf depths
                //   2) 2 leaf depths that are more than 1 apart
                if (depthCount > 2 ||
                        (depthCount == 2 &&
                        max(depths[0], depths[1]) - min(depths[0], depths[1]) > 1)) {
                    return false;
                }
            }
        }

        // case: this isn't a leaf - keep stepping down
        else {
            if (node->left_) {
                nodes.push(make_pair(node->left_, depth + 1));
            }
            if (node->right_) {
                nodes.push(make_pair(node->right_, depth + 1));
            }
        }
    }

    return true;
}

bool superBalanced(const BinaryTreeNode* head){
    size_t minLevel = -1;
    size_t maxLevel = 0;
    stack<pair<const BinaryTreeNode*, size_t>> treeStack;
    if(head == nullptr){
        throw invalid_argument("no tree!");
    }
    treeStack.push(make_pair(head, 0));
    while(!treeStack.empty()){
         // get a node and its depth from the top of stack and pop it
        const BinaryTreeNode* node = treeStack.top().first;
        size_t levelDepth = treeStack.top().second;
        treeStack.pop();
        cout << "sanity: " << node->value_ << "\n";
        bool hasChildren = false;
        if (node->left_ != nullptr){
            treeStack.push(make_pair(node->left_ , levelDepth+1));
            hasChildren = true;
        }
        if (node->right_ != nullptr){
            treeStack.push(make_pair(node->right_ , levelDepth+1));
            hasChildren = true;
        }


        if (!hasChildren){
            if (minLevel == -1){
                minLevel = levelDepth;
            }
            else {
                minLevel = std::min(minLevel, levelDepth);
            }
            maxLevel = std::max(maxLevel, levelDepth);
            if ((maxLevel - minLevel) > 1){
                cout << "DONE: max:" << maxLevel << " min:" << minLevel << "\n";
                return false;
            }
            else {
                cout << "OKAY: max:" << maxLevel << " min:" << minLevel << "\n";
            }
        }
    }

    return true;
}



int main(){

    BinaryTreeNode* head = new BinaryTreeNode(0);
    BinaryTreeNode* node = head->insertLeft(1);
    node = node->insertLeft(2);
    node = node->insertLeft(3);
    node = head->insertRight(4);
    node = node->insertRight(5);
    //[
    cout << isBalanced(head) << "\n";
    cout << superBalanced(head) << "\n";
}
