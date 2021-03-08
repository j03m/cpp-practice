#include<iostream>
#include<vector>
using namespace std;
unsigned int findDuplicate(const vector<int>& intVector)
{

    // STEP 1: GET INSIDE A CYCLE
    // start at position n+1 and walk n steps to
    // find a position guaranteed to be in a cycle
    unsigned int positionInCycle = intVector.size();
    for (int i = 0; i < intVector.size() - 1; ++i) {
    cout << "pos:" << positionInCycle << "value: " << << "\n";
        positionInCycle = intVector[positionInCycle - 1];
    }

    // STEP 2: FIND THE LENGTH OF THE CYCLE
    // find the length of the cycle by remembering a position in the cycle
    // and counting the steps it takes to get back to that position
    unsigned int rememberedPositionInCycle = positionInCycle;
    unsigned int currentPositionInCycle    = intVector[positionInCycle - 1];  // 1 step ahead
    unsigned int cycleStepCount = 1;

    while (currentPositionInCycle != rememberedPositionInCycle) {
        currentPositionInCycle = intVector[currentPositionInCycle - 1];
        ++cycleStepCount;
    }
}

int main(){
    vector<int> intVector {3, 4, 2, 3, 1, 5};
    cout << findDuplicate(intVector);



}