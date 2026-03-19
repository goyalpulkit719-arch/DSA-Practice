#include<bits/stdc++.h>
using namespace std;

/*
Problem: Count Submatrices with Top-Left Element and Sum Less Than k (3070 Medium)
Topics: Prefix Sum, Matrix
TC = 0(m*n)
SC = 0(1)
*/

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for(int i=0; i<m; i++) {
            long long int sum = 0;
            if(grid[i][0] > k) break;
            for(int j=0; j<n; j++) {
                if(i>0) grid[i][j] += grid[i-1][j];
                sum += grid[i][j];
                if(sum <= k) ans++;
            }
        }
        return ans;
    }
};