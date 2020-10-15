#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

int findDupeBad(vector<int> &numbers){
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size(); i++){
        if (i != 0){
            if (numbers[i] == numbers[i-1]){
                return numbers[i];
            }
        }
    }
    throw invalid_argument("no duplicate!");
}

int findDupe(vector<int> &numbers){
    unsigned int floor = 1;
    unsigned int ceiling = numbers.size() - 1;

    while(floor < ceiling) {

        unsigned int midpoint = floor + ((ceiling - floor)/2);
        unsigned int lowerRangeFloor = floor;
        unsigned int lowerRangeCeiling = midpoint;
        unsigned int upperRangeFloor = midpoint + 1;
        unsigned int upperRangeCeiling = ceiling;

        cout << "floor: " << floor << "\n";
        cout << "ceiling: " << ceiling << "\n";
        cout << "midpoint: " << midpoint << "\n";


        unsigned int itemsInLowerRange = 0;
        for (unsigned int item : numbers) {
            cout << "\t" << item;
            if (item >= lowerRangeFloor && item <= lowerRangeCeiling){
                cout << " is in low range";
                ++itemsInLowerRange;
            }
            cout << "\n";
        }

        unsigned int distinctPossibleIntegersInLowerRange = lowerRangeCeiling - lowerRangeFloor + 1;
        cout << "\t\t possibles:" << distinctPossibleIntegersInLowerRange << " actual:" << itemsInLowerRange << "\n";
        if (itemsInLowerRange > distinctPossibleIntegersInLowerRange) {
            // there must be a duplicate in the lower range
            // so use the same approach iteratively on that range
            floor   = lowerRangeFloor;
            ceiling = lowerRangeCeiling;
        }
        else {
            // there must be a duplicate in the upper range
            // so use the same approach iteratively on that range
            floor   = upperRangeFloor;
            ceiling = upperRangeCeiling;
        }
    }

    // floor and ceiling have converged
    // we found a number that repeats!
    return floor;
}

int main(){
    vector<int> numbers { 3, 4, 5, 7, 1, 12, 4, 3};
    cout << findDupe(numbers) << "\n";
}