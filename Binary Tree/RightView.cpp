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
//Right View Of a tree
class Solution {
public:
    //APPROACH 1: RECURSIVE
    //similar to left view
    void solve(TreeNode* root,vector<int> &res,int level){
        if(root==NULL){
            return;
        }
        if(level == res.size()){
            res.push_back(root->val);
        }
        //for right view recurse through right node first nd then left
        solve(root->right,res,level+1);
        solve(root->left,res,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        solve(root,res,0);
        return res;
    }
};

    //APPROACH 2: LEVEL ORDER
    //INSTEAD OF i=0 add if i=size-1 last element of a level
  
class Solution {
public:
   
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        if(root==NULL) return res;

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
                if(i==size-1){
                    res.push_back(front->val);
                }
            }
        }
        return res;
    }
};