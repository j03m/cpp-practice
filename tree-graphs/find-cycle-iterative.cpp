#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool findCycle(unordered_map<int, vector<int>> &graph, int numCourses){

    vector<bool> visited(numCourses);
    vector<bool> onStack(numCourses);
    stack<int> stck;

    for(auto node : graph){
        int v = node.first;
        if (visited[v] == true) {
            continue;
        }

        stck.push(v);
        while(!stck.empty()){
            int top = stck.top();
            if (!visited[top]){
                visited[top] = true;
                onStack[top] = true;
            }
            else {
                onStack[top] = false;
                stck.pop();
            }
            auto children = graph[top];
            for(int child : children){
                if (!visited[child]){
                    stck.push(child);
                }
                else if (onStack[child]){
                    return true;
                }
            }

        }
    }
    return false;

}


bool canFinish(int numCourses, vector<vector<int>>& prerequisites, vector<int> &visited){
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

    return !findCycle(graph, numCourses);
}

int main(){

}