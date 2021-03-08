#include <vector>
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:


    void printGraph(Node* node){

        visited[node->val] = node;
        cout << node->val << "\n";
        for (Node* neighbor : node->neighbors){
            cout << "\t" << neighbor->val << "\n";
        }


        for (Node* neighbor : node->neighbors){
            if (visited.find(neighbor->val) == visited.end()){
                printGraph(neighbor);
            }
        }
    }

    Node* findOrCache(int index, unordered_map<int, Node*> &map){
        Node * node;
        if (map.find(index) != map.end()){
            node = map[index];
        }
        else {
            node = new Node(index);
            map[index] = node;
        }
        return node;
    }


    void buildGraph(const vector<vector<int>> &input,  unordered_map<int, Node*> &map)
    {
        for (int pos = 0; pos < input.size(); pos++){
            int index = pos+1;
            findOrCache(index, map);
        }

        for (int pos = 0; pos < input.size(); pos++){
            int index = pos+1;
            for (int neighbor : input[pos]){
                Node *neighborNode = map[neighbor];
                map[index]->neighbors.push_back(neighborNode);
            }
        }
    }

    void reset() {
        visited.clear();
    }

    unordered_map<int, Node*> visited;
    Node* cloneGraph(Node* node){
        cout << "c: " << node->val << "\n";
        Node* clone;
        if (visited.find(node->val) == visited.end()){
            clone = new Node(node->val);
            visited[node->val] = clone;
            cout << "Neighbors: " << node->val << "\n";
            for (Node* neighbor : node->neighbors){
                cout << "cn: " << neighbor->val << "\n";
                clone->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        else {
            clone = visited[node->val];
        }
        return clone;
    }
};

int main(){
    Solution s;
    vector<vector<int>> input = {{2,4},{1,3},{2,4},{1,3}};
    unordered_map<int, Node*> map;
    s.buildGraph(input, map);

    cout << "print orig\n";
    s.printGraph(map[1]);
    Node *node = map[1];
    s.reset();

    //implement clone graph
    cout << "clone orig\n";
    Node* clone = s.cloneGraph(node);
    node->val = -1;
    node->neighbors[0]->val = -1;
    cout << "print clone\n";
    s.reset();
    s.printGraph(clone);

}