#include<bits/stdc++.h>
using namespace std;

/*
Problem: Maximum Non Negative Product in a Matrix (1594 medium)
Topics: DP
TC: 0(m*n)
SC: 0(m*n)
*/

class Solution {
public:
    int mod = 1e9 + 7;
    using ll = long long;

    pair<ll,ll> solve(vector<vector<int>> &grid, int i, int j, vector<vector<ll>> &dp1, vector<vector<ll>> &dp2) {

        int m = grid.size();
        int n = grid[0].size();

        if(i==0 && j==0) return {grid[i][j], grid[i][j]};

        if(dp1[i][j]!=LLONG_MIN || dp2[i][j]!=LLONG_MAX) return {dp1[i][j], dp2[i][j]};

        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        if(i > 0) {
            auto [Maxi, Mini] = solve(grid, i-1, j, dp1, dp2);
            maxVal = max({maxVal, Maxi * grid[i][j], Mini * grid[i][j]});
            minVal = min({minVal, Maxi * grid[i][j], Mini * grid[i][j]});
        }

        if(j > 0) {
            auto [Maxi, Mini] = solve(grid, i, j-1, dp1, dp2);
            maxVal = max({maxVal, Maxi * grid[i][j], Mini * grid[i][j]});
            minVal = min({minVal, Maxi * grid[i][j], Mini * grid[i][j]});
        }

        dp1[i][j] = maxVal;
        dp2[i][j] = minVal;
        
        return {maxVal, minVal};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<ll>> dp1(m, vector<ll> (n,LLONG_MIN));
        vector<vector<ll>> dp2(m, vector<ll> (n,LLONG_MAX));


        auto ans = solve(grid, m-1, n-1, dp1, dp2);

        return ans.first<0? -1 : ans.first%mod;

    }
};