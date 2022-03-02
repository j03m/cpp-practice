#include<vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>
using namespace std;

typedef unordered_map<int, vector<int>> Tree;

bool hasChildren(int node, Tree &map){
    return !(map.find(node) == map.end());
}


int findHeight(int node, Tree &tree){
    if (!hasChildren(node, tree)){
        return 0;
    }
    else {
        auto children = tree[node];
        int height = 0;
        for(auto child : children){
            height = max(findHeight(child, tree), height);
        }
        return height+1;
    }
}

int main(){

    Tree tree {
           {5, { 4, 3, 10}},
           {4, { 1, -6}},
           {1, { 2, 9}},
           {3, { 0, 7, -4 }},
           {7, { 8 }},
           {10, {11}},
           {11, {12}},
           {12, {13}}
    };

    cout << findHeight(5, tree);

}
