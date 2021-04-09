#include <vector>
#include <iostream>
using namespace std;

/**
knowing a reasonable high score lets us generate a sorted index in o(n) instead of best case in place sorting
time of o(nlgn). Here we trade o(n) space complexity for the better time complexity.
**/
vector<int> sortScores (const vector<int> & unorderedScores, int highestPossibleScore)
{
    vector<int> scoredCounts(highestPossibleScore+1);
    for (int score : unorderedScores)
    {
        ++scoredCounts[score];
    }

    vector<int> sortedScores(unorderedScores.size());
    size_t currentSortedIndex = 0;

    for (int score = highestPossibleScore; score >= 0; --score)
    {
        int count = scoredCounts[score];
        for (int occurrence = 0; occurrence< count; ++occurrence)
        {
            sortedScores[currentSortedIndex] = score;
            ++currentSortedIndex;
        }
    }

    return sortedScores;
}

int main(){

    const vector<int> unsorted { 37, 89, 41, 65, 91, 53 };
    const vector<int> sorted = sortScores(unsorted, 100);
    for (int i : sorted){
        cout << i << ",";
    }
}