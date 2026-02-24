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
    //PREORDER
    vector<int> res;
    void preorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        res.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return res;
    }
    
    //INORDER
    void solve(TreeNode* root,vector<int> &res){
        if(root==NULL){
            return;
        }
        solve(root->left,res);
        res.push_back(root->val);
        solve(root->right,res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        solve(root,res);
        return res;
    }
};

 