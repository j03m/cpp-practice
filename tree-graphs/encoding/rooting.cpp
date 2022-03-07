#include<rooting.h>
#include<common.h>

/**
  Recreate an undirected graph as a tree, starting from the supplied node
**/
Node getRootedNode(Graph &g, int id, Node *parent){
    // Declare a node for this id
    // for each child of the node id in question, add that node to the supplied id's new tree children
    // recursively add the child node's children
    // because the graph is undirected, skip any edges back to the parent
    Node node;
    node.id = id;
    node.parent = parent;
    for(auto child : g[id]){
        if (parent !== nullptr && child != parent->id){
            node.children.push_back(getRootedNode(g, child, &node));
        }
    }
    return node;
}