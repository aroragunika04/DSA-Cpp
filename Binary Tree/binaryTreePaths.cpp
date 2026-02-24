#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//257. Binary Tree Paths
class Solution {
public:
    void solve(TreeNode* root,vector<string> &res,string temp){
        if(root==NULL){
            return;
        }
        temp+= to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            res.push_back(temp);
            return;
        }
        //add this only if root is not leaf node
        temp+="->";
        solve(root->left,res,temp);
        solve(root->right,res,temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
         vector<string> res;
         string temp="";
         solve(root,res,temp);
         return res;
    }
};