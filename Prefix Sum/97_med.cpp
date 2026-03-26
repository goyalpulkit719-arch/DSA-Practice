#include<bits/stdc++.h>
using namespace std;

/*
Problem: Interleaving String (97 medium)
Topics: DP and String
TC = 0(m*n*p)
SC = 0(m*n*p)
*/

class Solution {
    public:
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<vector<int>>> &dp) {
        
        if(k==0) return true;
        
        if(i>0 && j>0 && dp[i][j][k]!=-1) return dp[i][j][k];
        
        if(i>0 && j>0 && s1[i-1]==s3[k-1] && s2[j-1]==s3[k-1]) {
            return dp[i][j][k] = solve(s1,s2,s3,i-1,j,k-1,dp) || solve(s1,s2,s3,i,j-1,k-1,dp);
        }
        else if(i>0 && s1[i-1]==s3[k-1]) {
            return dp[i][j][k] = solve(s1,s2,s3,i-1,j,k-1,dp);
        }
        else if(j>0 && s2[j-1]==s3[k-1]) {
            return dp[i][j][k] = solve(s1,s2,s3,i,j-1,k-1,dp);
        }
        
        return dp[i][j][k] = false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        
        if(n1+n2 != n3) return false;
        
        vector<vector<vector<int>>> dp(n1+1, vector<vector<int>> (n2+1, vector<int> (n3+1,-1)));
        
        return solve(s1,s2,s3, n1, n2, n3, dp);
    }
};


/*
TC = 0(m*n)
SC = 0(m*n)
*/


class Solution {
public:
    bool solve(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>> &dp) {

        if(i==0 && j==0) return true;

        if(dp[i][j] != -1) return dp[i][j];

        int k = i + j;

        bool ans = false;

        if(i > 0 && s1[i-1] == s3[k-1])
            ans |= solve(s1, s2, s3, i-1, j, dp);

        if(j > 0 && s2[j-1] == s3[k-1])
            ans |= solve(s1, s2, s3, i, j-1, dp);

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {

        int n1 = s1.size(), n2 = s2.size();

        if(n1 + n2 != s3.size()) return false;

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));

        return solve(s1, s2, s3, n1, n2, dp);
    }
};