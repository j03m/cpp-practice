#include<vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

typedef unordered_map<int, vector<int>> Graph;

class Node {
    public:
        vector<Node> children;
        int id;
};

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