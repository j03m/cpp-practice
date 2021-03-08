#include<vector>
#include<iostream>
using namespace std;

int getCount(vector<vector<int>> &graph, int row, int col){
    int count = 0;
    //bottom
    if (row+1 >= graph.size()){
        count++;
    }
    else if (graph[row+1][col] == 0){
        count++;
    }

    //top
    if (row-1 < 0){
        count++;
    }
    else if(graph[row-1][col] == 0){
        count++;
    }

    //right
    if (col +1 >= graph[row].size()){
        count++;
    }
    else if(graph[row][col+1] == 0) {
        count++;
    }

    //left
    if (col +1 >= graph[row].size()){
        count++;
    }
    else if(graph[row][col+1] == 0) {
        count++;
    }
    return count;
}

int islandPerimeter(vector<vector<int>> &graph){
    int perimeter = 0;
    for(int row = 0; row < graph.size(); row++){
        for (int col = 0; col < graph[row].size(); col++){
            if (graph[row][col] == 1){ //land
                perimeter+=  getCount(graph, row, col);
            }
        }
    }
    return perimeter;
}

int main() {
    vector<vector<int>> graph = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    cout << islandPerimeter(graph);
}