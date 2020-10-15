#include <vector>
#include <iostream>
using namespace std;
bool binarySearch(int target, const vector<int>& nums)
{
    // see if target appears in nums

    // we think of floorIndex as leftmost edge of the possible positions
    // of our target and ceilingIndex as "wall" on the right of it
    size_t floorIndex = 0;
    size_t ceilingIndex = nums.size();

    // if there isn't at least 1 index between floor and ceiling,
    // we've run out of guesses and the number must not be present
    while (floorIndex < ceilingIndex) {

        // find the index ~halfway between the floor and ceiling
        // we use integer division, so we'll never get a "half index"
        size_t distance = ceilingIndex - floorIndex;
        size_t halfDistance = distance / 2;
        size_t guessIndex = floorIndex + halfDistance;

        int guessValue = nums[guessIndex];

        cout << "floor: " << floorIndex << " ceiling: " << ceilingIndex << " guess:" << guessIndex << "\n";

        if (guessValue == target) {
            return true;
        }

        if (guessValue > target) {
            // target is to the left, so move ceiling to the left
            ceilingIndex = guessIndex;
        }
        else {
            // target is to the right, so move floor to the right
            floorIndex = guessIndex + 1;
        }
    }

    return false;
}

int main(){
    vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << binarySearch(11, numbers) << "\n";

}