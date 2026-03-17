#include<bits/stdc++.h>
using namespace std;

/*
Problem: Array Partition (561)
Topics: Greedy
TC: 0(nlogn)
*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i=0; i<n; i+=2) {
            ans += nums[i];
        }

        return ans;
    }
};