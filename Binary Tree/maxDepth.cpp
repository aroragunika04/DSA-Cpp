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
//APPROACH1: RECURSIVE
//count depth for left child and right child till their last and return 1+max(leftDepth,rightDepth)
//added 1 to include depth of root to first left or right child
    int maxDepth(TreeNode* root) {
        //Base case: If the node is NULL, depth is 0 (empty tree)
        if(root==NULL){
            return 0;
        }
        // if(root->left==NULL && root->right==NULL){
        //     return 1;
        // }
        //for edges do -1
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};

//APPROACH2:  USING LEVEL ORDER TRAVERSAL

//Count all the nodes
   int getSize(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return 1+getSize(root->left)+getSize(root->right);
        
    }
//COUNT ALL LEAF NODES
class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(TreeNode* root) {
       if(root==NULL){
           return 0;
       }
       if(root->left==NULL && root->right==NULL){
           return 1;
       }
       return countLeaves(root->left)+countLeaves(root->right);
        
    }
};
//COUNT NON LEAF NODES
class Solution {
  public:
    int countNonLeafNodes(TreeNode* root) {
        // Code here
        if(root==NULL){
            return 0;
        }
        if(!root->left && !root->right){
            return 0;
        }
        return 1+countNonLeafNodes(root->left)+countNonLeafNodes(root->right);
        }
};

//SUM OF ALL NODES
class Solution {
  public:
    int sumBT(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return root->val+sumBT(root->left)+sumBT(root->right);
        
    }
};
//APPROACH 2: UING LEVEL ORDER TRAVERSAL
class Solution {
  public:
    int sumBT(TreeNode* root) {
       // vector<int> level;
        queue<TreeNode*> q;
        int sum=0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                sum+=node->val;
            }
        }
        return sum;
        
    }
};