#include<bits/stdc++.h>
using namespace std;


/*
Problem: Unique Binary Search Trees (96 medium)
Topics: DP and Binary Tree
TC = 0(n)
SC = 0(n) (recursion stack + dp vector)

Memoization
*/

class Solution {
public:
    int solve(int n, vector<int> &dp) {
        if(n<=1) return 1;

        if(dp[n]!= -1) return dp[n];

        int ans = 0;

        for(int i=1; i<=n; i++) {
            ans += solve(i-1, dp)*solve(n-i, dp);
        }
        
        return dp[n] = ans;
    }

    int numTrees(int n) {
        
        vector<int> dp(n+1,-1);
        return solve(n, dp);
    }

    
};


/*
Problem: Unique Binary Search Trees (96 medium)
Topics: DP
TC = 0(n)
SC = 0(n) (dp vector)

Bottom Up
*/


class Solution {
public:
    int numTrees(int n) {
        
        vector<int> dp(n+1,-1);
        
        dp[0] = dp[1] = 1;

        for(int i=1; i<=n; i++) {
            int ans = 0;
            for(int j=1; j<=i; j++) {
                ans += dp[j-1]*dp[i-j];
            }

            dp[i] = ans;
        }

        return dp[n];
    }
};