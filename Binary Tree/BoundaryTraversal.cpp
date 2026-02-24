
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to perform boundary traversal of the binary tree
// The boundary traversal includes the left boundary, leaf nodes, and right boundary of the tree.

class Solution {
  public:
  
    bool isleaf(Node* root){
        if(root->left==NULL && root->right==NULL) return true;
        return false;
    }
    void left(Node* root,vector<int> &ans){
        if(root==NULL || isleaf(root)){
            return;
        }
         
        ans.push_back(root->data);
        
        if(root->left)
        left(root->left,ans);
        
        else
        left(root->right,ans);
    }

    void leaf(Node* root,vector<int> &ans){
        if(root==NULL) return;
        if(!root->left && !root->right){
            ans.push_back(root->data);
        }
        leaf(root->left,ans);
        leaf(root->right,ans);
    }
    
    void right(Node* root,vector<int>&ans){
        if(root==NULL || isleaf(root)) return;
        
        if(root->right){
            right(root->right,ans);
        }
        else{
            right(root->left,ans);
        }
       
        ans.push_back(root->data);
        
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        ans.push_back(root->data);
        left(root->left,ans);
        leaf(root->left,ans);
        leaf(root->right,ans);
        right(root->right,ans);
        
        return ans;
        
    }
};