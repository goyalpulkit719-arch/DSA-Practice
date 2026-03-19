#include<bits/stdc++.h>
using namespace std;

/*
Problem: Two Sum (1)
Topics: Array, Hash Map
TC: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;  // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (m.count(complement)) {
                return {m[complement], i};
            }

            m[nums[i]] = i;  // store current number's index
        }

        return {};  
    }
};
