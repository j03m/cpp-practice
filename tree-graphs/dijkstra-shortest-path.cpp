#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<utility>
using namespace std;


// Structure of the condition
// for sorting the pair by its
// second elements
struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        return a.second > b.second;
    }
};

class Solution {
    public:
        Solution(unordered_map<int, vector<pair<int,int>>> &input):
        graph { input } {
            for(auto path : graph){
                // we don't really need this for unweighted, but when
                // I wrote it I was thinking about dijkstra
                distances[path.first] = INT_MAX; //infinity
                previous[path.first] = -1;
            }
        }

        vector<int> shortestPath(int start, int end){
            vector<int> path;
            priority_queue<pair<int, int>, vector<pair<int,int>>, myComp> pq;
            pair<int, int> startNode = { start, 0 };
            pq.push(startNode);
            distances[start] = 0;
            while(!pq.empty()){
                pair<int, int> node = pq.top();
                pq.pop();
                cout << "priority node: " << node.first << "\n";
                vector<pair<int,int>> children = graph[node.first];
                for (auto child : children) {
                    int childNode = child.first;
                    int childDistance = child.second;
                    if (distances[childNode] == INT_MAX){
                        distances[childNode] = distances[node.first] + childDistance;
                        cout << "\tchild: " << childNode << " cost: " << distances[childNode] << "\n";
                        pq.push(make_pair(childNode, distances[childNode]));
                        previous[childNode] = node.first;
                    }
                }

                if (node.first == end){
                    break;
                }
            }


            int current = end;
            while(current != -1){
                path.push_back(current);
                cout << current << " leads to: ";
                current = previous[current];
                cout << current << "\n";
            }

            return path;
        }

    private:
        unordered_map<int, vector<pair<int, int>>> &graph;
        unordered_map<int, int> distances;
        unordered_map<int, int> previous;


};

int main(){
    unordered_map<int, vector<pair<int, int>>> graph;
    graph[0] = { make_pair(1, 5), make_pair(2, 6) };
    graph[1] = { make_pair(3, 7), make_pair(4, 2) };
    graph[2] = { make_pair(5, 5), make_pair(6, 1) };
    graph[3] = { make_pair(7, 7)};
    graph[4] = {};
    graph[5] = {};
    graph[6] = { make_pair(7, 1) };
    graph[7] = {};

    Solution s(graph);
    //reverse me or use a stack
    vector<int> path = s.shortestPath(0, 7);
    for (auto node : path){
        cout << node << "\n";
    }
}