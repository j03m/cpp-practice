#include <iostream>
#include <vector>
using namespace std;
int trap(vector<int> &heights){
    int left = 0;
    int right = heights.size() -1;
    int maxLeft = 0;
    int maxRight = 0;
    int trapped = 0;
    while (left < right){
        if (heights[left] < heights[right]){
            //move the left wall
            if (heights[left] > maxLeft){
                maxLeft = heights[left];
            }
            else {
                trapped += (maxLeft - heights[left]);
            }
            left++;
        }
        else {
            //move the right wall
            if (heights[right] > maxRight){
                maxRight = heights[right];
            }
            else {
                trapped += (maxRight - heights[right]);
                cout << "trapped: " << trapped << "\n";
            }
            right--;
        }
    }

    return trapped;
}


int main(){
    vector<int> heights {
        0,1,0,2,1,0,1,3,2,1,2,1
    };

    cout << trap(heights);
}