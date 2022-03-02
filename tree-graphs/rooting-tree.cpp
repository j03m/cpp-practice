#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

typedef unordered_map<int, vector<int>> Graph;

class Node {
    public:
        vector<Node> children;
        int id;
};


//
Node graphToNode(Graph &g, int id, Node *parent){
    Node node;
    node.id = id;
    for(auto child : g[id]){
        //don't process back cycles
        if (parent == nullptr || child != parent->id){
            node.children.push_back(graphToNode(g, child, &node));
        }
    }
    return node;
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

int main(){

    // This has to be an UNDIRECTED GRAPH
    Graph g = {
        {1, {2, 3, 4}},
        {2, {1, 5, 6}},
        {3, {1, 7, 8}},
        {4, {1, 9, 10}},
        {5, {2, 11}},
        {10, { 4, 12 }} //
    };

    Node tree = graphToNode(g, 4, nullptr);
    printTree(tree, 0);
}