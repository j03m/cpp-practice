#include<deque>
#include<stdexcept>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;


vector<string> bfs(const unordered_map<string, vector<string>>& graph, const string& startNode, const string& endNode){
    deque<string> nodesToVisit;
    nodesToVisit.emplace_back(startNode);

    unordered_map<string,string> paths;
    paths.emplace(startNode, "");
    bool found = false;
    while(!nodesToVisit.empty()){
        string currentNode = nodesToVisit.front();
        cout << "visiting: " << currentNode << "\n";
        nodesToVisit.pop_front();
        if (currentNode == endNode){
            found = true;
            break;
        }

        auto search = graph.find(currentNode);
        if (search != graph.end()){
            for(const auto& neighbor : search->second) {
                if (paths.count(neighbor) == 0){
                    paths.emplace(neighbor, currentNode);
                    nodesToVisit.emplace_back(neighbor);
                }
            }
        }
    }

    vector<string> final;
    if (!found){
        return final;
    }


    string pathNode = endNode;
    while(!pathNode.empty()){
        final.push_back(pathNode);
        pathNode = paths.find(pathNode)->second;
    }

    reverse(final.begin(), final.end());
    return final;
}

int main(){

  unordered_map<string, vector<string>> network {
    { "Min",     { "William", "Jayden", "Omar" } },
    { "William", { "Min", "Noam" } },
    { "Jayden",  { "Min", "Amelia", "Ren", "Noam" } },
    { "Ren",     { "Jayden", "Omar" } },
    { "Amelia",  { "Jayden", "Adam", "Miguel", "boo" } },
    { "Adam",    { "Amelia", "Miguel", "Sofia", "Lucas" } },
    { "Miguel",  { "Amelia", "Adam", "Liam", "Nathan" } },
    { "Noam",    { "Nathan", "Jayden", "William" } },
    { "Omar",    { "Ren", "Min", "Scott" } },
    };

    vector<string> foo = bfs(network, "Amelia", "William");
    for (string f : foo){
        cout << f << "\n";
    }

}