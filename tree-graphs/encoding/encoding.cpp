#include <encoding.h>
#include <algorithm>

string encodeTree(Node &node){

    vector<string> labels;
    for (auto child : node.children){
        labels.push_back(encodeTree(child));
    }

    //sort the labels
    sort(labels.begin(), labels.end());

    //construct a result
    string result = "";
    for(auto label in labels){
        result+=label; //todo: is this inefficient does it make a copy?
    }

    return "(" + result + ")";
}