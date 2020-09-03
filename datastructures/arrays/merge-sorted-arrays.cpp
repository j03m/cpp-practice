#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> mergeVectors(const vector<int> &v1, const vector<int> &v2){
    vector<int> merged(v1.size() + v2.size());
    int v1i = 0;
    int v2i = 0;

    for (size_t i = 0; i < merged.size(); ++i) {
        if (v1i > v1.size() && v2i < v2.size()){
            merged[i] = v2[v2i];
            v2i++;
        }

        if (v2i > v2.size() && v1i < v1.size()){
            merged[i] = v1[v1i];
            v1i++;
        }

        if (v1[v1i] <= v2[v2i]){
            merged[i] = v1[v1i];
            v1i++;
        }
        else if (v2[v2i] < v1[v1i]){
            merged[i] = v2[v2i];
            v2i++;
        }
    }

    return merged;
}


int main(){
    const vector<int> myVector {3, 4, 6, 10, 11, 15};
    const vector<int> alicesVector {1, 5, 8, 12, 14, 19};
    const vector<int> merged = mergeVectors(myVector, alicesVector);
    for (int i : merged) {
        cout << i << ",";
    }
    cout << "\n";

}