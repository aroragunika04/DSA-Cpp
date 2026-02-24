#include<bits/stdc++.h>
using namespace std;

//230. Kth Smallest Element in a BST
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
    //sort the tree and store in a vector
    //inorder gives sorted val in BST
    void inOrder(TreeNode* root,vector<int>& res){
        if(root==NULL){
            return;
        }
        inOrder(root->left,res);
        res.push_back(root->val);
        inOrder(root->right,res);
    }
    //return the k-1 kth smallest el from vector
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        inOrder(root,res);
        return res[k-1];
    }
};

//APPROACH 2: RECURSIVE IN BST
class Solution {
public:
    void solve(TreeNode* root,int &k,int &ans){
        if(root==NULL){
            return;
        }
        solve(root->left,k,ans);
        k--;
        if(k==0){
            ans = root->val;
            return;
        }
        solve(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        solve(root,k,ans);
        return ans;

    }
};