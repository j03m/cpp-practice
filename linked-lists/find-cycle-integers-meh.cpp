#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(const vector<int>& intVector) {

    int fast = intVector[intVector.size() - 1];
    int slow = intVector[intVector.size() - 1];

    //next
    slow = intVector[slow - 1];

    //next next
    fast = intVector[fast - 1];
    fast = intVector[fast - 1];
    cout << "pointers start:" << slow << "," << fast << "\n";

    if(slow == intVector.size()){
        //never reach head again, there is no cycle
        cout<< "no cycle" << "\n";
        return -1;
    }

    while(slow != fast){
        if (slow == intVector.size()){
            //never reach head again, there is no cycle
            cout<< "no cycle" << "\n";
            return -1;
        }

        //next
        slow = intVector[slow - 1];

        //next next
        fast = intVector[fast - 1];

        fast = intVector[fast - 1];
        cout << "loop:"  << slow << "," << fast << "\n";
    }


    fast = intVector[intVector.size() -1];
    while(slow != fast){
       cout << "loop2:"  << slow << "," << fast << "\n";
       slow = intVector[slow - 1];
       fast = intVector[fast - 1];
    }
    cout << "answer: " << slow << "\n";
    return slow;
}

int main(){
    vector<int> intVector {3, 1, 2, 2};
    vector<int> intVector1 {3, 4, 2, 3, 1, 5};
    vector<int> intVector2 {4, 3, 1, 1, 4};
    vector<int> intVector3 {4, 3, 1, 5, 2};
    vector<int> intVector4 {3, 5, 1, 2, 5};
    vector<int> intVector5 {1, 2, 3, 4, 5};
    vector<int> intVector5 {1, 2, 3, 4, 5};

   // findDuplicate(intVector);
    //findDuplicate(intVector1);
    //findDuplicate(intVector2);
    //findDuplicate(intVector3);
    //findDuplicate(intVector4);
    findDuplicate(intVector5);



}