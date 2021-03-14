#include<queue>
#include<unordered_map>
#include<iostream>
using namespace std;
class Solution {
    public:

        Solution(unordered_map<int, vector<int>> &input):
        graph { input } {

            for(auto path : graph){
                // we don't really need this for unweighted, but when
                // I wrote it I was thinking about dijkstra
                distance[path.first] = INT_MAX; //infinity
                previous[path.first] = -1;
            }
        }

        bool bfs(int start, int end){
            queue<int> q;
            q.push(start);
            distance[start] = 0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                vector<int> children = graph[node];
                for (auto child : children) {
                    if (distance[child] == INT_MAX) {
                        cout << node << " -> " << child << "\n";
                        distance[child] = distance[node] + 1; //all edges are equal
                        previous[child] = node;
                        q.push(child);
                    }
                     if (child == end){
                        //done
                        return true;
                     }
                }

            }

            return false;
        }

        vector<int> shortestPath(int start, int end){
            vector<int> path;
            if (bfs(start, end)){
                int current = end;
                path.push_back(current);
                while(previous[current] != -1){
                    cout << current << " gets " << previous[current] << "\n";
                    path.push_back(previous[current]);
                    current = previous[current];
                }
            }
            return path;
        }

    private:
        unordered_map<int, vector<int>> &graph;
        unordered_map<int, int> distance;
        unordered_map<int, int> previous;
};



int main(){

    unordered_map<int, vector<int>> graph {
       {0, { 1, 2}},
       {1, { 3, 4}},
       {2, { 5, 4}},
       {3, { 6, 7 }},
       {4, { 6 }},
       {5, { 6, 8 }},
       {6, { 7 }},
       {7, { 8 }},
       {8, {}}
    };

    Solution s(graph);
    vector<int> path = s.shortestPath(0, 8);
    for (auto node : path){
        cout << node << "\n";
    }

}