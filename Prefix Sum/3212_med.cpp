#include<bits/stdc++.h>
using namespace std;

/*
Problem: Count Submatrices With Equal Frequency of X and Y (3212 Medium)
Topics: Matrix, Prefix Sum
TC: 0(m*n)
SC: 0(n)
*/

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prevx(n,0);
        vector<int> prevy(n,0);
        int ans = 0;

        for(int i=0; i<m; i++) {
            int curx =0, cury=0;
            for(int j=0; j<n; j++) {

                if(grid[i][j]=='X') {
                    prevx[j] += 1;
                }
                else if(grid[i][j]=='Y') {
                    prevy[j] += 1;
                }
                curx += prevx[j];
                cury += prevy[j];

                if(cury>0 && cury==curx) {
                    // cout << i << " " << j << " " << curx << " " << cury << endl;
                    ans++;
                }
            }
        }

        return ans;
    }
};