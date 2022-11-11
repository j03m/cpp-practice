#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

typedef unordered_map<int, vector<int>> Graph;
typedef unordered_set<int> Visited;

//!!!! Need a visited array?!?!?!
void dfs(Graph &g, Visited &visited, int node){
    cout << node << ",";
    for (auto child : g[node]){
        if (visited.find(child) == visited.end()){
            visited.insert(child);
            dfs(g, visited, child);
        }
    }
}

//TODO:
//  Write BFS shorted path unweighted
//  Write djikstra and top sort until you can do it in your sleep (3x?)
//  Return to bridges


void dfs_stack(Graph &g, int node){
    vector<int> stack;
    Visited visited;
    stack.push_back(node);
    while(stack.size() > 0){
        int current = stack.back();
        visited.insert(current);
        stack.pop_back();
        cout << current << ",";
        for(auto child : g[current]){
            if (visited.find(child) == visited.end()){
                stack.push_back(child);
            }
        }
    }
}

int main(){
    Graph g = {
        { 5, { 2, 3, 0, 5} },
        { 4, { 0, 1 } },
        { 2, { 3 } },
        { 3, { 1 } },
        { 1, {} },
        { 0, { 6 } } ,
        { 6, {}}
    };
    Visited visited;
    visited.insert(5);
    dfs(g, visited, 5);
    cout << "\n";
    dfs_stack(g, 5);
}