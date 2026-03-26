#include<bits/stdc++.h>
using namespace std;

/*
Problem: Minimum Absolute Difference in Sliding Submatrix (3567 medium)
Topics: Sorting, Matrix
TC: 0(m*n*k^2*log(k))
SC: 0(m*n)
*/

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans;

        for(int i=0; i<=m-k; i++) {
            vector<int> curr;
            for(int j=0; j<=n-k; j++) {

                vector<int> diff;
                for(int a=0; a<k; a++) {
                    for(int b=0; b<k; b++) {
                        diff.push_back(grid[a+i][b+j]);
                    }
                }
                sort(diff.begin(), diff.end());
                int mini = INT_MAX;
                for(int a=1; a<diff.size(); a++) {
                    if(diff[a] != diff[a-1]) mini = min(mini, abs(diff[a]-diff[a-1]));
                }

                if(mini == INT_MAX) mini = 0;
                curr.push_back(mini);
            }
            ans.push_back(curr);
        }

        return ans;
    }
};