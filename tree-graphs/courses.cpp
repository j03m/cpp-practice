#include<vector>
#include<unordered_map>
#include<stack>
#include<iostream>

using namespace std;

bool findCycle(int head, unordered_map<int, vector<int>> &graph, vector<bool> &black, vector<bool> &gray){
    if (black[head]){ return false; }
    if (gray[head]){ return true; }
    gray[head] = true;
    const auto children = graph[head];
    bool ret = false;
    for (int child : children){
        ret = findCycle(child, graph, black, gray);
        if (ret){
            break;
        }
    }
    gray[head] = false;
    black[head] = true;
    return ret;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
    //build adjacency list o(n)
    unordered_map<int, vector<int>> graph;
    for(auto prereq : prerequisites){
        int course = prereq[1];

        int required = prereq[0];

        if (graph.find(course) == graph.end()) { //add it
            vector<int> foo;
            graph[course] = foo;
        }
        graph[course].push_back(required);
    }


    //dfs each node in our graph checking for cycles
    vector<bool> black(numCourses);
    vector<bool> gray(numCourses);
    for (auto node : graph){
        if (findCycle(node.first, graph, black, gray)){
            return false;
        }
    }
    return true;
}


int main(){

    vector<vector<int>> prereq1 = {
        {1,0}
    };

    vector<vector<int>> prereq2 = {
        {1,0},
        {0,1}
    };
    
    vector<vector<int>> prereq3 = {{0,1},{0,2},{1,2}};

    cout << canFinish(prereq1.size(), prereq1) << "\n";
//
    cout << canFinish(prereq2.size(), prereq2) << "\n";

    cout << canFinish(prereq3.size(), prereq3) << "\n";

}