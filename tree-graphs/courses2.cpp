#include<unordered_set>
#include<vector>
#include<unordered_map>
#include<iostream>

using namespace std;

class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

            visited = new vector<bool>(numCourses, false);
            onPath = new vector<bool>(numCourses, false);
            hasCycle = false;
            buildGraph(numCourses, prerequisites);
            vector<int> empty;
            for(auto node : graph){
                hasCycle = dfs(node.first);
                if (hasCycle){
                    return empty;
                }
            }

            delete visited;
            delete onPath;

            //reverse the stack
            vector<int> rev(s.size(), -1);
            int last = s.size() -1;
            for (int i =0; i<s.size(); i++){
                rev[last - i] = s[i];
            }
            return rev;
        }

    private:
        vector<int> s;
        vector<bool> *visited; //black
        vector<bool> *onPath; //gray
        unordered_map<int, vector<int>> graph;
        bool hasCycle;

        void buildGraph(int numCourses, vector<vector<int>> input){

            //before we process graph build the base courses
            //personally I think this is stupid, we should prepresent them
            //in the input as having 0 prereqs, but whatever.
            for (int i = 0; i< numCourses; i++){
                vector<int> foo;
                graph[i] = foo;
            }

            for(auto pair : input){
                int course = pair[1];
                int required = pair[0];
                graph[course].push_back(required);
            }
        }

        bool dfs(int head){

            cout << "dfs start: " << head << "\n";

            if ((*visited)[head]){
                cout << "\tvisited: " << head << "\n";
                return false;
            }

            if ((*onPath)[head]){
                cout << "\tonPath: " << head << "\n";
                return true;
            }

            (*onPath)[head] = true;
            bool ret = false;

            for (auto node : graph[head]){
                cout << "\tdfs child: " << node << "\n";
                ret = dfs(node);
                if (ret){
                    cout << "\tcycle found!: " << node << "\n";
                    return ret;
                }

            }

            cout << "dfs done: " << head << "\n";

            (*onPath)[head] = false;
            (*visited)[head] = true;
            s.push_back(head);
            return ret;
        }
};


int main() {
    //buil
    vector<vector<int>> prereq1 = {
        {1,0},
        {1,2}
    };

    vector<vector<int>> prereq2 = {
        {1,0},
        {0,1}
    };

    vector<vector<int>> prereq3 = {{0,2},{1,2},{2,0}};

    Solution solution;
    for (auto i : solution.findOrder(1, prereq3)){
        cout << i << ",";
    }

}