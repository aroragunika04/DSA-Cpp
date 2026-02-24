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
 
class Solution {
public:
//872. Leaf-Similar Trees
//APPROACH
//store leave nodes of both tree in vectors nd compare the two vectors
    void solve(TreeNode* root,vector<int> &res){
        if(root == NULL){
            return;
        }
        if(!root->left && !root->right){
            res.push_back(root->val);
            return;
        }
        solve(root->left,res);
        solve(root->right,res);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> temp1;
        vector<int> temp2;
        solve(root1,temp1);
        solve(root2,temp2);
        if(temp1.size()!=temp2.size()){
            return false;
        }
        for(int i=0;i<temp1.size();i++){
            if(temp1[i]!=temp2[i]){
                return false;
            }
        }
        return true;
    }
};