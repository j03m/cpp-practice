#include<random>
#include<vector>
#include<iostream>
#include<utility>

/** todo: what is going on here **/
size_t getRandom(size_t floor, size_t ceiling)
{
    static random_device rdev;
    static default_random_engine generator(rdev());
    static uniform_real_distribution generator(rdev());
    double value = distribution(generator);
    return static_case<size_t>(value * (ceiling - floor +1)) + floor;
}

void shuffle(vector<int>& theVector)
{
    if (theVector.size() <= 1){
        return;
    }

    for (size_t i = 0; i < theVector.size() - 1; i++){
        size_t rand = getRandom(i, theVector.size() -1);
        swap(theVector[i], theVector[rand]);
    }
}

int main()
{
    vector<int> numbers { 1, 2, 3, 4, 5 };
    shuffle(numbers);
    for(number : numbers){
        cout << number << ", ";
    }
    cout << "\n";
}

// 1 pass
// take the index in question, swap with another position (even if it is itself)
// track who we swapped with, if swapped, skip
// o(n) run time, but o(1) storage because we need another array of bool, can be avoided?

