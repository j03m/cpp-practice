#include "common.h"
#include "center.h"

/*
    To find the center of the graph we will detect leaf nodes by looking at their total number of children. A leaf node
    is any node with edges(degrees) of 1. Because this is an undirected graph, every node will have at least one edge
    back to its parent node.

    Once we know which nodes are connected to leaves, we can reduce that nodes count of degrees and treat them as leaves.

    We can continue this processing until we have turned the entire graph into leaves. At that point the last 1-2 leaves

    we detected will be the center of the tree
*/

vector<int> findCenter(Graph &g){
    int size = g.size();
    int degrees[size];
    vector<int> leaves;
    for(auto pair : g){
        if (pair.second.size() == 1){
            leaves.push_back(pair.first);
            degrees[pair.first] = 0;
        }
        else {
            degrees[pair.first] = pair.second.size();
        }
    }

    int numLeaves = leaves.size();

    //continue this process until all nodes are reduced to a leaf
    while(numLeaves < size){

        //iterate through the leaves. And prune them - pruning them isn't removing them from the graph
        //which we will leave unchanged, but rather indicate that their "parent" has had one node removed by reducing
        //its degrees. If the modified parent, has no other edges, treat it as a newly detected leaf
        vector<int> newLeaves;
        for(auto child : leaves){
            for (auto edge : g[child]){
                degrees[edge]--;
                if (degrees[edge] == 1){
                    newLeaves.push_back(edge);
                }
            }
        }

        //now iterate through the new leaves, repeating the process
        leaves = newLeaves;
        numLeaves+=leaves.size();
    }

    //once we reduced the entire graph, we the remaining leaves should be our center.
    //return them but assert there are only 2
    if (leaves.size() > 2 || leaves.size() < 1){
        throw "bad center size";
    }

    return leaves;
}