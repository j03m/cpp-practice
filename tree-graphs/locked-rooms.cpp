#include <iostream>
#include <stack>
#include <vector>
#include <unordered_set>

using namespace std;


void pushKeys(stack<int>& stack, vector<int>& keys){
    for (auto& it : keys) {
        stack.push(it);
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    unordered_set <int> visited;
    stack<int> path;
    path.push(0); //start node
    while(!path.empty()){
        int room = path.top();
        path.pop();
        if (visited.find(room) == visited.end()){
            visited.insert(room);
            pushKeys(path, rooms[room]);
        }
    }
    return visited.size() == rooms.size();
}

int main(){
    vector<vector<int>> test1 {
        {1}, {2}, {3}, {}
    };
    vector<vector<int>> test2 {
        {1,3}, {3,0,1}, {2}, {0}
    };
    cout << canVisitAllRooms(test2) << "\n";
}