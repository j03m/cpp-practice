#include<vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>

using namespace std;

typedef unordered_map<int, vector<int>> Graph;

//todo revist dfs and bfs without recursion
void dfs(Graph &g, int node, bool *visited, vector<int> &ordering, int &position) {
    visited[node] = true;
    for(auto child : g[node]) {
        if (visited[child] == false) {
            dfs(g, child, visited, ordering, position);
        }
    }
    ordering[--position] = node;
}

void topSort(Graph &g, vector<int> &ordering, int &position){
    int nodes = g.size();
    //use map if ids are not reasonably in range
    bool V[nodes];
    for (auto pair : g){
        dfs(g, pair.first, V, ordering, position);
    }
}


int main(){

    // define a graph we can verify the sort of
    // note this graph is DIRECTED and doesn't have any cycles
    Graph g = {
        { 5, { 2, 0 } },
        { 4, { 0, 1 } },
        { 2, { 3 } },
        { 3, { 1 } },
        { 1, {} },
        { 0, {} }
    };
    vector<int> ordering(g.size());
    int pos = g.size();
    topSort(g, ordering, pos);
    for(auto i : ordering){
        cout << i << "\n";
    }

}