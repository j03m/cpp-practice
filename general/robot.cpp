#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> directions = {
            {0, 1}, //direction 0 (North) = no X change, but y change + 1
            {1, 0},
            {0, -1},
            {-1, 0}
        };

        int x = 0, y = 0;
        int idx = 0;

        for (int pos = 0; pos < instructions.size(); pos++){
            const char i = instructions[pos];
            if (i == 'L'){
                idx = (idx + 3) % 4; //1 left turn = 3 right turns
            }
            else if (i == 'R'){
                idx = (idx + 1) % 4;
            }
            else {
                x += directions[idx][0];
                y += directions[idx][1];
            }

        }

        // based on this proof https://leetcode.com/problems/robot-bounded-in-circle/solution/#appendix-mathematical-proof
        // if we have returned to 0 or the robot doesn't face north then there exists a circle such that the robot never leaves
        // because we have proved the robots trajectory is limited

        return (x == 0 && y == 0) || idx != 0;

    }
};

int main(){
    Solution s;
    cout << s.isRobotBounded("GGLLGGLG") << "\n";
}