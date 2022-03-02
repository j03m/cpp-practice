#include <common.h>


/*
    To find the center of the graph we will detect leaf nodes by looking at their total number of children. A leaf node
    is any node with edges(degrees) of 1. Because this is an undirected graph, every node will have at least one edge
    back to its parent node.

    Once we know which nodes are connected to leaves, we can reduce that nodes count of degrees and treat them as leaves.

    We can continue this processing until we have turned the entire graph into leaves. At that point the last 1-2 leaves

    we detected will be the center of the tree
*/

vector<int> findCenter(Graph &g){

}