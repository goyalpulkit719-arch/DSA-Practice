#include<bits/stdc++.h>
using namespace std;

/*
Problem: Largest Submatrix With Rearrangements (1727 Medium)
Topics: Greedy and Prefix Sum
TC = 0(m*n*log(n))
SC = 0(n)
*/

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 0;
        vector<int> last(n,0);
        
        for(int i=0; i<m; i++) {
            vector<int> curr(n,0);
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0) curr[j] = 0;
                else{
                    curr[j] = last[j] + 1;
                }
            }
            last = curr;
            sort(curr.begin(), curr.end());
            for(int k=n-1; k>=0; k--) {
                ans = max(ans, curr[k]*(n-k));
            }
        }
        return ans;
    }
};


/*
Optimised Version
TC = 0(m*n*logn)
SC = 0(1)
*/


class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;

        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 1)
                    matrix[i][j] += matrix[i - 1][j];

        for (int i = 0; i < m; i++) {
            sort(matrix[i].begin(), matrix[i].end());
            for (int j = n-1; j>=0; j--)
                res = max(res, matrix[i][j] * (n - j));
        }

        return res;
    }
};