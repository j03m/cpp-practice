#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

typedef unordered_map<int, vector<int>> Tree;

bool hasChildren(int node, Tree &map){
    return !(map.find(node) == map.end());
}

int findSum(int node, Tree &tree){
    if (!hasChildren(node, tree)){
        return node;
    }
    else {
        int sum = 0;
        auto children = tree[node];
        for( auto child : children){
            sum += findSum(child, tree);
        }
        return sum;
    }
}

int main(){

    Tree tree {
           {5, { 4, 3}},
           {4, { 1, -6}},
           {1, { 2, 9}},
           {3, { 0, 7, -4 }},
           {7, { 8 }}
    };

    cout << findSum(5, tree);

}

