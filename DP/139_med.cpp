#include<bits/stdc++.h>
using namespace std;


/*
Problem: Unique Binary Search Trees (96 medium)
Topics: DP 
TC = 0(n^2)
SC = 0(m+n)  m for set and n for dp vector 
*/


class Solution {
public:
    unordered_set<string> st;
    vector<int> dp;
 
    bool solve(string &s, int i) {
        if(i == s.size()) return true;

        if(dp[i] != -1) return dp[i];

        string temp = "";

        for(int j = i; j < s.size(); j++) {
            temp += s[j];

            if(st.count(temp) && solve(s, j+1)) {
                return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        st = unordered_set<string>(wordDict.begin(), wordDict.end());
        dp.resize(s.size(), -1);

        return solve(s, 0);
    }
};