#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//path from root to leaf nodes
//Given a binary tree, find all paths from root to leaf nodes.
class Solution {
  public:
   void solve(Node* root,vector<int>temp,vector<vector<int>> &res){
       if(root==NULL){
           return;
       }
       temp.push_back(root->data);
       if(!root->left && !root->right){
           res.push_back(temp);
           return;
       }
       solve(root->left,temp,res);
       solve(root->right,temp,res);
   }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(root,temp,res);
        return res;
        
    }
};