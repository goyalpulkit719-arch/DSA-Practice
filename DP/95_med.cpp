#include<bits/stdc++.h>
using namespace std;

/*
Problem: Unique Binary Search Tree 2 (95 medium)
Topics: Binary Tree and DP
TC = Catalian Num * n = 0((4^n)/n^1.5)*n)
*/


/*
  Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> solve(int start, int end) {
        if(start>end) return {NULL};
        if(start==end) {
            TreeNode* root = new TreeNode(start);
            return {root};
        }

        vector<TreeNode*> result;
        for(int i=start; i<=end; i++) {
            vector<TreeNode*> leftPart = solve(start, i-1);
            vector<TreeNode*> rightPart = solve(i+1, end);

            TreeNode* root = new TreeNode(i);
            for(auto &l:leftPart) {
                root->left = l;
                for (auto &r : rightPart) {
                    root->right = r;
                    result.push_back(root);
                }
            }
        }
        return result;
    } 

    vector<TreeNode*> generateTrees(int n) {
        
        return solve(1,n);
    }
};



/*
Memoized Version
*/


class Solution {
public:
    vector<TreeNode*> solve(int start, int end) {
        if(start>end) return {NULL};
        if(start==end) {
            TreeNode* root = new TreeNode(start);
            return {root};
        }

        vector<TreeNode*> result;
        for(int i=start; i<=end; i++) {
            vector<TreeNode*> leftPart = solve(start, i-1);
            vector<TreeNode*> rightPart = solve(i+1, end);

            TreeNode* root = new TreeNode(i);
            for(auto &l:leftPart) {
                root->left = l;
                for (auto &r : rightPart) {
                    root->right = r;
                    result.push_back(root);
                }
            }
        }
        return result;
    } 

    vector<TreeNode*> generateTrees(int n) {
        
        return solve(1,n);
    }
};