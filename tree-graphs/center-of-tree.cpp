#include<vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

typedef unordered_map<int, vector<int>> Graph;

void print(std::string prefix, vector<int> input){
    cout << prefix;
    for(int i : input){
        cout << i << ",";
    }
    cout << "\n";
}

vector<int> findCenter(Graph &g){
    int size = g.size();
    vector<int> leaves;
    int degrees[size];
    // N
    for (auto entry : g){
        if(entry.second.size() <= 1){
            leaves.push_back(entry.first);
            degrees[entry.first] = 0; //prune it
        }
        else {
            degrees[entry.first] = entry.second.size();
        }
    }

    int count = leaves.size();
    //N
    while(count < size){
        cout << "leaf count: " << count << " size of graph: " << size << "\n";
        string msg = "leaves are: ";
        print(msg, leaves);
        vector<int> new_leaves;
        for(int node : leaves){
            for(int child : g[node]){
                //prune my neighbors
                degrees[child]--;
                //if post pruning we are leaf, capture us
                if (degrees[child] == 1){
                    new_leaves.push_back(child);
                    degrees[child] = 0;
                }
            }
        }
        count+=new_leaves.size();
        leaves = new_leaves;
    }
    cout << "size:" << leaves.size() << "\n";
    if (leaves.size() > 2){
        throw -1;
    }
    return leaves;
}


int main(){

    Graph g {
           {0 , {1}},
           {1 , {0, 3, 4}},
           {4 , {1, 5, 8}},
           {3 , {1, 7, 6, 2}},
           {2, {3} },
           {6, {3, 9}},
           {7, {3}},
           {8, {4}},
           {5, {4}},
           {9, {6}}
    };

    //TODO htf does this work? I don't understand how we meet the exit condition - study it and document in mochi
    vector<int> center = findCenter(g);
    print("final: ", center);
}
