#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void getChildren(vector<vector<int>> &matrix, stack<int> &children, vector<bool> &visited, int pos){
    for (int i = 0; i<matrix.size(); i++){
        if (!visited[i] && matrix[pos][i] == 1){
            children.push(i);
        }
    }
}


int findCircle(vector<vector<int>> matrix){
    vector<bool> visited(matrix.size());
    fill(visited.begin(), visited.end(), false);
    int count = 0;
    for (int i = 0; i < matrix.size(); i++){
        if (visited[i] == false){
            count++;
            stack<int> children;
            children.push(i);
            while(!children.empty()){
                int j = children.top();
                children.pop();
                visited[j] = true;
                getChildren(matrix, children, visited, j);
            }
        }
    }
    return count;
}


int main(){

//  vector<vector<int>> v {{1,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
//                        {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
//                        {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
//                        {0,0,0,1,0,1,1,0,0,0,0,0,0,0,0},
//                        {0,0,0,0,1,0,0,0,0,1,1,0,0,0,0},
//                        {0,0,0,1,0,1,0,0,0,0,1,0,0,0,0},
//                        {0,0,0,1,0,0,1,0,1,0,0,0,0,1,0},
//                        {1,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
//                        {0,0,0,0,0,0,1,1,1,0,0,0,0,1,0},
//                        {0,0,0,0,1,0,0,0,0,1,0,1,0,0,1},
//                        {0,0,0,0,1,1,0,0,0,0,1,1,0,0,0},
//                        {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
//                        {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
//                        {0,0,0,0,0,0,1,0,1,0,0,0,0,1,0},
//                        {0,0,0,0,0,0,0,0,0,1,0,0,0,0,1}};

    vector<vector<int>> v = {{1,1,0},{1,1,0},{0,0,1}};
    cout << findCircle(v);

}