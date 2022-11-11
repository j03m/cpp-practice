#include <iostream>
#include "common.h"
#include <queue>
#include <unordered_set>

using namespace std;

// Structure of the condition
// for sorting the pair by its
// second elements
struct myComp
{
    constexpr bool operator()(
        WeightedNode const &a,
        WeightedNode const &b)
        const noexcept
    {
        return a.weight > b.weight;
    }
};

typedef priority_queue<WeightedNode, vector<WeightedNode>, myComp> NodeQueue;

bool shortestPath(WeightedGraph &g, int start, int end, Path &path)
{
    
    unordered_map<int, int> distance;
    unordered_set<int> visited;
    bool found = false;
    
    // all of the calculated distances for unvisted codes should be initialized to
    // the max possible value so that all of initial distance calculates are less.
    for (auto entry:g){
        distance[entry.first] = UINT_MAX;
        path[entry.first] = -1;
    }
    
    distance[start] = 0;
    path[start] = -1;
    NodeQueue queue;
    queue.push(WeightedNode(start, 0));
    
    while(!queue.empty()){
        WeightedNode current = queue.top();
        queue.pop();
        if (visited.find(current.id) != visited.end()){
            continue;
        }
        else {
            visited.insert(current.id);
        }
        if (current.id == end){
            found = true;
            break;
        }

        for(auto neighbor : g[current.id]){
            int difficulty = distance[current.id] + neighbor.weight;
            if (distance[neighbor.id] == UINT_MAX || distance[neighbor.id] > difficulty){
                distance[neighbor.id] = difficulty;
                path[neighbor.id] = current.id;
                queue.push(WeightedNode(neighbor.id, difficulty));
            }
        }
    }

    return found;
}

int main()
{

    WeightedGraph g = {
        {1, {
                WeightedNode(2, 2),
                WeightedNode(3, 1),
            }},
        {2, {WeightedNode(4, 1)}},
        {4, {WeightedNode(6, 1)}},
        {3, {
                WeightedNode(5, 6),
                WeightedNode(2, 8)
            }},
        {5, {WeightedNode(6, 1)

            }},
        {6, {}}
    };

    Path path;
    int start = 1;
    int end = 6;
    bool found = shortestPath(g, start, end, path);
    int id = end;
    if (found)
    {
        while (path[id] != -1)
        {
            cout << id << "->";
            id = path[id];
        }
    }
    else
    {
        cout << "not found\n";
    }
}

//todo - path nodes correct but
//c++ why does pushing onto the queue poison the current node?
//The path is backwards - can we get the path in the right order, do we have to reverse it?