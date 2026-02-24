#include <iostream>
#include <bits/stdc++.h>

using namespace std;


 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
//687. Longest Univalue Path
//Time Complexity: O(n) where n is the number of nodes in the tree
//Space Complexity: O(h) where h is the height of the tree
//
class Solution {
public:
    int length(TreeNode* root,int &ans){
        if(root==NULL){
            return 0;
        }

        int left = length(root->left,ans);
        int right = length(root->right,ans);
        int leftpath=0,rightpath = 0;
        if(root->left && root->left->val==root->val){
            leftpath =  (1+left);
        }
        if(root->right && root->right->val==root->val){
            rightpath =  (1+right);
        }

         ans = max(ans,leftpath+rightpath);

        return max(leftpath,rightpath);
    }
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        length(root,ans);
        return ans;
            
        
      
    }
};