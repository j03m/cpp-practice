#pragma once
#include<vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

class WeightedNode {
    public:
        int id;
        int weight;

        WeightedNode(int _id, int _weight):
         id(_id),
         weight(_weight){}
};


typedef vector<WeightedNode>  WeightedNodeList;
typedef unordered_map<int, vector<int>> Graph;
typedef unordered_map<int, WeightedNodeList> WeightedGraph;
typedef unordered_map<int, int> Path;

class Node {
    public:
        vector<Node> children;
        int id;
        Node* parent;
};

void printChildren(std::string prefix, vector<int> input);

void printTree(Node &root, int indent);