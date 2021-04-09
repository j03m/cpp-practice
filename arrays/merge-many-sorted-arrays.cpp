#include <iostream>
#include <string>
#include <vector>
using namespace std;



int min (const vector<vector<int>> &vectors, vector<int> &positions) {
    int min = INT_MAX;
    int pos = 0;
    int selected = -1;
    for (vector<int> v : vectors) {
        int index = positions[pos];
        if (index < v.size()){
            cout << "vector: " << pos << " vector index: " << index << " vector value: " << v[index] << " current min: " << min << "\n";
            if (v[index] < min){
                min = v[index];
                selected = pos;
                cout << "updated min: " << min << "\n";
            }
        }
        pos++;
    }
    if (selected == -1) {
        cout << "something went wrong, no min" << "\n";
        throw -1;
    }
    positions[selected]++;

    return min;
}

vector<int> mergeVectors(const vector<vector<int>> &vectors){

    int finalSize = 0;
    for (vector<int> v : vectors){
        finalSize += v.size();
    }

    vector<int> positions(vectors.size());
    for(int x = 0; x < vectors.size(); x++){
        positions[x] = 0;
    }

    vector<int> merged(finalSize);
    for(int x = 0; x < merged.size(); x++){
        cout << " index: " << x << " of " << merged.size() << "\n";
        merged[x] = min(vectors, positions);
    }
    return merged;
}


int main(){
    const vector<int> myVector {3, 4, 6, 10, 11, 15};
    const vector<int> alicesVector {1, 5, 8, 12, 14, 19};
    const vector<int> fredVector { 3, 5 };
    const vector<vector<int>> allVectors {myVector, alicesVector, fredVector };
    const vector<int> merged = mergeVectors(allVectors);
    for (int i : merged) {
        cout << i << ",";
    }
    cout << "\n";

}