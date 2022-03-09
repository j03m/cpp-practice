#pragma once
#include<vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

typedef unordered_map<int, vector<int>> Graph;

class Node {
    public:
        vector<Node> children;
        int id;
        Node* parent;
};

void printChildren(std::string prefix, vector<int> input);

void printTree(Node &root, int indent);