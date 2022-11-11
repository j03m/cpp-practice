#include "common.h"

void printChildren(std::string prefix, vector<int> input){
    cout << prefix;
    for(int i : input){
        cout << i << ",";
    }
    cout << "\n";
}

void printTree(Node &root, int indent){
    for (int i =0; i<indent; i++){
        cout << " ";
    }
    cout << root.id << "\n";
    indent++;
    for (auto node : root.children){
        printTree(node, indent);
    }
    indent--;
}