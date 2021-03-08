#include<vector>
#include<stack>
#include<iostream>
#include<utility>
using namespace std;


/**

While this might perform better for small islands in VAST seas, its worst case runtime is the same as
island-perimeter.cpp O(n*m) and it has worse storage (the stack is wost case o(n) in the case of all no water).

In addition to this, in practice this was much slower than solution 1! 112ms to run vs 80 ms and 99.5mb vs 95.8 mb

**/

int getCount(vector<vector<int>> &graph, int row, int col, stack<pair<int,int>> &s){
    int count = 0;
    //bottom
    if (row+1 >= graph.size()){
        count++;
    }
    else if (graph[row+1][col] == 0){
        count++;
    }
    else if (graph[row+1][col] == 1){
        cout << "push: " << row+1 << col << "\n";
        graph[row+1][col] = -1;
        s.push({row+1,col});
    }

    //top
    if (row-1 < 0){
        count++;
    }
    else if(graph[row-1][col] == 0){
        count++;
    }
    else if (graph[row-1][col] == 1){
    cout << "push: " << row-1 << col << "\n";
        graph[row-1][col] = -1;
        s.push({row-1,col});
    }

    //right
    if (col +1 >= graph[row].size()){
        count++;
    }
    else if(graph[row][col+1] == 0) {
        count++;
    }
    else if (graph[row][col+1] == 1){
        cout << "push: " << row << col+1 << "\n";
        graph[row][col+1] = -1;
        s.push({row,col+1});
    }

    //left
    if (col-1 < 0){
        count++;
    }
    else if(graph[row][col-1] == 0) {
        count++;
    }
    else if (graph[row][col-1] == 1){
        cout << "push: " << row << col-1 << "\n";
        graph[row][col-1] = -1;
        s.push({row,col-1});
    }

    return count;
}


int dfs(vector<vector<int>> &graph, int row, int col){
    int perimeter = 0;
    stack<pair<int, int>> s;
    s.push({row, col});
    while(!s.empty()){
        pair<int, int> cell = s.top();
        graph[cell.first][cell.second] = -1; //traversed, land
        s.pop();
        perimeter+=getCount(graph, cell.first, cell.second, s);
    }
    return perimeter;
}

int islandPerimeter(vector<vector<int>> &graph){
    for(int row = 0; row < graph.size(); row++){
        for (int col = 0; col < graph[row].size(); col++){
            if (graph[row][col] == 1){ //on first land dfs
                return dfs(graph, row, col);
            }
        }
    }
    return 0;
}

int main() {
    vector<vector<int>> graph = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    //vector<vector<int>> graph = {{1,1},{1,1}};

    cout << islandPerimeter(graph);
}