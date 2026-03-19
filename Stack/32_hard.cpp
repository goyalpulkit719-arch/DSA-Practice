#include<bits/stdc++.h>
using namespace std;

/*
Problem: Longest Valid Parenthesis (32 Hard)
Topics: Stack
TC = 0(n)
SC = 0(n)
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        int ans =  0;
        st.push(-1);

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();

                if(st.empty()) {
                    st.push(i);
                }
                else {
                    ans = max(ans, i-st.top());
                }
            }
        }

        return ans;
    }
};




/*
Optimised version
TC = 0(n)
SC = 0(1)
*/


class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int left=0, right=0, ans=0;

        // left to right
        for(int i=0; i<n; i++) {
            if(s[i]=='(') left++;
            else right++;

            if(left == right) {
                ans = max(ans, 2*right);
            }
            else if(right > left) {
                left = 0;
                right = 0;
            }
        }

        left = right = 0;

        // right to left
        for(int i=n-1; i>=0; i--) {
            if(s[i]=='(') left++;
            else right++;

            if(left==right) {
                ans = max(ans, 2*left);
            }
            else if(left>right){
                left = 0;
                right = 0;
            }
        }

        return ans;
    }
};