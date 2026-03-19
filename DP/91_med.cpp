#include<bits/stdc++.h>
using namespace std;

/*
Problem: Decode Ways (91 Medium)
Topics: Dynamic Programming
TC = 0(n)
SC = 0(n)
Memoization 
*/

class Solution {
public:
    int solve(string &s, int i, vector<int> &dp) {
        if(i<0) return 1;

        if(dp[i] != -1) return dp[i];

        if(s[i]=='0') {
            if(i>0 && (s[i-1]=='1' || s[i-1]=='2')) return dp[i] = solve(s, i-2, dp);
            else return dp[i] = 0;
        }
        else{
            int one = solve(s, i-1, dp);
            int two = 0;
            if(i>0) {
                if(s[i-1]=='1') two = solve(s, i-2, dp);
                else if(s[i-1]=='2' && s[i]<'7') two = solve(s, i-2, dp); 
            }
            return dp[i] = one + two;

        }
    }

    int numDecodings(string s) {
        int n = s.length();

        vector<int> dp(n,-1);
        return solve(s, n-1, dp);
    }
};


/*
TC = 0(n)
SC = 0(n) no recursion stack
Tabulation
*/


class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();

        vector<int> dp(n+1,0);

        dp[0] = 1;        // base case

        for(int i=1; i<=n; i++) {

            if(s[i-1]=='0') {
                if(i>1 && (s[i-2]=='1' || s[i-2]=='2')) dp[i] = dp[i-2];
                else dp[i] = 0;
            }
            else{
                int one = dp[i-1];
                int two = 0;
                if(i>1) {
                    if(s[i-2]=='1') two = dp[i-2];
                    else if(s[i-2]=='2' && s[i-1]<'7') two = dp[i-2];
                }
                dp[i] = one + two;

            }

        }

        return dp[n];

    }
};