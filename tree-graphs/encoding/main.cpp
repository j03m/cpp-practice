#include<common.h>
#include<encoding.h>
#include<center.h>
#include<rooting.h>
#include<encoding.h>
#include<string>

using namespace std;

bool compare(Graph &g1, Graph g2){
    vector<int> center = findCenter(g1);
    vector<int> center2 = findCenter(g2);
    Node root1 = getRootedNode(g1, center[0], nullptr);
    string encoding1 = encodeTree(root1);
    for(int mid : center2){
        Node root2 = getRootedNode(g2, mid, nullptr);
        string encoding2 = encodeTree(root2);
        if (encoding1 == encoding2){
            return true;
        }
    }
    return false;
}

int main(){
    //compare two equal trees and two not equal trees
    Graph g1 = {
        { 0: { 1, 2} },
        { 1: { 0 } },
        { 2: { 5, 6, 0} },
        { 6: { 2 } },
        { 5: { 2 } },
        { 3: { 2, 4} },
        { 4: { 3 } }
    };

    Graph g2 = {
        { 1: { 2 } },
        { 0: { 3 } },
        { 6: { 5 } },
        { 5: { 6, 3 } },
        { 3: { 0, 5, 4 }},
        { 2: { 1, 3 }}
    };

    cout << compare(g1, g2);

}