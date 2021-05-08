#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> storage;
            vector<int> final;
            int len = nums.size();
            for(int i =0; i < len; i++){
                storage[nums[i]] = i;
            }

            for(int i =0; i < len; i++){
               int possible = target - nums[i];
               if (storage.find(possible) != storage.end() &&
                   storage[possible] != i){
                   final.push_back(i);
                   final.push_back(storage[possible]);
                   break;
               }
            }

            return final;
        }
    };

int main(){
    Solution s;
    vector<int> nums = {2,7,11,15};

    for (auto i : s.twoSum(nums, 9)){
        cout << i << ",";
    }
    cout << "\n";

}