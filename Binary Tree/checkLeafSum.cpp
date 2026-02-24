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
//112. Path Sum
    bool hasPathSum(TreeNode* root, int targetSum) {
        //U CAN USE SUM BUT THEN WE HAVE TO PASS SUM ALSO
        //int sum = 0;
        if(root==NULL){
            return false;
        }
        
        //sum += root->val;
        if(root->left==NULL && root->right==NULL){
            return root->val == targetSum;
        }
        
        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);
    }
};

//approach2: using sum in helper function
class Solution2 {   
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, targetSum, 0);
    }
    
    bool helper(TreeNode* root, int targetSum, int sum) {
        if (root == NULL) {
            return false;
        }
        
        sum += root->val;
        
        if (root->left == NULL && root->right == NULL) {
            return sum == targetSum;
        }
        
        return helper(root->left, targetSum, sum) || helper(root->right, targetSum, sum);
    }
};