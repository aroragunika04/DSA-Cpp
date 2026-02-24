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
    int depth(TreeNode* root,bool & res){
        if(root==NULL){
            return 0;
        }
        int left = depth(root->left,res);
        int right = depth(root->right,res);
        if(abs(left-right)>1){
            res = false;
        }
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        bool res = true;
        depth(root,res);
        return res;
    }
};