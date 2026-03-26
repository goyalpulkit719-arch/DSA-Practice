#include<bits/stdc++.h>
using namespace std;

/*
Problem: Equal Sum Grid Partition 1 (3545 medium)
Topic: Prefix Sum
TC = 0(m*n)
SC = 0(m+n)
*/


class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long total = 0;

        vector<long long int> row(m,0);
        vector<long long int> col(n,0);
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                row[i] += grid[i][j];
                col[j] += grid[i][j];
                total += grid[i][j];
            }
        }

        long long int sum = 0;
        for(int i=0; i<m; i++) {
            sum += row[i];
            if(total - 2*sum == 0) return true;
        }
        
        sum = 0;
        for(int i=0; i<n; i++) {
            sum += col[i];
            if(total - 2*sum == 0) return true;
            cout << col[i] << endl;
        }

        return false;

    }
};

/*
TC = 0(m*n)
SC = 0(1)
*/

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long total = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                total += grid[i][j];
            }
        }

        long long sum = 0;

        for(int i=0; i<m; i++) {
            long long rowSum = 0;
            for(int j=0; j<n; j++) {
                rowSum += grid[i][j];
            }

            sum += rowSum;
            if(total - 2*sum == 0) return true;
        }
        
        sum = 0;
        for(int j=0; j<n; j++) {
            long long colSum = 0;
            for(int i=0; i<m; i++) {
                colSum += grid[i][j];
            }

            sum += colSum;
            if(total - 2*sum == 0) return true;
        }

        return false;
    }
};