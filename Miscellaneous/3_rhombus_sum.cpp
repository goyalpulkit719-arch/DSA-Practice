#include<bits/stdc++.h>
using namespace std;

/*
Problem: Get Biggest Three Rhombus Sums in a Grid(1878)
Topics: Maths
TC: 0(n*m*min(m,n)^2)
*/

class Solution {
public:
    void solve(vector<long long> &ans, long long sum) {
        for (long long x : ans) {
            if (x == sum) return;   // avoid duplicates
        }

        int mini = 0;
        if (ans[1] < ans[mini]) mini = 1;
        if (ans[2] < ans[mini]) mini = 2;

        if (ans[mini] < sum) ans[mini] = sum;
    }

    long long compute(vector<vector<int>>& grid, int a, int b, int jmp) {
        long long sum = 0;

        // top -> left
        for (int i = a, j = b; i <= a + jmp / 2; i++, j--) {
            sum += grid[i][j];
        }

        // top -> right (skip top)
        for (int i = a + 1, j = b + 1; i <= a + jmp / 2; i++, j++) {
            sum += grid[i][j];
        }

        // left -> bottom (skip left)
        for (int i = a + jmp / 2 + 1, j = b - jmp / 2 + 1; i <= a + jmp; i++, j++) {
            sum += grid[i][j];
        }

        // right -> bottom (skip right and bottom)
        for (int i = a + jmp / 2 + 1, j = b + jmp / 2 - 1; i < a + jmp; i++, j--) {
            sum += grid[i][j];
        }

        return sum;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<long long> ans = {LLONG_MIN, LLONG_MIN, LLONG_MIN};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long num = grid[i][j];
                solve(ans, num);

                for (int jmp = 2; i + jmp < m; jmp += 2) {
                    if ((j - jmp / 2) >= 0 && (j + jmp / 2) < n) {
                        long long sum = compute(grid, i, j, jmp);
                        solve(ans, sum);
                    }
                }
            }
        }

        vector<long long> temp;
        for (long long x : ans) {
            if (x != LLONG_MIN) temp.push_back(x);
        }

        sort(temp.begin(), temp.end(), greater<long long>());

        vector<int> rtn;
        for (long long x : temp) {
            rtn.push_back((int)x);
        }

        return rtn;
    }
};



/*
OPTIMISED VERSION USING PREFIX SUM
Problem: Get Biggest Three Rhombus Sums in a Grid(1878)
Topics: Maths, Prefix Sum
TC: 0(n*m*(min(m,n)))
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<long long>> diag1, diag2;

    void solve(vector<long long>& ans, long long sum) {
        for (long long x : ans) {
            if (x == sum) return;
        }

        int mini = 0;
        if (ans[1] < ans[mini]) mini = 1;
        if (ans[2] < ans[mini]) mini = 2;

        if (ans[mini] < sum) ans[mini] = sum;
    }

    void buildDiagonalPrefix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        diag1.assign(m + 1, vector<long long>(n + 1, 0));
        diag2.assign(m + 1, vector<long long>(n + 2, 0));

        // '\' diagonal prefix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diag1[i + 1][j + 1] = grid[i][j] + diag1[i][j];
            }
        }

        // '/' diagonal prefix
        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j >= 0; j--) {
                diag2[i + 1][j] = grid[i][j] + diag2[i][j + 1];
            }
        }
    }

    long long getDiag1(int r1, int c1, int r2, int c2) {
        return diag1[r2 + 1][c2 + 1] - diag1[r1][c1];
    }

    long long getDiag2(int r1, int c1, int r2, int c2) {
        return diag2[r2 + 1][c2] - diag2[r1][c1 + 1];
    }

    long long compute(vector<vector<int>>& grid, int a, int b, int jmp) {
        int k = jmp / 2;

        int top_r = a, top_c = b;
        int left_r = a + k, left_c = b - k;
        int right_r = a + k, right_c = b + k;
        int bottom_r = a + jmp, bottom_c = b;

        long long sum = 0;

        // top -> right  (\)
        sum += getDiag1(top_r, top_c, right_r, right_c);

        // top -> left   (/)
        sum += getDiag2(top_r, top_c, left_r, left_c);

        // left -> bottom (\)
        sum += getDiag1(left_r, left_c, bottom_r, bottom_c);

        // right -> bottom (/)
        sum += getDiag2(right_r, right_c, bottom_r, bottom_c);

        // corners counted twice
        sum -= grid[top_r][top_c];
        sum -= grid[left_r][left_c];
        sum -= grid[right_r][right_c];
        sum -= grid[bottom_r][bottom_c];

        return sum;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        buildDiagonalPrefix(grid);

        vector<long long> ans = {LLONG_MIN, LLONG_MIN, LLONG_MIN};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                solve(ans, grid[i][j]);

                for (int jmp = 2; i + jmp < m; jmp += 2) {
                    int k = jmp / 2;
                    if (j - k >= 0 && j + k < n) {
                        long long sum = compute(grid, i, j, jmp);
                        solve(ans, sum);
                    }
                }
            }
        }

        vector<long long> temp;
        for (long long x : ans) {
            if (x != LLONG_MIN) temp.push_back(x);
        }

        sort(temp.begin(), temp.end(), greater<long long>());

        vector<int> rtn;
        for (long long x : temp) {
            rtn.push_back((int)x);
        }

        return rtn;
    }
};