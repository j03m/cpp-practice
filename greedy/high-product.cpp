#include<iostream>
#include<vector>
#include<algorithm>
#include<stdexcept>
using namespace std;




int main(){

    vector<int> numbers({1, 10, -5, 1, -100});

    if (numbers.size() < 3){
        throw invalid_argument("need 3");
    }

    int highest = max(numbers[0], numbers[1]);
    int lowest = min(numbers[0], numbers[1]);

    int highestTwo = numbers[0] * numbers[1];
    int lowestTwo = numbers[0] * numbers[1];
    int highestThree = numbers[0] * numbers[1] * numbers[2];

    for(size_t i = 2; i < numbers.size(); i++){
        int current = numbers[i];
        highestThree = max(highestThree, current * highestTwo);
        highestThree = max(highestThree, current * lowestTwo);

        highestTwo = max(highestTwo, current * highest);
        highestTwo = max(highestTwo, current * lowest);

        lowestTwo = min(lowestTwo, current * highest);
        lowestTwo = min(lowestTwo, current * lowest);

        highest = max(highest, current);
        lowest = min(lowest, current);
    }

    cout << highestThree;

}